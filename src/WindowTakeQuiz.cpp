/// @file   WindowTakeQuiz.cpp
/// @author Kenneth McAlinden
/// @author Roy Zhu
/// @date   30 November 2021
/// @brief  WindowTakeQuiz class used to Take Quizzes



#include "WindowTakeQuiz.h"
#include "WindowQuiz.h"



/// @brief Constructor.
/// @details WindowTakeQuiz Constructor
/// @param *parent: QWidget pointer which points to the main window
WindowTakeQuiz::WindowTakeQuiz(Quiz *quiz, Quiz *quizTemp, QWidget *parent) : QMainWindow(parent) {
	this -> setFixedSize(960, 624);
	this -> setWindowTitle("Quiz Maker: Taking Quiz");

	this -> quiz            = quiz;
	this -> quizTemp        = quizTemp;
	this -> quizQuestions   = quizTemp -> getQuizQuestions();
	this -> questionIndex   = 0;
	this -> question        = quizQuestions[questionIndex];
	this -> questionAnswers = question.getQuestionAnswers();
	this -> quizTimeLimit   = quizTemp -> getQuizTimeLimit();

	// Start timer if quiz has a time limit.
	if ((quizTemp -> getQuizStatus() == 0) && (quizTemp -> getQuizTimeLimit() != "00:00:00")) {
		QTimer *timer_TimeUsed = new QTimer(this);

		connect(timer_TimeUsed, SIGNAL(timeout()), this, SLOT(updateLineEdit_TimeUsed()));

		timer_TimeUsed -> start(1000);
	}

	// lineEdit_Number
	lineEdit_Number = new QLineEdit(this);
	lineEdit_Number -> setGeometry(QRect(QPoint(16, 16), QSize(56, 32)));
	lineEdit_Number -> setReadOnly(true);
	lineEdit_Number -> setStyleSheet("font-weight: bold; color: rgb(223, 223, 223); background-color: rgb(14, 28, 84);");
	lineEdit_Number -> setAlignment(Qt::AlignCenter);

	// lineEdit_Title
	lineEdit_Title = new QLineEdit(this);
	lineEdit_Title -> setGeometry(QRect(QPoint(88, 16), QSize(440, 32)));
	lineEdit_Title -> setReadOnly(true);
	lineEdit_Title -> setStyleSheet("font-weight: bold; color: rgb(223, 223, 223); background-color: rgb(14, 28, 84);");
	lineEdit_Title -> setAlignment(Qt::AlignCenter);

	// plainTextEdit_Description
	plainTextEdit_Description = new QPlainTextEdit(this);
	plainTextEdit_Description -> setGeometry(QRect(QPoint(16, 64), QSize(512, 80)));
	plainTextEdit_Description -> setReadOnly(true);
	plainTextEdit_Description -> setStyleSheet("color: rgb(223, 223, 223); background-color: rgb(14, 28, 84);");

	// label_TimeLimit
	label_TimeLimit = new QLabel("Time", this);
	label_TimeLimit -> setGeometry(QRect(QPoint(560, 24), QSize(72, 16)));
	label_TimeLimit -> setStyleSheet("color: rgb(128, 255, 207); font-weight: bold;");

	// lineEdit_TimeLimit
	lineEdit_TimeLimit = new QLineEdit(this);
	lineEdit_TimeLimit -> setGeometry(QRect(QPoint(632, 16), QSize(120, 32)));
	lineEdit_TimeLimit -> setReadOnly(true);
	lineEdit_TimeLimit -> setStyleSheet("color: rgb(223, 223, 223); background-color: rgb(14, 28, 84);");
	lineEdit_TimeLimit -> setAlignment(Qt::AlignCenter);
	if (quizTemp -> getQuizTimeLimit() == "00:00:00") lineEdit_TimeLimit -> setText("N/A");
	else                                              lineEdit_TimeLimit -> setText(QString::fromStdString(quizTemp -> getQuizTimeLimit()));

	// label_TimeUsed
	label_TimeUsed = new QLabel("Used", this);
	label_TimeUsed -> setGeometry(QRect(QPoint(560, 72), QSize(72, 16)));
	label_TimeUsed -> setStyleSheet("color: rgb(128, 255, 207); font-weight: bold;");

	// lineEdit_TimeUsed
	lineEdit_TimeUsed = new QLineEdit(this);
	lineEdit_TimeUsed -> setGeometry(QRect(QPoint(632, 64), QSize(120, 32)));
	lineEdit_TimeUsed -> setReadOnly(true);
	lineEdit_TimeUsed -> setStyleSheet("color: rgb(223, 223, 223); background-color: rgb(14, 28, 84);");
	lineEdit_TimeUsed -> setAlignment(Qt::AlignCenter);
	if (quizTemp -> getQuizTimeLimit() == "00:00:00") lineEdit_TimeUsed -> setText("N/A");
	else                                              lineEdit_TimeUsed -> setText(QString::fromStdString(quizTemp -> getQuizTimeUsed()));

	// label_Points
	label_Points = new QLabel("Points", this);
	label_Points -> setGeometry(QRect(QPoint(560, 120), QSize(72, 16)));
	label_Points -> setStyleSheet("color: rgb(128, 223, 255); font-weight: bold;");

	// lineEdit_Points
	lineEdit_Points = new QLineEdit(this);
	lineEdit_Points -> setGeometry(QRect(QPoint(632, 112), QSize(120, 32)));
	lineEdit_Points -> setReadOnly(true);
	lineEdit_Points -> setStyleSheet("color: rgb(223, 223, 223); background-color: rgb(14, 28, 84);");
	lineEdit_Points -> setAlignment(Qt::AlignCenter);

	// listWidget_QWidget_Answers
	listWidget_QWidget_Answers = new QListWidget(this);
	listWidget_QWidget_Answers -> setGeometry(QRect(QPoint(16, 168), QSize(736, 376)));
	listWidget_QWidget_Answers -> setSelectionMode(QAbstractItemView::NoSelection);

	// tableWidget_Questions
	tableWidget_Questions = new QTableWidget(0, 3, this);
	if (quizTemp -> getQuizSettingJump() == true) tableWidget_Questions -> setGeometry(QRect(QPoint(792, 16), QSize(152, 480)));
	else                                          tableWidget_Questions -> setGeometry(QRect(QPoint(792, 16), QSize(152, 528)));

	QStringList headers = {"S", "#"};

	if ((quizTemp -> getQuizStatus() >= 1) || (quizTemp -> getQuizSettingPointsQuestion() == true)) headers << QString::fromStdString(to_string((int)quizTemp -> getQuizPointsCorrect()) + " / " + to_string((int)quizTemp -> getQuizPointsTotal()));
	else                                                                                            headers << QString::number(quizTemp -> getQuizPointsTotal());

	tableWidget_Questions -> setHorizontalHeaderLabels(headers);
	tableWidget_Questions -> setAlternatingRowColors(true);
	tableWidget_Questions -> setColumnWidth(0,  1); ///< Column Width: S
	tableWidget_Questions -> setColumnWidth(1, 32); ///< Column Width: #
	tableWidget_Questions -> setColumnWidth(2, 76); ///< Column Width: Points
	tableWidget_Questions -> horizontalHeader() -> setSectionResizeMode(QHeaderView::Fixed); ///< Disable resizing column widths
	tableWidget_Questions -> verticalHeader() -> setVisible(false); ///< Hide row count column
	tableWidget_Questions -> verticalHeader() -> setDefaultSectionSize(25); ///< Set row height
	tableWidget_Questions -> setSelectionBehavior(QAbstractItemView::SelectRows); ///< Set entire row to be selected when selected
	tableWidget_Questions -> setSelectionMode(QAbstractItemView::SingleSelection); ///< Limit selection to a single row
	tableWidget_Questions -> setEditTriggers(QAbstractItemView::NoEditTriggers); ///< Set read only
	connect(tableWidget_Questions, &QTableWidget::itemSelectionChanged, this, &WindowTakeQuiz::selectionChanged);

	updateTableWidget_Questions();

	// pushButton_Jump
	pushButton_Jump = new QPushButton("Jump", this);
	pushButton_Jump -> setGeometry(QRect(QPoint(792, 512), QSize(152, 32)));
	pushButton_Jump -> setDisabled(true);
	connect(pushButton_Jump, &QPushButton::released, this, &WindowTakeQuiz::jumpToQuestion);
	if (quizTemp -> getQuizSettingJump() == false) pushButton_Jump -> setHidden(true);

	// pushButton_Previous
	pushButton_Previous = new QPushButton("Previous", this);
	pushButton_Previous -> setGeometry(QRect(QPoint(16, 576), QSize(448, 32)));
	connect(pushButton_Previous, &QPushButton::released, this, &WindowTakeQuiz::previousQuestion);

	// pushButton_Next
	pushButton_Next = new QPushButton("Next", this);
	pushButton_Next -> setGeometry(QRect(QPoint(496, 576), QSize(448, 32)));
	connect(pushButton_Next, &QPushButton::released, this, &WindowTakeQuiz::nextQuestion);

	// Hide pushButton_Previous and enlargen pushButton_Next if quiz does not allow moving backwards.
	if (quizTemp -> getQuizSettingBack() == false) {
		pushButton_Previous -> setHidden(true);
		pushButton_Next -> setGeometry(QRect(QPoint(16, 576), QSize(928, 32)));
	}

	buildAnswerLists();

	updateWindow(0);
}



/// @brief   Destructor.
/// @details Desconstructor for the WindowTakeQuiz class
WindowTakeQuiz::~WindowTakeQuiz() {};




/// @brief  Method to Build Answer List
/// @details Method to Build Answer List
void WindowTakeQuiz::buildAnswerLists() {
	listWidget_QWidget_Answers -> clear();

	// Display QWidget_Answers for each answer of the current question.
	for (int i = 0; i < questionAnswers.size(); i++) {
		// Add this answer of the question as a QWidget_Answer to listWidget_QWidget_Answers.
		item = new QListWidgetItem();
		item -> setFlags(item -> flags() & ~Qt::ItemIsEnabled);

		if ((quizTemp -> getQuizStatus() == 0) || (questionAnswers[i].getAnswerFeedback() == "")) item -> setSizeHint(QSize(736, 94));
		else                                                                                      item -> setSizeHint(QSize(736, 160));

		listWidget_QWidget_Answers -> insertItem(listWidget_QWidget_Answers -> count(), item);

		QWidget_Answer *qWidget_Answer = new QWidget_Answer(&questionAnswers[i]);

		if (((quizTemp -> getQuizSettingChange() == false) && (question.getQuestionStatus() > 0)) || (quizTemp -> getQuizStatus() != 0)) qWidget_Answer -> disableQObjects(questionAnswers[i].getAnswerType());

		listWidget_QWidget_Answers -> setItemWidget(item, qWidget_Answer);
	}
}




/// @brief   Method called when selection changes on answer list
/// @details Method called when selection changes on answer list
void WindowTakeQuiz::selectionChanged() {
	if (tableWidget_Questions -> selectedItems().isEmpty() == false) pushButton_Jump -> setDisabled(false);
	else                                                             pushButton_Jump -> setDisabled(true);
}


/// @brief   Method to jump to question
/// @details Method to jump to question
void WindowTakeQuiz::jumpToQuestion() {
	updateWindow(3);
}



/// @brief   Method to go to previous question
/// @details Method to go to previous question
void WindowTakeQuiz::previousQuestion() {
	// Go to WindowQuiz if viewing the first question of the quiz.
	if   (questionIndex == 0) submitQuiz();
	else                      updateWindow(1);
}



/// @brief   Method to go to next question
/// @details Method to go to next question
void WindowTakeQuiz::nextQuestion() {
	/// Go to WindowQuiz if viewing the last question of the quiz.
	if   (questionIndex == quizQuestions.size() - 1) submitQuiz();
	else                                             updateWindow(2);
}



/// @brief   Method to submit quiz
/// @details Method to submit quiz and switch to WindowQuiz window
void WindowTakeQuiz::submitQuiz() {
	updateQuiz();

	// Set some data for quizTemp now that it's being submitted.
	if (quizTemp -> getQuizStatus() == 0) {
		quizTemp -> setQuizTimeUsed(quizTimeUsed);
		quizTemp -> setQuizDate((QDate::currentDate().toString("d MMM yyyy")).toStdString());
		quizTemp -> setQuizTime((QTime::currentTime().toString("h:mm AP")).toStdString());
	}

	calculateQuizStatus();

	// Switch window.
	windowQuiz = new WindowQuiz(quizTemp);

	connect(windowQuiz, &WindowQuiz::switchWindow, this, &WindowQuiz::show);

	this       -> close();
	windowQuiz -> show();
}



/// @brief   Method to check quiz status
/// @details Method to check quiz status based on question status
void WindowTakeQuiz::calculateQuizStatus() {
	// If quiz has not been submitted yet...
	if (quizTemp -> getQuizStatus() == 0) {
		int questionsAnswered = 0;

		// Tally up how many questions have input.
		for (int i = 0; i < quizQuestions.size(); i++) if (quizQuestions[i].getQuestionStatus() >= 1) questionsAnswered += 1;

		// set quizTemp's quizStatus to either "Taken (incomplete)" or "Taken".
		if   (questionsAnswered != quizQuestions.size()) quizTemp -> setQuizStatus(1);
		else                                             quizTemp -> setQuizStatus(2);
	}
}



/// @brief   Method to update window
/// @details Method to update window to go backward, forward, or jump
/// @param button: int that determines backward, forward, or jump
void WindowTakeQuiz::updateWindow(int button) {
	// Update quizTemp.
	updateQuiz();

	// Determine which question should now be displayed/selected, based on which button was clicked.
	if (button == 1) questionIndex -= 1;
	if (button == 2) questionIndex += 1;
	if (button == 3) questionIndex = tableWidget_Questions -> currentRow(); /// Jump

	// Change current question to the new question.
	question = quizQuestions[questionIndex];

	// Change current question Answers to be the answers to the new question.
	questionAnswers = question.getQuestionAnswers();

	buildAnswerLists();

	// Update Qt elements.

	// lineEdit_Number
	lineEdit_Number -> setText(QString::number(question.getQuestionNumber()));

	// lineEdit_Title
	lineEdit_Title -> setText(QString::fromStdString(question.getQuestionTitle()));

	// plainTextEdit_Description
	plainTextEdit_Description -> setPlainText(QString::fromStdString(question.getQuestionDescription()));

	// lineEdit_Points
	string questionPointsCorrect = to_string(question.getQuestionPointsCorrect());
	string questionPointsTotal   = to_string(question.getQuestionPointsTotal());

	questionPointsCorrect.erase(questionPointsCorrect.find_last_not_of("0") + 1, string::npos);
	questionPointsTotal  .erase(questionPointsTotal  .find_last_not_of("0") + 1, string::npos);

	if (questionPointsCorrect.back() == '.') questionPointsCorrect.pop_back();
	if (questionPointsTotal  .back() == '.') questionPointsTotal  .pop_back();

	if ((questionPointsCorrect == "0") && (questionPointsTotal == "0")) lineEdit_Points -> setText("N/A");
	if (quizTemp -> getQuizSettingPointsQuestion() == true)             lineEdit_Points -> setText(QString::fromStdString(questionPointsCorrect + " / " + questionPointsTotal));
	else                                                                lineEdit_Points -> setText(QString::fromStdString(questionPointsTotal));

	// tableWidget_Questions
	updateTableWidget_Questions();

	// pushButton_Previous: Say "Submit" if taker is on the first question.
	if   (questionIndex == 0) {
		if (quizTemp -> getQuizStatus() == 0) pushButton_Previous -> setText("Submit");
		else                                  pushButton_Previous -> setText("Back");
	}
	else pushButton_Previous -> setText("Previous");

	// pushButton_Next: Say "Submit" if taker is on the last question.
	if (questionIndex == quizQuestions.size() - 1) {
		if (quizTemp -> getQuizStatus() == 0)        pushButton_Next -> setText("Submit");
		else                                         pushButton_Next -> setText("Done");
	}
	else                                             pushButton_Next -> setText("Next");
}



/// @brief   Method to update quiz
/// @details Method to update quiz with new data
void WindowTakeQuiz::updateQuiz() {
	// Only update question if it has answers (otherwise, there's no way the taker could modify the question).
	if (questionAnswers.size() != 0) {
		// Record taker's input into current question.
		int   answersAnswered       = 0;
		float questionPointsCorrect = 0;

		for (int i = 0; i < questionAnswers.size(); i++) {
			QWidget_Answer *qWidget_Answer = dynamic_cast<QWidget_Answer*>(listWidget_QWidget_Answers -> itemWidget(listWidget_QWidget_Answers -> item(i)));

			// answerType: TF
			if (questionAnswers[i].getAnswerType() == 0) {

				// true
				if (qWidget_Answer -> getQWidget_AnswerInputTF() == 2) {
					questionAnswers[i].setAnswerInput("true");
					questionAnswers[i].setAnswerStatus(1);

					answersAnswered += 1;
				}
				// false
				else if (qWidget_Answer -> getQWidget_AnswerInputTF() == 1) {
					questionAnswers[i].setAnswerInput("false");
					questionAnswers[i].setAnswerStatus(1);

					answersAnswered += 1;
				}

				else questionAnswers[i].setAnswerInput("unselected");
			}

			// answerType: MC
			if (questionAnswers[i].getAnswerType() == 1) {
				if   (qWidget_Answer -> getQWidget_AnswerInputMC() == 1) questionAnswers[i].setAnswerInput("selected");
				else                                                     questionAnswers[i].setAnswerInput("unselected");

				questionAnswers[i].setAnswerStatus(1);

				answersAnswered += 1;
			}

			// answerType: WA
			if (questionAnswers[i].getAnswerType() == 2) {
				questionAnswers[i].setAnswerInput(qWidget_Answer -> getQWidget_AnswerInputWA());

				if (questionAnswers[i].getAnswerInput() != "") {
					questionAnswers[i].setAnswerStatus(1);

					answersAnswered += 1;
				}
			}

			// Update questionPointsCorrect based on the user's input.
			if (questionAnswers[i].getAnswerInput() == questionAnswers[i].getAnswerCorrect()) questionPointsCorrect += questionAnswers[i].getAnswerPoints();

			question.setQuestionPointsCorrect(questionPointsCorrect);
		}

		// Update questionStatus based on answerStatus of each answer of question.
		if (answersAnswered > 0)                       question.setQuestionStatus(1);
		if (answersAnswered == questionAnswers.size()) question.setQuestionStatus(2);

		// Update question's answers with the answered answers.
		question.setQuestionAnswers(questionAnswers);

		// Update question in quizQuestions.
		quizQuestions[questionIndex] = question;

		// Update quizTemp's questions to the questions that include the updated question.
		quizTemp -> setQuizQuestions(quizQuestions);

		// Update quizTemp's quizPointsCorrect and quizPointsTotal.
		float quizPointsTotal   = 0;
		float quizPointsCorrect = 0;

		// Get total points and correct points
		for (int i = 0; i < quizQuestions.size(); i++) {
			quizPointsTotal   += quizQuestions[i].getQuestionPointsTotal();
			quizPointsCorrect += quizQuestions[i].getQuestionPointsCorrect();
		}

		// Set point values
		this -> quizTemp -> setQuizPointsTotal(quizPointsTotal);
		this -> quizTemp -> setQuizPointsCorrect(quizPointsCorrect);
	}
}



/// @brief   Method to update table with question
/// @details Method to update table with question and data values
void WindowTakeQuiz::updateTableWidget_Questions() {
	for (int i = 0; i < quizQuestions.size(); i++) {
		tableWidget_Questions -> setRowCount(quizQuestions.size());

		QStringList headers = {"S", "#"};

		if (quizTemp -> getQuizStatus() == 0) headers << QString::number(quizTemp -> getQuizPointsTotal());
		else                                  headers << QString::fromStdString(to_string((int)quizTemp -> getQuizPointsCorrect()) + " / " + to_string((int)quizTemp -> getQuizPointsTotal()));

		tableWidget_Questions -> setHorizontalHeaderLabels(headers);

		string questionStatus = "○";

		// Set questionStatus based on question status
		if      (quizQuestions[i].getQuestionStatus()      == 1) questionStatus = "◐";
		else if (quizQuestions[i].getQuestionStatus()      == 2) questionStatus = "●";
		if      (quizQuestions[i].getQuestionPointsTotal() == 0) questionStatus = "";

		tableWidget_Questions -> setItem(i, 0, new QTableWidgetItem(QString::fromStdString(questionStatus)));
		tableWidget_Questions -> setItem(i, 1, new QTableWidgetItem(QString::number(quizQuestions[i].getQuestionNumber())));

		// If taking quiz...
		if (quizTemp -> getQuizStatus() == 0) tableWidget_Questions -> setItem(i, 2, new QTableWidgetItem(QString::number(quizQuestions[i].getQuestionPointsTotal())));

		// If points are shown per question after submitting them, or viewing taken quiz...
		else if (((quizTemp -> getQuizSettingPointsQuestion() == true) && (quizQuestions[i].getQuestionStatus() >= 1)) || (quizTemp -> getQuizStatus() >= 1)) tableWidget_Questions -> setItem(i, 2, new QTableWidgetItem(QString::number(quizQuestions[i].getQuestionPointsCorrect()) + " / " + QString::number(quizQuestions[i].getQuestionPointsTotal())));
	}
}



/// @brief   Method to update time used on quiz
/// @details Method to update time used on quiz, and warn user if time is all used
void WindowTakeQuiz::updateLineEdit_TimeUsed() {
	// Get current time used.
	quizTimeUsedhh = atoi(lineEdit_TimeUsed -> text().toStdString().substr(0, 2).c_str());
	quizTimeUsedmm = atoi(lineEdit_TimeUsed -> text().toStdString().substr(3, 3).c_str());
	quizTimeUsedss = atoi(lineEdit_TimeUsed -> text().toStdString().substr(6, 4).c_str());

	time_TimeUsed.setHMS(quizTimeUsedhh, quizTimeUsedmm, quizTimeUsedss);

	// Add 1 second to current time used.
	static_cast<void>(time_TimeUsed = time_TimeUsed.addSecs(1));

	quizTimeUsed = time_TimeUsed.toString().toStdString();

	lineEdit_TimeUsed -> setText(QString::fromStdString(quizTimeUsed));

	// Inform quiz taker that they have used time equal to the time limit.
	if ((quizTemp -> getQuizStatus() == 0) && (quizTimeUsed == quizTimeLimit)) {
		messageBox.critical(0, "Time's Up!", "You have used all the time allotted to you for this quiz. The quiz will now be automatically submitted.");

		submitQuiz();
	}
}
