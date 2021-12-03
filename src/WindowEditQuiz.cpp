/// @file   WindowEditQuiz.cpp
/// @author Kenneth McAlinden
/// @author Navjeeven Mann
/// @date   30 November 2021
/// @brief  WindowEditQuiz class used to edit quizzes 



#include "WindowEditQuiz.h"
#include "WindowQuiz.h"



/// @brief   Constructor
/// @details WindowEditQuiz Constructor that initializes the view with parameter values
/// @param   *quiz:  Quiz pointer
/// @param   *quizTemp: temp Quiz pointer
/// @param   *parent: QWidget parent window pointer
WindowEditQuiz::WindowEditQuiz(Quiz *quiz, Quiz *quizTemp, QWidget *parent) : QMainWindow(parent) {
	this -> setFixedSize(960, 624);
	this -> setWindowTitle("Quiz Maker: Edit Quiz");

	this -> quiz     = quiz;
	this -> quizTemp = quizTemp;

	quizQuestionsTemp = quizTemp -> getQuizQuestions();

	// Sort quiz questions so that they are shown in table sorted by letter (descending).
	sort(quizQuestionsTemp.begin(), quizQuestionsTemp.end(), compareQuestions);

	this -> quizTemp -> setQuizQuestions(quizQuestionsTemp);

	// label_Title
	label_Title = new QLabel("Title", this);
	label_Title -> setGeometry(QRect(QPoint(16, 24), QSize(64, 16)));

	// lineEdit_Title
	lineEdit_Title = new QLineEdit(this);
	lineEdit_Title -> setGeometry(QRect(QPoint(80, 16), QSize(384, 32)));
	lineEdit_Title -> setText(QString::fromStdString(quizTemp -> getQuizTitle()));

	// label_Maker
	label_Maker = new QLabel("Maker", this);
	label_Maker -> setGeometry(QRect(QPoint(16, 72), QSize(64, 16)));

	// lineEdit_Maker
	lineEdit_Maker = new QLineEdit(this);
	lineEdit_Maker -> setGeometry(QRect(QPoint(80, 64), QSize(384, 32)));
	lineEdit_Maker -> setText(QString::fromStdString(quizTemp -> getQuizMaker()));

	// label_Taker
	label_Taker = new QLabel("Taker", this);
	label_Taker -> setGeometry(QRect(QPoint(16, 120), QSize(64 , 16)));

	// lineEdit_Taker
	lineEdit_Taker = new QLineEdit(this);
	lineEdit_Taker -> setPlaceholderText("leave blank to prompt taker for name");
	lineEdit_Taker -> setGeometry(QRect(QPoint(80, 112), QSize(384, 32)));
	lineEdit_Taker -> setText(QString::fromStdString(quizTemp -> getQuizTaker()));

	// plainTextEdit_Description
	plainTextEdit_Description = new QPlainTextEdit(this);
	plainTextEdit_Description -> setPlaceholderText("enter quiz description...");
	plainTextEdit_Description -> setGeometry(QRect(QPoint(16, 176), QSize(448, 208)));
	plainTextEdit_Description -> setPlainText(QString::fromStdString(quizTemp -> getQuizDescription()));

	// label_TimeLimit
	label_TimeLimit = new QLabel("Time Limit", this);
	label_TimeLimit -> setGeometry(QRect(QPoint(16, 424), QSize(144, 16)));
	label_TimeLimit -> setStyleSheet("color: rgb(128, 223, 255);");

	// lineEdit_TimeLimit
	lineEdit_TimeLimit = new QLineEdit(this);
	lineEdit_TimeLimit -> setPlaceholderText("hh:mm:ss (if desired)");
	lineEdit_TimeLimit -> setGeometry(QRect(QPoint(160, 416), QSize(304, 32)));
	lineEdit_TimeLimit -> setMaxLength(8);
	if (quizTemp -> getQuizTimeLimit() != "00:00:00") lineEdit_TimeLimit -> setText(QString::fromStdString(quizTemp -> getQuizTimeLimit()));

	// label_PasswordEdit
	label_PasswordEdit = new QLabel("Edit Password", this);
	label_PasswordEdit -> setGeometry(QRect(QPoint(16, 472), QSize(144, 16)));
	label_PasswordEdit -> setStyleSheet("color: rgb(128, 223, 255);");

	// lineEdit_PasswordEdit
	lineEdit_PasswordEdit = new QLineEdit(this);
	lineEdit_PasswordEdit -> setPlaceholderText("leave blank to let anyone edit");
	lineEdit_PasswordEdit -> setGeometry(QRect(QPoint(160, 464), QSize(304, 32)));
	lineEdit_PasswordEdit -> setMaxLength(32);
	lineEdit_PasswordEdit -> setText(QString::fromStdString(quizTemp -> getQuizPasswordEdit()));

	// label_PasswordTake
	label_PasswordTake = new QLabel("Take Password", this);
	label_PasswordTake -> setGeometry(QRect(QPoint(16, 520), QSize(144, 16)));
	label_PasswordTake -> setStyleSheet("color: rgb(128, 223, 255);");

	// lineEdit_PasswordTake
	lineEdit_PasswordTake = new QLineEdit(this);
	lineEdit_PasswordTake -> setPlaceholderText("leave blank to let anyone take");
	lineEdit_PasswordTake -> setGeometry(QRect(QPoint(160, 512), QSize(304, 32)));
	lineEdit_PasswordTake -> setMaxLength(32);
	lineEdit_PasswordTake -> setText(QString::fromStdString(quizTemp -> getQuizPasswordTake()));

	// checkBox_SettingRandom
	checkBox_SettingRandom = new QCheckBox("Random question order", this);
	checkBox_SettingRandom -> setGeometry(QRect(QPoint(496, 16), QSize(216, 32)));
	if (quizTemp -> getQuizSettingRandomQuestion() == true) checkBox_SettingRandom -> setChecked(true);

	// checkBox_SettingJump
	checkBox_SettingJump = new QCheckBox("Allow jump to question", this);
	checkBox_SettingJump -> setGeometry(QRect(QPoint(496, 64), QSize(216, 32)));
	if (quizTemp -> getQuizSettingJump() == true) checkBox_SettingJump -> setChecked(true);

	// checkBox_SettingChange
	checkBox_SettingChange = new QCheckBox("Allow changing answer", this);
	checkBox_SettingChange -> setGeometry(QRect(QPoint(496, 112), QSize(216, 32)));
	if (quizTemp -> getQuizSettingChange() == true) checkBox_SettingChange -> setChecked(true);

	// checkBox_SettingBack
	checkBox_SettingBack = new QCheckBox("Allow move backwards", this);
	checkBox_SettingBack -> setGeometry(QRect(QPoint(728, 16), QSize(216, 32)));
	if (quizTemp -> getQuizSettingBack() == true) checkBox_SettingBack -> setChecked(true);

	// checkBox_SettingPointsQuiz
	checkBox_SettingPointsQuiz = new QCheckBox("Show points on completion", this);
	checkBox_SettingPointsQuiz -> setGeometry(QRect(QPoint(728, 64), QSize(216, 32)));
	if (quizTemp -> getQuizSettingPointsQuiz() == true) checkBox_SettingPointsQuiz -> setChecked(true);

	// checkBox_SettingPointsQuestion
	checkBox_SettingPointsQuestion = new QCheckBox("Show points per question", this);
	checkBox_SettingPointsQuestion -> setGeometry(QRect(QPoint(728, 112), QSize(216, 32)));
	if (quizTemp -> getQuizSettingPointsQuestion() == true) checkBox_SettingPointsQuestion -> setChecked(true);

	// pushButton_Add
	pushButton_Add = new QPushButton("Add", this);
	pushButton_Add -> setGeometry(QRect(QPoint(496, 176), QSize(138.6665, 32)));
	connect(pushButton_Add, &QPushButton::released, this, &WindowEditQuiz::addQuestion);

	// pushButton_Delete
	pushButton_Delete = new QPushButton("Delete", this);
	pushButton_Delete -> setGeometry(QRect(QPoint(650.5369, 176), QSize(138.6665, 32)));
	pushButton_Delete -> setDisabled(true);
	connect(pushButton_Delete, &QPushButton::released, this, &WindowEditQuiz::deleteQuestion);

	// pushButton_Edit
	pushButton_Edit = new QPushButton("Edit", this);
	pushButton_Edit -> setGeometry(QRect(QPoint(805.3335, 176), QSize(138.6665, 32)));
	pushButton_Edit -> setDisabled(true);
	connect(pushButton_Edit, &QPushButton::released, this, &WindowEditQuiz::editQuestion);

	// tableWidget_Questions
	tableWidget_Questions = new QTableWidget(0, 5, this);
	tableWidget_Questions -> setGeometry(QRect(QPoint(496, 224), QSize(448, 320)));

	// tableWidget_Questions: Make a copy of Question's Answer vector.
	quizQuestionsTemp = this -> quizTemp -> getQuizQuestions();

	float quizPointsTotal   = 0;
	float quizPointsCorrect = 0;

	for (int i = 0; i < quizQuestionsTemp.size(); i++) {
		quizPointsTotal   += quizQuestionsTemp[i].getQuestionPointsTotal();
		quizPointsCorrect += quizQuestionsTemp[i].getQuestionPointsCorrect();
	}

	// Set quiz points
	this -> quizTemp -> setQuizPointsTotal(quizPointsTotal);
	this -> quizTemp -> setQuizPointsCorrect(quizPointsCorrect);

	quizPoints = to_string((int)quizPointsCorrect) + " / " + to_string((int)quizPointsTotal);

	if (quizPoints == "0 / 0") quizPoints = "Points";

	QStringList headers = {"S", "#", "Title", "Description"};

	headers << QString::fromStdString(quizPoints);

	// Set tableWidget_Questions
	tableWidget_Questions -> setHorizontalHeaderLabels(headers);
	tableWidget_Questions -> setAlternatingRowColors(true);
	tableWidget_Questions -> setColumnWidth(0,   1); ///< Column Width: S
	tableWidget_Questions -> setColumnWidth(1,  32); ///< Column Width: #
	tableWidget_Questions -> setColumnWidth(2, 124); ///< Column Width: Title
	tableWidget_Questions -> setColumnWidth(3, 194); ///< Column Width: Description
	tableWidget_Questions -> setColumnWidth(4,  70); ///< Column Width: Points
	tableWidget_Questions -> horizontalHeader() -> setSectionResizeMode(QHeaderView::Fixed); ///< Disable resizing column widths
	tableWidget_Questions -> verticalHeader() -> setVisible(false); ///< Hide row count column
	tableWidget_Questions -> verticalHeader() -> setDefaultSectionSize(50); ///< Set row height
	tableWidget_Questions -> setSelectionBehavior(QAbstractItemView::SelectRows); ///< Set entire row to be selected when selected
	tableWidget_Questions -> setSelectionMode(QAbstractItemView::SingleSelection); ///< Limit selection to a single row
	tableWidget_Questions -> setEditTriggers(QAbstractItemView::NoEditTriggers); ///< Set read only
	connect(tableWidget_Questions, &QTableWidget::itemSelectionChanged, this, &WindowEditQuiz::selectionChanged);

	// Populate table with Quiz's Questions.
	buildTableWidget_Questions();

	// pushButton_Cancel
	pushButton_Cancel = new QPushButton("Cancel", this);
	pushButton_Cancel -> setGeometry(QRect(QPoint(16, 576), QSize(448, 32)));
	connect(pushButton_Cancel, &QPushButton::released, this, &WindowEditQuiz::cancel);

	// pushButton_Ok
	pushButton_Ok = new QPushButton("Ok", this);
	pushButton_Ok -> setGeometry(QRect(QPoint(496, 576), QSize(448, 32)));
	connect(pushButton_Ok, &QPushButton::released, this, &WindowEditQuiz::ok);
}



/// @brief   Destructor.
/// @details WindowEditQuiz Desconstructor
WindowEditQuiz::~WindowEditQuiz() {};



/// @brief Method to add question
/// @details Method to add question which navigates to WindowEditQuesiton window
void WindowEditQuiz::addQuestion() {
	// Set values for quizTemp to pass into WindowEditQuesiton.
	setQuizAttributes();

	Quiz *quizTempTemp = new Quiz();

	*quizTempTemp = *quizTemp;

	Question *question = new Question();

	// Switch window.
	windowEditQuestion = new WindowEditQuestion(quiz, quizTemp, quizTempTemp, question);

	connect(windowEditQuestion, &WindowEditQuestion::switchWindow, this, &WindowEditQuestion::show);

	this               -> close();
	windowEditQuestion -> show();
}



/// @brief Method to delete a question
/// @details  Method to delete a question
void WindowEditQuiz::deleteQuestion() {

	// erase currentRow from the table
	quizQuestionsTemp.erase(quizQuestionsTemp.begin() + (tableWidget_Questions -> currentRow()));

	// update the quiz with the new total points and current points
	float quizPointsTotal   = 0;
	float quizPointsCorrect = 0;

	for (int i = 0; i < quizQuestionsTemp.size(); i++) {
		quizPointsTotal   += quizQuestionsTemp[i].getQuestionPointsTotal();
		quizPointsCorrect += quizQuestionsTemp[i].getQuestionPointsCorrect();
	}

	// Set quiz points
	this -> quizTemp -> setQuizPointsTotal(quizPointsTotal);
	this -> quizTemp -> setQuizPointsCorrect(quizPointsCorrect);

	quizPoints = to_string((int)quizPointsCorrect) + " / " + to_string((int)quizPointsTotal);

	if (quizPoints == "0 / 0") quizPoints = "Points";

	// recreate table
	QStringList headers = {"S", "#", "Title", "Description"};

	headers << QString::fromStdString(quizPoints);

	tableWidget_Questions -> setHorizontalHeaderLabels(headers);

	quizTemp -> setQuizQuestions(quizQuestionsTemp);

	tableWidget_Questions -> setRowCount(0);

	buildTableWidget_Questions();
}



/// @brief Method to edit a question
/// @details Method to edit a question which opens a WindowEditQuesiton window
void WindowEditQuiz::editQuestion() {
	setQuizAttributes();

	Quiz *quizTempTemp = new Quiz();

	*quizTempTemp = *quizTemp;

	// Switch window.
	windowEditQuestion = new WindowEditQuestion(quiz, quizTemp, quizTempTemp, &quizQuestionsTemp[tableWidget_Questions -> currentRow()]);

	connect(windowEditQuestion, &WindowEditQuestion::switchWindow, this, &WindowEditQuestion::show);

	this               -> close();
	windowEditQuestion -> show();
}



/// @brief Method to Cancel
/// @param Method to Cancel Editing of the Quiz
void WindowEditQuiz::cancel() {
	// Open the temp file storing the previous quiz.
	QString quizFileName = (QDir::homePath() + QString("/QuizMaker/Temp/temp.quiz"));

	Quiz *quizNew = new Quiz();

	quizFile = new QuizFile(quizNew);

	quizFile -> readFile(quizFileName);

	// Switch window.
	windowQuiz = new WindowQuiz(quiz);

	connect(windowQuiz, &WindowQuiz::switchWindow, this, &WindowQuiz::show);

	this       -> close();
	windowQuiz -> show();
}



/// @brief Method to Ok
/// @param Method to confirm changes to the quiz
void WindowEditQuiz::ok() {
	// Check that time limit was input correctly.
	bool   invalid            = 0;
	string quizTimeLimitInput = lineEdit_TimeLimit -> text().toStdString();

	// Get time values
	if (quizTimeLimitInput.size() == 8) {
		string quizTimeLimitInputhh     = quizTimeLimitInput.substr(0, 2);
		string quizTimeLimitInputColon1 = quizTimeLimitInput.substr(2, 1);
		string quizTimeLimitInputmm     = quizTimeLimitInput.substr(3, 2);
		string quizTimeLimitInputColon2 = quizTimeLimitInput.substr(5, 1);
		string quizTimeLimitInputss     = quizTimeLimitInput.substr(6, 2);

		if ((isNumber(quizTimeLimitInputhh) == false) || (isNumber(quizTimeLimitInputmm) == false) || (isNumber(quizTimeLimitInputss) == false) || (quizTimeLimitInputColon1 != ":") || (quizTimeLimitInputColon2 != ":")) invalid = 1;
	}

	else if (quizTimeLimitInput != "") invalid = 1;

	if (invalid == 1) {
		messageBox.critical(0, "Error", "If you enter a time limit for the quiz, it must be of the format \"hh:mm:ss\".");

		lineEdit_TimeLimit -> setFocus();

		return;
	}

	else if (lineEdit_Title -> text().isEmpty()) {
		messageBox.critical(0, "Error", "Enter a title for the quiz!");

		lineEdit_Title -> setFocus();
	}

	else {
		// Set data
		quizTemp -> setQuizTitle(lineEdit_Title -> text().toStdString());
		quizTemp -> setQuizMaker(lineEdit_Maker -> text().toStdString());
		quizTemp -> setQuizTaker(lineEdit_Taker -> text().toStdString());
		quizTemp -> setQuizDescription(plainTextEdit_Description -> toPlainText().toStdString());

		int   questionsAnswered = 0;
		float quizPointsTotal   = 0;
		float quizPointsCorrect = 0;

		// Set Total and Current Points for Quiz
		for (int i = 0; i < quizQuestionsTemp.size(); i++) {
			if ((quizQuestionsTemp[i].getQuestionStatus() >= 1) && (quizQuestionsTemp[i].getQuestionPointsTotal() != 0)) questionsAnswered += 1;

			quizPointsTotal   += quizQuestionsTemp[i].getQuestionPointsTotal();
			quizPointsCorrect += quizQuestionsTemp[i].getQuestionPointsCorrect();
		}
		// Set quiz status
		if      (questionsAnswered == 0)                        quizTemp -> setQuizStatus(0);
		else if (questionsAnswered != quizQuestionsTemp.size()) quizTemp -> setQuizStatus(1);
		else                                                    quizTemp -> setQuizStatus(2);

		// Set quiz points
		quizTemp -> setQuizPointsTotal(quizPointsTotal);
		quizTemp -> setQuizPointsCorrect(quizPointsCorrect);

		if (lineEdit_TimeLimit -> text().isEmpty()) quizTemp -> setQuizTimeLimit("00:00:00");
		else                                        quizTemp -> setQuizTimeLimit(lineEdit_TimeLimit -> text().toStdString());

		// Set Data
		if (quizTemp -> getQuizTimeUsed() == "") quizTemp -> setQuizTimeUsed("00:00:00");
		if (quizTemp -> getQuizTimeUsed() == "N/A") quizTemp -> setQuizTimeUsed("00:00:00");
		quizTemp -> setQuizSettingRandomQuestion(checkBox_SettingRandom -> isChecked());
		quizTemp -> setQuizSettingJump(checkBox_SettingJump -> isChecked());
		quizTemp -> setQuizSettingChange(checkBox_SettingChange -> isChecked());
		quizTemp -> setQuizSettingBack(checkBox_SettingBack -> isChecked());
		quizTemp -> setQuizSettingPointsQuiz(checkBox_SettingPointsQuiz -> isChecked());
		quizTemp -> setQuizSettingPointsQuestion(checkBox_SettingPointsQuestion -> isChecked());
		quizTemp -> setQuizPasswordEdit(lineEdit_PasswordEdit -> text().toStdString());
		quizTemp -> setQuizPasswordTake(lineEdit_PasswordTake -> text().toStdString());
		quizTemp -> setQuizQuestions(quizQuestionsTemp);

		// Switch window.
		windowQuiz = new WindowQuiz(quizTemp);

		connect(windowQuiz, &WindowQuiz::switchWindow, this, &WindowQuiz::show);

		this       -> close();
		windowQuiz -> show();
	}
}



/// @brief Selection Change Method
/// @param Method called when selection changes on the table
void WindowEditQuiz::selectionChanged() {
	if (tableWidget_Questions -> selectedItems().isEmpty() == false) {
		pushButton_Edit   -> setDisabled(false);
		pushButton_Delete -> setDisabled(false);
	}

	else {
		pushButton_Edit   -> setDisabled(true);
		pushButton_Delete -> setDisabled(true);
	}
}



/// @brief  Check if string is a number
/// @param  quizTimeLimitInput: string of time value
/// @return true is number, false if else
bool WindowEditQuiz::isNumber(const string& quizTimeLimitInput) {
	for (char const &quizTimeLimitInputChar : quizTimeLimitInput) if (isdigit(quizTimeLimitInputChar) == 0) return false;

	return true;
}



/// @brief  Method to compare Questions
/// @details Method to compare Question numbers
/// @param  question1: Question to compare
/// @param  question2: Question to compare with
/// @return bool for whether question1 questionNumber is less than question2
bool WindowEditQuiz::compareQuestions(Question question1, Question question2) {
	return (question1.getQuestionNumber() < question2.getQuestionNumber());
}



/// @brief Method to build Question Table
/// @details Method used to build Question Table and set information
void WindowEditQuiz::buildTableWidget_Questions() {
	for (int i = 0; i < quizQuestionsTemp.size(); i++) {
		tableWidget_Questions -> setRowCount(tableWidget_Questions -> rowCount() + 1);

		string questionStatus = "○";

		// Set questionStatus based on question status
		if      (quizQuestionsTemp[i].getQuestionStatus() == 0)      questionStatus = "○";
		else if (quizQuestionsTemp[i].getQuestionStatus() == 1)      questionStatus = "◐";
		else if (quizQuestionsTemp[i].getQuestionStatus() == 2)      questionStatus = "●";
		if      (quizQuestionsTemp[i].getQuestionPointsTotal() == 0) questionStatus = "";

		tableWidget_Questions -> setItem(i, 0, new QTableWidgetItem(QString::fromStdString(questionStatus)));
		tableWidget_Questions -> setItem(i, 1, new QTableWidgetItem(QString::number(quizQuestionsTemp[i].getQuestionNumber())));
		tableWidget_Questions -> setItem(i, 2, new QTableWidgetItem(QString::fromStdString(quizQuestionsTemp[i].getQuestionTitle())));
		tableWidget_Questions -> setItem(i, 3, new QTableWidgetItem(QString::fromStdString(quizQuestionsTemp[i].getQuestionDescription())));
		tableWidget_Questions -> setItem(i, 4, new QTableWidgetItem(QString::number(quizQuestionsTemp[i].getQuestionPointsCorrect()) + " / " + QString::number(quizQuestionsTemp[i].getQuestionPointsTotal())));
	}
}



/// @brief Method to set data for Quiz
/// @details Method is used to fill out all information for the quizTemp pointer
void WindowEditQuiz::setQuizAttributes() {
	// Set values for quizTemp to pass into WindowEditQuesiton.
	quizTemp -> setQuizTitle(lineEdit_Title -> text().toStdString());
	quizTemp -> setQuizMaker(lineEdit_Maker -> text().toStdString());
	quizTemp -> setQuizTaker(lineEdit_Taker -> text().toStdString());
	quizTemp -> setQuizDescription(plainTextEdit_Description -> toPlainText().toStdString());

	if (lineEdit_TimeLimit -> text().isEmpty() == false) quizTemp -> setQuizTimeLimit(lineEdit_TimeLimit -> text().toStdString());

	// Set data
	quizTemp -> setQuizSettingRandomQuestion(checkBox_SettingRandom -> isChecked());
	quizTemp -> setQuizSettingJump(checkBox_SettingJump -> isChecked());
	quizTemp -> setQuizSettingChange(checkBox_SettingChange -> isChecked());
	quizTemp -> setQuizSettingBack(checkBox_SettingBack -> isChecked());
	quizTemp -> setQuizSettingPointsQuiz(checkBox_SettingPointsQuiz -> isChecked());
	quizTemp -> setQuizSettingPointsQuestion(checkBox_SettingPointsQuestion -> isChecked());
	quizTemp -> setQuizPasswordEdit(lineEdit_PasswordEdit -> text().toStdString());
	quizTemp -> setQuizPasswordTake(lineEdit_PasswordTake -> text().toStdString());
	quizTemp -> setQuizQuestions(quizQuestionsTemp);
}
