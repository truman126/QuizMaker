/// @file   WindowEditQuestion.cpp
/// @author Kenneth McAlinden
/// @author Jason Chan
/// @date   30 November 2021
/// @brief  WindowEditQuestion class used to edit questions



#include "WindowEditQuestion.h"
#include "WindowEditQuiz.h"



using namespace std;



/// @brief   Constructor.
/// @details WindowEditQuestion Constructor that initializes the view with parameter values
/// @param   *quiz: first Quiz pointer
/// @param   *quizTemp: second Quiz pointer
/// @param   *quizTempTemp: third Quiz pointer
/// @param   *question: Question pointer
/// @param   *parent: QWidget pointer
WindowEditQuestion::WindowEditQuestion(Quiz *quiz, Quiz *quizTemp, Quiz *quizTempTemp, Question *question, QWidget *parent) : QMainWindow(parent) {
	this -> setFixedSize(960, 624);
	this -> setWindowTitle("Quiz Maker: Edit Question");

	this -> quiz         = quiz;
	this -> quizTemp     = quizTemp;
	this -> quizTempTemp = quizTempTemp;
	this -> question     = question;

	questionTemp        = question;
	questionAnswersTemp = question -> getQuestionAnswers();

	// Sort question answers so that they are shown in table sorted by letter (descending).
	sort(questionAnswersTemp.begin(), questionAnswersTemp.end(), compareAnswers);

	// label_Number
	label_Number = new QLabel("Number", this);
	label_Number -> setGeometry(QRect(QPoint(16, 24), QSize(80, 16)));

	// lineEdit_Number
	lineEdit_Number = new QLineEdit(this);
	lineEdit_Number -> setGeometry(QRect(QPoint(96, 16), QSize(368, 32)));
	lineEdit_Number -> setMaxLength(3);
	// lineEdit_Number: Trim trailing zeroes.
	if (question -> getQuestionNumber() != 0) {
		string questionNumber = to_string(question -> getQuestionNumber());

		questionNumber.erase(questionNumber.find_last_not_of("0") + 1, string::npos);

		if (questionNumber.back() == '.') questionNumber.pop_back();

		lineEdit_Number -> setText(QString::fromStdString(questionNumber));
	}

	// label_Title
	label_Title = new QLabel("Title", this);
	label_Title -> setGeometry(QRect(QPoint(16, 72), QSize(80, 16)));

	// lineEdit_Title
	lineEdit_Title = new QLineEdit(this);
	lineEdit_Title -> setGeometry(QRect(QPoint(96, 64), QSize(368, 32)));
	lineEdit_Title -> setText(QString::fromStdString(question -> getQuestionTitle()));

	// checkBox_SettingRandomAnswer
	checkBox_SettingRandomAnswer = new QCheckBox("Random answer order", this);
	checkBox_SettingRandomAnswer -> setGeometry(QRect(QPoint(16, 112), QSize(448, 32)));
	if (this -> question -> getQuestionSettingRandomAnswer() == true) checkBox_SettingRandomAnswer -> setChecked(true);

	// plainTextEdit_Description
	plainTextEdit_Description = new QPlainTextEdit(this);
	plainTextEdit_Description -> setPlaceholderText("enter question description...");
	plainTextEdit_Description -> setGeometry(QRect(QPoint(496, 16), QSize(448, 128)));
	plainTextEdit_Description -> setPlainText(QString::fromStdString(question -> getQuestionDescription()));

	// pushButton_AddAnswer
	pushButton_AddAnswer = new QPushButton("Add", this);
	pushButton_AddAnswer -> setGeometry(QRect(QPoint(16, 176), QSize(298.6664, 32)));
	connect(pushButton_AddAnswer, &QPushButton::released, this, &WindowEditQuestion::addAnswer);

	// pushButton_DeleteAnswer
	pushButton_DeleteAnswer = new QPushButton("Delete", this);
	pushButton_DeleteAnswer -> setGeometry(QRect(QPoint(330.6668, 176), QSize(298.6664, 32)));
	pushButton_DeleteAnswer -> setDisabled(true);
	connect(pushButton_DeleteAnswer, &QPushButton::released, this, &WindowEditQuestion::deleteAnswer);

	// pushButton_EditAnswer
	pushButton_EditAnswer = new QPushButton("Edit", this);
	pushButton_EditAnswer -> setGeometry(QRect(QPoint(645.3336, 176), QSize(298.6664, 32)));
	pushButton_EditAnswer -> setDisabled(true);
	connect(pushButton_EditAnswer, &QPushButton::released, this, &WindowEditQuestion::editAnswer);

	// tableWidget_Answers
	tableWidget_Answers = new QTableWidget(0, 8, this);
	tableWidget_Answers -> setGeometry(QRect(QPoint(16, 224), QSize(928, 320)));

	float questionPointsTotal   = 0;
	float questionPointsCorrect = 0;

	// Get total and correct points
	for (int i = 0; i < questionAnswersTemp.size(); i++) {
		questionPointsTotal += questionAnswersTemp[i].getAnswerPoints();

		if (questionAnswersTemp[i].getAnswerInput() == questionAnswersTemp[i].getAnswerCorrect()) questionPointsCorrect += questionAnswersTemp[i].getAnswerPoints();
	}

	// Set Values
	this -> question -> setQuestionPointsCorrect(questionPointsTotal);
	this -> question -> setQuestionPointsCorrect(questionPointsCorrect);

	questionPoints = to_string((int)questionPointsCorrect) + " / " + to_string((int)questionPointsTotal);

	if (questionPoints == "0 / 0") questionPoints = "Points";

	QStringList headers = {"S", "L", "Text", "T", "Input", "Correct", "Feedback"};

	headers << QString::fromStdString(questionPoints);

	tableWidget_Answers -> setHorizontalHeaderLabels(headers);
	tableWidget_Answers -> setAlternatingRowColors(true);
	tableWidget_Answers -> setColumnWidth(0,   1); ///< Column Width: S
	tableWidget_Answers -> setColumnWidth(1,   1); ///< Column Width: L
	tableWidget_Answers -> setColumnWidth(2, 276); ///< Column Width: Text
	tableWidget_Answers -> setColumnWidth(3,  30); ///< Column Width: T
	tableWidget_Answers -> setColumnWidth(4, 108); ///< Column Width: Input
	tableWidget_Answers -> setColumnWidth(5, 108); ///< Column Width: Correct
	tableWidget_Answers -> setColumnWidth(6, 276); ///< Column Width: Feedback
	tableWidget_Answers -> setColumnWidth(7,  70); ///< Column Width: Points
	tableWidget_Answers -> horizontalHeader() -> setSectionResizeMode(QHeaderView::Fixed); ///< Disable resizing column widths
	tableWidget_Answers -> verticalHeader() -> setVisible(false); ///< Hide row count column
	tableWidget_Answers -> verticalHeader() -> setDefaultSectionSize(50); ///< Set row height
	tableWidget_Answers -> setSelectionBehavior(QAbstractItemView::SelectRows); ///< Set entire row to be selected when selected
	tableWidget_Answers -> setSelectionMode(QAbstractItemView::SingleSelection); ///< Limit selection to a single row
	tableWidget_Answers -> setEditTriggers(QAbstractItemView::NoEditTriggers); ///< Set read only
	connect(tableWidget_Answers, &QTableWidget::itemSelectionChanged, this, &WindowEditQuestion::selectionChanged);

	// Populate tableWidget_Answers
	for (int i = 0; i < questionAnswersTemp.size(); i++) {
		tableWidget_Answers -> setRowCount(tableWidget_Answers -> rowCount() + 1);

		string answerStatus = "○";

		// Update answerStatus if completed
		if (questionAnswersTemp[i].getAnswerStatus() == 1) answerStatus = "●";

		tableWidget_Answers -> setItem(i, 0, new QTableWidgetItem(QString::fromStdString(answerStatus)));

		string s;

		s.append(1, questionAnswersTemp[i].getAnswerLetter());

		tableWidget_Answers -> setItem(i, 1, new QTableWidgetItem(QString::fromStdString(s)));
		tableWidget_Answers -> setItem(i, 2, new QTableWidgetItem(QString::fromStdString(questionAnswersTemp[i].getAnswerText())));

		// Update tableWidget_Answers with type of answer type
		if (questionAnswersTemp[i].getAnswerType() == 0) tableWidget_Answers -> setItem(i, 3, new QTableWidgetItem("TF"));
		if (questionAnswersTemp[i].getAnswerType() == 1) tableWidget_Answers -> setItem(i, 3, new QTableWidgetItem("MC"));
		if (questionAnswersTemp[i].getAnswerType() == 2) tableWidget_Answers -> setItem(i, 3, new QTableWidgetItem("WA"));

		tableWidget_Answers -> setItem(i, 4, new QTableWidgetItem(QString::fromStdString(questionAnswersTemp[i].getAnswerInput())));
		tableWidget_Answers -> setItem(i, 5, new QTableWidgetItem(QString::fromStdString(questionAnswersTemp[i].getAnswerCorrect())));
		tableWidget_Answers -> setItem(i, 6, new QTableWidgetItem(QString::fromStdString(questionAnswersTemp[i].getAnswerFeedback())));

		if (questionAnswersTemp[i].getAnswerInput() == questionAnswersTemp[i].getAnswerCorrect()) tableWidget_Answers -> setItem(i, 7, new QTableWidgetItem(QString::number(questionAnswersTemp[i].getAnswerPoints()) + " / " + QString::number(questionAnswersTemp[i].getAnswerPoints())));
		else                                                                                      tableWidget_Answers -> setItem(i, 7, new QTableWidgetItem("0 / " + QString::number(questionAnswersTemp[i].getAnswerPoints())));
	}

	// pushButton_Cancel
	pushButton_Cancel = new QPushButton("Cancel", this);
	pushButton_Cancel -> setGeometry(QRect(QPoint(16, 576), QSize(448, 32)));
	connect(pushButton_Cancel, &QPushButton::released, this, &WindowEditQuestion::cancel);

	// pushButton_Ok
	pushButton_Ok = new QPushButton("Ok", this);
	pushButton_Ok -> setGeometry(QRect(QPoint(496, 576), QSize(448, 32)));
	connect(pushButton_Ok, &QPushButton::released, this, &WindowEditQuestion::ok);
}



/// @brief   Destructor.
/// @details Desconstructor for WindowEditQuestion Widget
WindowEditQuestion::~WindowEditQuestion() {};



/// @brief  Method to Add Answer
/// @details Add a new answer and present the WindowEditAnswer widget
void WindowEditQuestion::addAnswer() {

	if (lineEdit_Number -> text().isEmpty()) {
		messageBox.critical(0, "Error", "Enter a number for the question!");

		lineEdit_Number -> setFocus();
	} else if (lineEdit_Number -> text().toFloat() <= 0) {
		messageBox.critical(0, "Error", "Number must be positive and not 0!");

		lineEdit_Number -> setText("");
		lineEdit_Number -> setFocus();
	} else {
		// Make a copy of Quiz's Question vector.
		quizQuestions = quizTempTemp -> getQuizQuestions();

		for (int i = 0; i < quizQuestions.size(); i++) {

			// Check if number entered already exists for a question in this quiz.
			if ((lineEdit_Number -> text().toFloat() == quizQuestions[i].getQuestionNumber()) && (lineEdit_Number -> text().toFloat() != questionTemp -> getQuestionNumber())) {
				messageBox.critical(0, "Error", "A question with this number already exists for this quiz!");

				// Update view with question number
				if (questionTemp -> getQuestionNumber() == 0) lineEdit_Number -> setText("");
				else                                          lineEdit_Number -> setText(QString::number(questionTemp -> getQuestionNumber()));

				lineEdit_Number -> setFocus();

				return;
			}
		}

		// Remove old Question from Quiz's Question vector.
		for (int i = 0; i < quizQuestions.size(); i++) {
			if ((quizQuestions[i].getQuestionNumber() != 0) && (quizQuestions[i].getQuestionNumber() == questionTemp -> getQuestionNumber())) {
				quizQuestions.erase(quizQuestions.begin() + i);
			}
		}

		// Set data for Question.
		questionTemp -> setQuestionNumber(lineEdit_Number -> text().toFloat());
		questionTemp -> setQuestionTitle(lineEdit_Title -> text().toStdString());
		questionTemp -> setQuestionSettingRandomAnswer(checkBox_SettingRandomAnswer -> isChecked());
		questionTemp -> setQuestionDescription(plainTextEdit_Description -> toPlainText().toStdString());
		questionTemp -> setQuestionAnswers(question -> getQuestionAnswers());

		questionAnswersTemp = questionTemp -> getQuestionAnswers();

		sort(questionAnswersTemp.begin(), questionAnswersTemp.end(), compareAnswers);

		float questionPointsTotal   = 0;
		float questionPointsCorrect = 0;
		int   answersAnswered       = 0;

		// Calculate total points and total correct points
		for (int i = 0; i < questionAnswersTemp.size(); i++) {
			questionPointsTotal += questionAnswersTemp[i].getAnswerPoints();

			if (questionAnswersTemp[i].getAnswerInput() == questionAnswersTemp[i].getAnswerCorrect()) questionPointsCorrect += questionAnswersTemp[i].getAnswerPoints();
			if (questionAnswersTemp[i].getAnswerStatus() == 1)                                        answersAnswered += 1;
		}

		// Set total correct points and total points
		if (questionAnswersTemp.size() > 0) {
			questionTemp -> setQuestionPointsTotal(questionPointsTotal);
			questionTemp -> setQuestionPointsCorrect(questionPointsCorrect);
		}
		else {
			questionTemp -> setQuestionPointsTotal(0);
			questionTemp -> setQuestionPointsCorrect(0);
		}

		// Set question status depending on answersAnswered
		if (answersAnswered == 0)                          questionTemp -> setQuestionStatus(0);
		if (answersAnswered >= 1)                          questionTemp -> setQuestionStatus(1);
		if (answersAnswered == questionAnswersTemp.size()) questionTemp -> setQuestionStatus(2);

		// Add Question to temporary Quiz Question vector.
		quizQuestions.push_back(*questionTemp);

		// Set Quiz's Question vector to temporary Quiz Question vector.
		quizTempTemp -> setQuizQuestions(quizQuestions);

		Quiz *quizTempTempTemp = new Quiz();

		*quizTempTempTemp = *quizTempTemp;

		Answer *answer = new Answer();

		// Switch window.
		windowEditAnswer = new WindowEditAnswer(quiz, quizTemp, quizTempTemp, quizTempTempTemp, question, questionTemp, answer);

		connect(windowEditAnswer, &WindowEditAnswer::switchWindow, this, &WindowEditAnswer::show);

		this            -> close();
		windowEditAnswer -> show();
	}
}



/// @brief  Method to Delete Answer
/// @details Delete an answer
void WindowEditQuestion::deleteAnswer() {
	// Get Answers
	questionAnswersTemp = question -> getQuestionAnswers();

	// Sort Answers
	sort(questionAnswersTemp.begin(), questionAnswersTemp.end(), compareAnswers);

	// Delete Answer
	questionAnswersTemp.erase(questionAnswersTemp.begin() + (tableWidget_Answers -> currentRow()));

	float questionPointsTotal   = 0;
	float questionPointsCorrect = 0;
	int   answersAnswered       = 0;

	// Calculate total points and total correct points
	for (int i = 0; i < questionAnswersTemp.size(); i++) {
		questionPointsTotal += questionAnswersTemp[i].getAnswerPoints();

		if (questionAnswersTemp[i].getAnswerInput() == questionAnswersTemp[i].getAnswerCorrect()) questionPointsCorrect += questionAnswersTemp[i].getAnswerPoints();
		if (questionAnswersTemp[i].getAnswerStatus() == 1)                                        answersAnswered       += 1;
	}

	// Set total correct points and total points
	question -> setQuestionPointsTotal(questionPointsTotal);
	question -> setQuestionPointsCorrect(questionPointsCorrect);

	// Set question status depending on answersAnswered
	if (answersAnswered == 0)                          questionTemp -> setQuestionStatus(0);
	if (answersAnswered >= 1)                          questionTemp -> setQuestionStatus(1);
	if (answersAnswered == questionAnswersTemp.size()) questionTemp -> setQuestionStatus(2);

	// Points
	questionPoints = to_string((int)questionPointsCorrect) + " / " + to_string((int)questionPointsTotal);

	if (questionPoints == "0 / 0") questionPoints = "Points";

	QStringList headers = {"S", "L", "Text", "T", "Input", "Correct", "Feedback"};

	headers << QString::fromStdString(questionPoints);

	// Set tableWidget_Answers headers
	tableWidget_Answers -> setHorizontalHeaderLabels(headers);

	// Set question answers
	question -> setQuestionAnswers(questionAnswersTemp);

	tableWidget_Answers -> setRowCount(0);

	for (int i = 0; i < questionAnswersTemp.size(); i++) {
		tableWidget_Answers -> setRowCount(tableWidget_Answers -> rowCount() + 1);

		string answerStatus = "○";

		// If question answered update status
		if (questionAnswersTemp[i].getAnswerStatus() == 1) answerStatus = "●";

		tableWidget_Answers -> setItem(i, 0, new QTableWidgetItem(QString::fromStdString(answerStatus)));

		string s;

		s.append(1, questionAnswersTemp[i].getAnswerLetter());

		// Set tableWidget_Answers item
		tableWidget_Answers -> setItem(i, 1, new QTableWidgetItem(QString::fromStdString(s)));
		tableWidget_Answers -> setItem(i, 2, new QTableWidgetItem(QString::fromStdString(questionAnswersTemp[i].getAnswerText())));

		// Set widget item for answer data
		if (questionAnswersTemp[i].getAnswerType() == 0) tableWidget_Answers -> setItem(i, 3, new QTableWidgetItem("TF"));
		if (questionAnswersTemp[i].getAnswerType() == 1) tableWidget_Answers -> setItem(i, 3, new QTableWidgetItem("MC"));
		if (questionAnswersTemp[i].getAnswerType() == 2) tableWidget_Answers -> setItem(i, 3, new QTableWidgetItem("WA"));

		tableWidget_Answers -> setItem(i, 4, new QTableWidgetItem(QString::fromStdString(questionAnswersTemp[i].getAnswerInput())));
		tableWidget_Answers -> setItem(i, 5, new QTableWidgetItem(QString::fromStdString(questionAnswersTemp[i].getAnswerCorrect())));
		tableWidget_Answers -> setItem(i, 6, new QTableWidgetItem(QString::fromStdString(questionAnswersTemp[i].getAnswerFeedback())));

		if (questionAnswersTemp[i].getAnswerInput() == questionAnswersTemp[i].getAnswerCorrect()) tableWidget_Answers -> setItem(i, 7, new QTableWidgetItem(QString::number(questionAnswersTemp[i].getAnswerPoints()) + " / " + QString::number(questionAnswersTemp[i].getAnswerPoints())));
		else                                                                              tableWidget_Answers -> setItem(i, 7, new QTableWidgetItem("0 / " + QString::number(questionAnswersTemp[i].getAnswerPoints())));
	}
}



/// @brief  Method to Edit Answer
/// @details Edit an answer
void WindowEditQuestion::editAnswer() {
	if      (lineEdit_Number -> text().isEmpty()) {
		messageBox.critical(0, "Error", "Enter a number for the question!");

		lineEdit_Number -> setFocus();
	}

	else if (lineEdit_Number -> text().toFloat() <= 0) {
		messageBox.critical(0, "Error", "Number must be positive and not 0!");

		lineEdit_Number -> setText("");
		lineEdit_Number -> setFocus();
	}

	else {
		// Make a copy of Quiz's Question vector.
		quizQuestions = quizTempTemp -> getQuizQuestions();

		// Check if number entered already exists for a question in this quiz.
		for (int i = 0; i < quizQuestions.size(); i++) {
			if ((lineEdit_Number -> text().toFloat() == quizQuestions[i].getQuestionNumber()) && (lineEdit_Number -> text().toFloat() != questionTemp -> getQuestionNumber())) {
				messageBox.critical(0, "Error", "A question with this number already exists for this quiz!");

				// Set question number
				if (questionTemp -> getQuestionNumber() == 0) lineEdit_Number -> setText("");
				else                                          lineEdit_Number -> setText(QString::number(questionTemp -> getQuestionNumber()));

				lineEdit_Number -> setFocus();

				return;
			}
		}

		// Remove old Question from Quiz's Question vector.
		for (int i = 0; i < quizQuestions.size(); i++) {
			if ((quizQuestions[i].getQuestionNumber() != 0) && (quizQuestions[i].getQuestionNumber() == questionTemp -> getQuestionNumber())) {
				quizQuestions.erase(quizQuestions.begin() + i);
			}
		}

		// Set data for Question.
		questionTemp -> setQuestionNumber(lineEdit_Number -> text().toFloat());
		questionTemp -> setQuestionTitle(lineEdit_Title -> text().toStdString());
		questionTemp -> setQuestionSettingRandomAnswer(checkBox_SettingRandomAnswer -> isChecked());
		questionTemp -> setQuestionDescription(plainTextEdit_Description -> toPlainText().toStdString());

		// update questionAnswersTemp with updated answers
		questionAnswersTemp = questionTemp -> getQuestionAnswers();

		sort(questionAnswersTemp.begin(), questionAnswersTemp.end(), compareAnswers);

		float questionPointsTotal   = 0;
		float questionPointsCorrect = 0;
		int   answersAnswered       = 0;

		// Calculate total points and total correct points
		for (int i = 0; i < questionAnswersTemp.size(); i++) {
			questionPointsTotal += questionAnswersTemp[i].getAnswerPoints();

			if (questionAnswersTemp[i].getAnswerInput() == questionAnswersTemp[i].getAnswerCorrect()) questionPointsCorrect += questionAnswersTemp[i].getAnswerPoints();
			if (questionAnswersTemp[i].getAnswerStatus() == 1)                                        answersAnswered       += 1;
		}

		// Set question points
		if (questionAnswersTemp.size() > 0) {
			questionTemp -> setQuestionPointsTotal(questionPointsTotal);
			questionTemp -> setQuestionPointsCorrect(questionPointsCorrect);
		}
		else {
			questionTemp -> setQuestionPointsTotal(0);
			questionTemp -> setQuestionPointsCorrect(0);
		}

		// Set questionStatus based on answersAnswered
		if (answersAnswered == 0)                          questionTemp -> setQuestionStatus(0);
		if (answersAnswered >= 1)                          questionTemp -> setQuestionStatus(1);
		if (answersAnswered == questionAnswersTemp.size()) questionTemp -> setQuestionStatus(2);

		// Add Question to temporary Quiz Question vector.
		quizQuestions.push_back(*questionTemp);

		// Set Quiz's Question vector to temporary Quiz Question vector.
		quizTempTemp -> setQuizQuestions(quizQuestions);

		Quiz *quizTempTempTemp = new Quiz();

		*quizTempTempTemp = *quizTempTemp;

		// Switch window.
		windowEditAnswer = new WindowEditAnswer(quiz, quizTemp, quizTempTemp, quizTempTempTemp, question, questionTemp, &questionAnswersTemp[tableWidget_Answers -> currentRow()]);

		connect(windowEditAnswer, &WindowEditAnswer::switchWindow, this, &WindowEditAnswer::show);

		this             -> close();
		windowEditAnswer -> show();
	}
}



/// @brief  Method to Cancel
/// @details Cancel and present WindowEditQuiz window
void WindowEditQuestion::cancel() {
	// Switch window.
	windowEditQuiz = new WindowEditQuiz(quiz, quizTemp);

	connect(windowEditQuiz, &WindowEditQuiz::switchWindow, this, &WindowEditQuiz::show);

	this           -> close();
	windowEditQuiz -> show();
}



/// @brief  Method to Ok
/// @details Ok Method to save Question changes and present WindowEditQuiz window
void WindowEditQuestion::ok() {
	if (lineEdit_Number -> text().isEmpty()) {
		messageBox.critical(0, "Error", "Enter a number for the question!");

		lineEdit_Number -> setFocus();
	}

	else if (lineEdit_Number -> text().toFloat() <= 0) {
		messageBox.critical(0, "Error", "Number must be positive and not 0!");

		lineEdit_Number -> setText("");
		lineEdit_Number -> setFocus();
	}

	else {
		// Make a copy of Quiz's Question vector.
		quizQuestions = quizTempTemp -> getQuizQuestions();

		// Check if number entered already exists for a question in this quiz.
		for (int i = 0; i < quizQuestions.size(); i++) {
			if ((lineEdit_Number -> text().toFloat() == quizQuestions[i].getQuestionNumber()) && (lineEdit_Number -> text().toFloat() != questionTemp -> getQuestionNumber())) {
				messageBox.critical(0, "Error", "A question with this number already exists for this quiz!");

				if (questionTemp -> getQuestionNumber() == 0) lineEdit_Number -> setText("");
				else                                          lineEdit_Number -> setText(QString::number(questionTemp -> getQuestionNumber()));

				lineEdit_Number -> setFocus();

				return;
			}
		}

		// Remove old Question from Quiz's Question vector.
		for (int i = 0; i < quizQuestions.size(); i++) {
			if ((quizQuestions[i].getQuestionNumber() != 0) && (quizQuestions[i].getQuestionNumber() == questionTemp -> getQuestionNumber())) {
				quizQuestions.erase(quizQuestions.begin() + i);
			}
		}

		// Set data for Question.
		question -> setQuestionNumber(lineEdit_Number -> text().toFloat());
		question -> setQuestionTitle(lineEdit_Title -> text().toStdString());
		question -> setQuestionSettingRandomAnswer(checkBox_SettingRandomAnswer -> isChecked());
		question -> setQuestionDescription(plainTextEdit_Description -> toPlainText().toStdString());

		questionAnswersTemp = questionTemp -> getQuestionAnswers();

		sort(questionAnswersTemp.begin(), questionAnswersTemp.end(), compareAnswers);

		float questionPointsTotal   = 0;
		float questionPointsCorrect = 0;
		int   answersAnswered       = 0;

		// Calculate total points and total correct points
		for (int i = 0; i < questionAnswersTemp.size(); i++) {
			questionPointsTotal += questionAnswersTemp[i].getAnswerPoints();
			if (questionAnswersTemp[i].getAnswerInput() == questionAnswersTemp[i].getAnswerCorrect()) questionPointsCorrect += questionAnswersTemp[i].getAnswerPoints();
			if (questionAnswersTemp[i].getAnswerStatus() == 1)                                        answersAnswered       += 1;
		}

		// Set total correct points and total points
		if (questionAnswersTemp.size() > 0) {
			question -> setQuestionPointsTotal(questionPointsTotal);
			question -> setQuestionPointsCorrect(questionPointsCorrect);
		}
		else {
			question -> setQuestionPointsTotal(0);
			question -> setQuestionPointsCorrect(0);
		}

		// Set questionStatus based on answersAnswered
		if (answersAnswered == 0)                          questionTemp -> setQuestionStatus(0);
		if (answersAnswered >= 1)                          questionTemp -> setQuestionStatus(1);
		if (answersAnswered == questionAnswersTemp.size()) questionTemp -> setQuestionStatus(2);

		question -> setQuestionAnswers(questionAnswersTemp);

		// Add Question to temporary Quiz Question vector.
		quizQuestions.push_back(*question);

		// Set Quiz's Question vector to temporary Quiz Question vector.
		quizTempTemp -> setQuizQuestions(quizQuestions);

		// Switch window.
		windowEditQuiz = new WindowEditQuiz(quiz, quizTempTemp);

		connect(windowEditQuiz, &WindowEditQuiz::switchWindow, this, &WindowEditQuiz::show);

		this           -> close();
		windowEditQuiz -> show();
	}
}



/// @brief Method triggered when selection changed
/// @details Method triggered when selection of a answer is changed
void WindowEditQuestion::selectionChanged() {
	if (tableWidget_Answers -> selectedItems().isEmpty() == false) {
		pushButton_EditAnswer   -> setDisabled(false);
		pushButton_DeleteAnswer -> setDisabled(false);
	}
	else {
		pushButton_EditAnswer   -> setDisabled(true);
		pushButton_DeleteAnswer -> setDisabled(true);
	}
}



/// @brief  Method to compare Answers
/// @details Method to compare Answer's letters
/// @param  answer1: Answer to compare
/// @param  answer2: Answer to compare with
/// @return bool for whether answer1 answerLetter is less than answer2
bool WindowEditQuestion::compareAnswers(Answer answer1, Answer answer2) {
	return (answer1.getAnswerLetter() < answer2.getAnswerLetter());
}
