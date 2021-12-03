/// @file   WindowQuiz.cpp
/// @author Kenneth McAlinden
/// @date   30 November 2021
/// @brief  WindowQuiz class used to display quizzes



#include "WindowQuiz.h"



/// @brief   Constructor.
/// @details Constructor for the WindowQuiz class
/// @param   *parent: Qwidget pointer to the main window.
WindowQuiz::WindowQuiz(Quiz *quiz, QWidget *parent) : QMainWindow(parent) {
	this -> setFixedSize(960, 624);
	this -> setWindowTitle("Quiz Maker: Quiz Details");

	this -> quiz = quiz;

	// pushButton_New
	pushButton_New = new QPushButton("New", this);
	pushButton_New -> setGeometry(QRect(QPoint(16, 16), QSize(288, 32)));
	connect(pushButton_New, &QPushButton::released, this, &WindowQuiz::newQuiz);

	// pushButton_Open
	pushButton_Open = new QPushButton("Open...", this);
	pushButton_Open -> setGeometry(QRect(QPoint(336, 16), QSize(288, 32)));
	connect(pushButton_Open, &QPushButton::released, this, &WindowQuiz::openQuiz);

	// pushButton_SaveAs
	pushButton_SaveAs = new QPushButton("Save As...", this);
	pushButton_SaveAs -> setGeometry(QRect(QPoint(656, 16), QSize(288, 32)));
	connect(pushButton_SaveAs, &QPushButton::released, this, &WindowQuiz::saveAsQuiz);

	// label_File
	label_File = new QLabel("File", this);
	label_File -> setGeometry(QRect(QPoint(16, 88), QSize(64, 16)));

	// lineEdit_File
	lineEdit_File = new QLineEdit(this);
	lineEdit_File -> setGeometry(QRect(QPoint(80, 80), QSize(384, 32)));
	lineEdit_File -> setReadOnly(true);
	lineEdit_File -> setStyleSheet("color: rgb(223, 223, 223); background-color: rgb(14, 28, 84);");

	// label_Title
	label_Title = new QLabel("Title", this);
	label_Title -> setGeometry(QRect(QPoint(16, 136), QSize(64, 16)));

	// lineEdit_Title
	lineEdit_Title = new QLineEdit(this);
	lineEdit_Title -> setGeometry(QRect(QPoint(80, 128), QSize(384, 32)));
	lineEdit_Title -> setReadOnly(true);
	lineEdit_Title -> setStyleSheet("color: rgb(223, 223, 223); background-color: rgb(14, 28, 84);");

	// label_Maker
	label_Maker = new QLabel("Maker", this);
	label_Maker -> setGeometry(QRect(QPoint(16, 184), QSize(64, 16)));

	// lineEdit_Maker
	lineEdit_Maker = new QLineEdit(this);
	lineEdit_Maker -> setGeometry(QRect(QPoint(80, 176), QSize(384, 32)));
	lineEdit_Maker -> setReadOnly(true);
	lineEdit_Maker -> setStyleSheet("color: rgb(223, 223, 223); background-color: rgb(14, 28, 84);");

	// label_Taker
	label_Taker = new QLabel("Taker", this);
	label_Taker -> setGeometry(QRect(QPoint(16, 232), QSize(64, 16)));

	// lineEdit_Taker
	lineEdit_Taker = new QLineEdit(this);
	lineEdit_Taker -> setGeometry(QRect(QPoint(80, 224), QSize(384, 32)));
	lineEdit_Taker -> setReadOnly(true);
	lineEdit_Taker -> setStyleSheet("color: rgb(223, 223, 223); background-color: rgb(14, 28, 84);");

	// plainTextEdit_Description
	plainTextEdit_Description = new QPlainTextEdit(this);
	plainTextEdit_Description -> setGeometry(QRect(QPoint(16, 272), QSize(448, 272)));
	plainTextEdit_Description -> setReadOnly(true);
	plainTextEdit_Description -> setStyleSheet("color: rgb(223, 223, 223); background-color: rgb(14, 28, 84);");

	// label_Points
	label_Points = new QLabel("Points", this);
	label_Points -> setGeometry(QRect(QPoint(496, 88), QSize(56, 16)));
	label_Points -> setStyleSheet("color: rgb(128, 223, 255);");

	// lineEdit_Points
	lineEdit_Points = new QLineEdit(this);
	lineEdit_Points -> setGeometry(QRect(QPoint(568, 80), QSize(376, 32)));
	lineEdit_Points -> setReadOnly(true);
	lineEdit_Points -> setStyleSheet("color: rgb(223, 223, 223); background-color: rgb(14, 28, 84);");

	// label_Status
	label_Status = new QLabel("Status", this);
	label_Status -> setGeometry(QRect(QPoint(496, 136), QSize(96, 16)));
	label_Status -> setStyleSheet("color: rgb(128, 223, 255);");

	// lineEdit_Status
	lineEdit_Status = new QLineEdit(this);
	lineEdit_Status -> setGeometry(QRect(QPoint(568, 128), QSize(376, 32)));
	lineEdit_Status -> setReadOnly(true);
	lineEdit_Status -> setStyleSheet("color: rgb(223, 223, 223); background-color: rgb(14, 28, 84);");

	// label_Date
	label_Date = new QLabel("Date", this);
	label_Date -> setGeometry(QRect(QPoint(496, 184), QSize(56, 16)));
	label_Date -> setStyleSheet("color: rgb(128, 223, 255);");

	// lineEdit_Date
	lineEdit_Date = new QLineEdit(this);
	lineEdit_Date -> setGeometry(QRect(QPoint(592, 176), QSize(120, 32)));
	lineEdit_Date -> setReadOnly(true);
	lineEdit_Date -> setStyleSheet("color: rgb(223, 223, 223); background-color: rgb(14, 28, 84);");

	// label_Time
	label_Time = new QLabel("Time", this);
	label_Time -> setGeometry(QRect(QPoint(728, 184), QSize(96, 16)));
	label_Time -> setStyleSheet("color: rgb(128, 223, 255);");

	// lineEdit_Time
	lineEdit_Time = new QLineEdit(this);
	lineEdit_Time -> setGeometry(QRect(QPoint(824, 176), QSize(120, 32)));
	lineEdit_Time -> setReadOnly(true);
	lineEdit_Time -> setStyleSheet("color: rgb(223, 223, 223); background-color: rgb(14, 28, 84);");

	// label_TimeLimit
	label_TimeLimit = new QLabel("Time Limit", this);
	label_TimeLimit -> setGeometry(QRect(QPoint(496, 232), QSize(96, 16)));
	label_TimeLimit -> setStyleSheet("color: rgb(128, 223, 255);");

	// lineEdit_TimeLimit
	lineEdit_TimeLimit = new QLineEdit(this);
	lineEdit_TimeLimit -> setGeometry(QRect(QPoint(592, 224), QSize(120, 32)));
	lineEdit_TimeLimit -> setReadOnly(true);
	lineEdit_TimeLimit -> setStyleSheet("color: rgb(223, 223, 223); background-color: rgb(14, 28, 84);");

	// label_TimeUsed
	label_TimeUsed = new QLabel("Time Used", this);
	label_TimeUsed -> setGeometry(QRect(QPoint(728, 232), QSize(96, 16)));
	label_TimeUsed -> setStyleSheet("color: rgb(128, 223, 255);");

	// lineEdit_TimeUsed
	lineEdit_TimeUsed = new QLineEdit(this);
	lineEdit_TimeUsed -> setGeometry(QRect(QPoint(824, 224), QSize(120, 32)));
	lineEdit_TimeUsed -> setReadOnly(true);
	lineEdit_TimeUsed -> setStyleSheet("color: rgb(223, 223, 223); background-color: rgb(14, 28, 84);");

	// lineEdit_SettingRandomQuestion
	lineEdit_SettingRandomQuestion = new QLineEdit(this);
	lineEdit_SettingRandomQuestion -> setGeometry(QRect(QPoint(496, 272), QSize(448, 32)));
	lineEdit_SettingRandomQuestion -> setReadOnly(true);
	lineEdit_SettingRandomQuestion -> setStyleSheet("font-size: 10pt; font-style: italic; padding: 8px; color: rgb(128, 159, 191); background-color: rgb(14, 28, 84);");

	// lineEdit_SettingJump
	lineEdit_SettingJump = new QLineEdit(this);
	lineEdit_SettingJump -> setGeometry(QRect(QPoint(496, 320), QSize(448, 32)));
	lineEdit_SettingJump -> setReadOnly(true);
	lineEdit_SettingJump -> setStyleSheet("font-size: 10pt; font-style: italic; padding: 8px; color: rgb(128, 159, 191); background-color: rgb(14, 28, 84);");

	// lineEdit_SettingChange
	lineEdit_SettingChange = new QLineEdit(this);
	lineEdit_SettingChange -> setGeometry(QRect(QPoint(496, 368), QSize(448, 32)));
	lineEdit_SettingChange -> setReadOnly(true);
	lineEdit_SettingChange -> setStyleSheet("font-size: 10pt; font-style: italic; padding: 8px; color: rgb(128, 159, 191); background-color: rgb(14, 28, 84);");

	// lineEdit_SettingBack
	lineEdit_SettingBack = new QLineEdit(this);
	lineEdit_SettingBack -> setGeometry(QRect(QPoint(496, 416), QSize(448, 32)));
	lineEdit_SettingBack -> setReadOnly(true);
	lineEdit_SettingBack -> setStyleSheet("font-size: 10pt; font-style: italic; padding: 8px; color: rgb(128, 159, 191); background-color: rgb(14, 28, 84);");

	// lineEdit_SettingPointsQuiz
	lineEdit_SettingPointsQuiz = new QLineEdit(this);
	lineEdit_SettingPointsQuiz -> setGeometry(QRect(QPoint(496, 464), QSize(448, 32)));
	lineEdit_SettingPointsQuiz -> setReadOnly(true);
	lineEdit_SettingPointsQuiz -> setStyleSheet("font-size: 10pt; font-style: italic; padding: 8px; color: rgb(128, 159, 191); background-color: rgb(14, 28, 84);");

	// lineEdit_SettingPointsQuestion
	lineEdit_SettingPointsQuestion = new QLineEdit(this);
	lineEdit_SettingPointsQuestion -> setGeometry(QRect(QPoint(496, 512), QSize(448, 32)));
	lineEdit_SettingPointsQuestion -> setReadOnly(true);
	lineEdit_SettingPointsQuestion -> setStyleSheet("font-size: 10pt; font-style: italic; padding: 8px; color: rgb(128, 159, 191); background-color: rgb(14, 28, 84);");

	// lineEdit_PasswordEdit
	lineEdit_PasswordEdit = new QLineEdit(this);
	lineEdit_PasswordEdit -> setPlaceholderText("enter edit password...");
	lineEdit_PasswordEdit -> setGeometry(QRect(QPoint(16, 576), QSize(304, 32)));

	// pushButton_Edit
	pushButton_Edit = new QPushButton("Edit", this);
	pushButton_Edit -> setGeometry(QRect(QPoint(336, 576), QSize(128, 32)));
	connect(pushButton_Edit, &QPushButton::released, this, &WindowQuiz::editQuiz);

	// lineEdit_PasswordTake
	lineEdit_PasswordTake = new QLineEdit(this);
	lineEdit_PasswordTake -> setPlaceholderText("enter take password...");
	lineEdit_PasswordTake -> setGeometry(QRect(QPoint(496, 576), QSize(304, 32)));

	// pushButton_Take
	pushButton_Take = new QPushButton("Take", this);
	pushButton_Take -> setGeometry(QRect(QPoint(816, 576), QSize(128, 32)));
	connect(pushButton_Take, &QPushButton::released, this, &WindowQuiz::takeQuiz);

	updateWindow();
}



/// @brief   Destructor.
/// @details Desconstructor for the WindowQuiz class
WindowQuiz::~WindowQuiz() {};



/// @brief   Method to create a new Quiz.
/// @details Method to create a new Quiz, which opens the WindowEditQuiz window
void WindowQuiz::newQuiz() {
	QString quizFileName = (QDir::homePath() + QString("/QuizMaker/Temp/temp.quiz"));

	quizFile = new QuizFile(quiz);

	quizFile -> writeFile(quizFileName);

	Quiz *quizTemp = new Quiz();

	// Switch window.
	windowEditQuiz = new WindowEditQuiz(quiz, quizTemp);

	connect(windowEditQuiz, &WindowEditQuiz::switchWindow, this, &WindowEditQuiz::show);

	this           -> close();
	windowEditQuiz -> show();
}



/// @brief   Method to open Quiz
/// @details Method to open a Quiz object from the file system
void WindowQuiz::openQuiz() {
	QString quizFileName = QFileDialog::getOpenFileName(this, "Open Quiz", (QDir::homePath() + QString("/QuizMaker")), "Quiz Files (*.quiz)");

	// Don't update quiz to be quiz if cancel was clicked on the file dialog.
	if   (quizFileName.toStdString() == "") return;
	else                                    pushButton_SaveAs -> setDisabled(false);

	quiz     = new Quiz();
	quizFile = new QuizFile(quiz);

	quizFile      -> readFile(quizFileName);

	lineEdit_File -> setText(quizFileName);

	updateWindow();
}




/// @brief   Method to save a Quiz Object.
/// @details Method to save a Quiz Object to the file system
void WindowQuiz::saveAsQuiz() {
	// Dialog box that opens to choose filename.
    QString quizFileName = QFileDialog::getSaveFileName(this, "Save Quiz As", (QDir::homePath() + QString("/QuizMaker")), "Quiz Files (*.quiz)");

    // Don't update quiz to be quiz if cancel was clicked on the file dialog.
    if (quizFileName == "") return;

	// Check if quiz file name has the .quiz extension.
	if (!quizFileName.endsWith(".quiz")) quizFileName.append(".quiz");

    quiz -> setQuizFile(quizFileName.toStdString());

	quizFile = new QuizFile(quiz);

	quizFile -> writeFile(quizFileName);

	// lineEdit_File
	if   (quiz -> getQuizFile() == "") lineEdit_File -> setText("Not saved");
	else                               lineEdit_File -> setText(QString::fromStdString(quiz -> getQuizFile()));
}



/// @brief   Method to edit a Quiz Object.
/// @details Method to edit a Quiz Object, which open a WindowEditQuiz window
void WindowQuiz::editQuiz() {
	string passwordEditInput = lineEdit_PasswordEdit -> text().toStdString();
	string passwordEditQuiz  = quiz -> getQuizPasswordEdit();

	// Input edit password correct.
	if (passwordEditInput == passwordEditQuiz) {
		Quiz *quizTemp = new Quiz();

		*quizTemp = *quiz;

		// Switch window.
		windowEditQuiz = new WindowEditQuiz(quiz, quizTemp);

		connect(windowEditQuiz, &WindowEditQuiz::switchWindow, this, &WindowEditQuiz::show);

		this           -> close();
		windowEditQuiz -> show();
	}

	// Input edit password incorrect.
	else {
		messageBox.critical(0,"Error", "You must enter the correct \"edit password\" to edit this quiz.");

		lineEdit_PasswordEdit -> setText("");
		lineEdit_PasswordEdit -> setFocus();
	}
}



/// @brief   Method to take a Quiz
/// @details Method to take a Quiz which opens a WindowTakeQuiz or windowTakeQuizTaker depending on if the taker is already set
void WindowQuiz::takeQuiz() {
	string passwordTakeInput = lineEdit_PasswordTake -> text().toStdString();
	string passwordTakeQuiz  = quiz -> getQuizPasswordTake();

	// Input Take password correct.
	if (passwordTakeInput == passwordTakeQuiz) {
		Quiz *quizTemp = new Quiz();

		*quizTemp = *quiz;

		// Taker not yet input.
		if (quiz -> getQuizTaker() == "") {
			// Switch window.
			windowTakeQuizTaker = new WindowTakeQuizTaker(quiz, quizTemp);

			connect(windowTakeQuizTaker, &WindowTakeQuizTaker::switchWindow, this, &WindowTakeQuizTaker::show);

			this                -> close();
			windowTakeQuizTaker -> show();
		}

		// Taker already input.
		else {
			// Switch window.
			windowTakeQuiz = new WindowTakeQuiz(quiz, quizTemp);

			connect(windowTakeQuiz, &WindowTakeQuiz::switchWindow, this, &WindowTakeQuiz::show);

			this           -> close();
			windowTakeQuiz -> show();
		}
	}

	// Input take password incorrect.
	else {
		messageBox.critical(0,"Error", "You must enter the correct \"take password\" to edit this quiz.");

		lineEdit_PasswordTake -> setText("");
		lineEdit_PasswordTake -> setFocus();
	}
}



/// @brief   Method to update the current window
/// @details Method to update the current window with data from the quiz object
void WindowQuiz::updateWindow() {
	if (quiz -> getQuizTitle() != "") {
		// lineEdit_File
		if   (quiz -> getQuizFile() == "") lineEdit_File -> setText("Not saved");
		else                               lineEdit_File -> setText(QString::fromStdString(quiz -> getQuizFile()));

		// lineEdit_Title
		lineEdit_Title -> setText(QString::fromStdString(quiz -> getQuizTitle()));

		// lineEdit_Maker
		lineEdit_Maker -> setText(QString::fromStdString(quiz -> getQuizMaker()));

		// lineEdit_Taker
		lineEdit_Taker -> setText(QString::fromStdString(quiz -> getQuizTaker()));

		// plainTextEdit_Description
		plainTextEdit_Description -> setPlainText(QString::fromStdString(quiz -> getQuizDescription()));

		// lineEdit_Points
		if   (quiz -> getQuizPointsTotal() == 0) lineEdit_Points -> setText("N/A");
		else                                     lineEdit_Points -> setText(QString::number(quiz -> getQuizPointsCorrect()) + " / " + QString::number(quiz -> getQuizPointsTotal()));
		if ((quiz -> getQuizStatus() > 0) && (quiz -> getQuizSettingPointsQuiz() == false)) lineEdit_Points -> setText("Hidden");

		// lineEdit_Status
		if      (quiz -> getQuizStatus() == 0) lineEdit_Status -> setText("Not taken");
		else if (quiz -> getQuizStatus() == 1) lineEdit_Status -> setText("Taken (incomplete)");
		else if (quiz -> getQuizStatus() == 2) lineEdit_Status -> setText("Taken");

		// lineEdit_Date
		if   (quiz -> getQuizStatus() == 0) lineEdit_Date -> setText("N/A");
		else                                lineEdit_Date -> setText(QString::fromStdString(quiz -> getQuizDate()));

		// lineEdit_Time
		if   (quiz -> getQuizStatus() == 0) lineEdit_Time -> setText("N/A");
		else                                lineEdit_Time -> setText(QString::fromStdString(quiz -> getQuizTime()));

		// lineEdit_TimeLimit
		if   (quiz -> getQuizTimeLimit() == "00:00:00") lineEdit_TimeLimit -> setText("N/A");
		else                                            lineEdit_TimeLimit -> setText(QString::fromStdString(quiz -> getQuizTimeLimit()));

		// lineEdit_TimeUsed
		if   (quiz -> getQuizTimeLimit() == "00:00:00") lineEdit_TimeUsed -> setText("N/A");
		else                                            lineEdit_TimeUsed -> setText(QString::fromStdString(quiz -> getQuizTimeUsed()));

		// lineEdit_SettingRandomQuestion
		if   (quiz -> getQuizSettingRandomQuestion() == false) lineEdit_SettingRandomQuestion -> setText("Question order is the same each time this quiz is taken.");
		else                                                   lineEdit_SettingRandomQuestion -> setText("Question order is random.");

		// lineEdit_SettingJump
		if   (quiz -> getQuizSettingJump() == false) lineEdit_SettingJump -> setText("The question list does not let you jump to questions.");
		else                                         lineEdit_SettingJump -> setText("The question list lets you jump to questions.");

		// lineEdit_SettingChange
		if   (quiz -> getQuizSettingChange() == false) lineEdit_SettingChange -> setText("You cannot change answers to questions after clicking Next.");
		else                                           lineEdit_SettingChange -> setText("You can change answers to questions after clicking Next.");

		// lineEdit_SettingBack
		if   (quiz -> getQuizSettingBack() == false) lineEdit_SettingBack -> setText("You cannot return to a previous question after clicking Next.");
		else                                         lineEdit_SettingBack -> setText("You can return to previous questions by clicking Prev.");

		// lineEdit_SettingPointsQuiz
		if   (quiz -> getQuizSettingPointsQuiz() == false) lineEdit_SettingPointsQuiz -> setText("Points achieved is hidden upon completion.");
		else                                               lineEdit_SettingPointsQuiz -> setText("Points achieved is shown upon completion.");

		// lineEdit_SettingPointsQuestion
		if   (quiz -> getQuizSettingPointsQuestion() == false) lineEdit_SettingPointsQuestion -> setText("Points achieved per question is not shown until you submit.");
		else                                                   lineEdit_SettingPointsQuestion -> setText("Points achieved per question is shown immediately.");

		// pushButton_Edit
		pushButton_Edit -> setHidden(false);

		// pushButton_Take
		pushButton_Take -> setHidden(false);
		// Disable pushButton_Take if quiz does not have any questions.
		if (quiz -> getQuizQuestions().size() == 0) pushButton_Take -> setDisabled(true);
		else                                        pushButton_Take -> setDisabled(false);
		if (quiz -> getQuizStatus() >= 1)           pushButton_Take -> setText("View");
		else                                        pushButton_Take -> setText("Take");
	}

	else {
		// pushButton_SaveAs
		pushButton_SaveAs -> setDisabled(true);

		// pushButton_Edit
		pushButton_Edit -> setHidden(true);

		// pushButton_Take
		pushButton_Take -> setHidden(true);
	}

	// lineEdit_PasswordEdit
	if   (quiz -> getQuizPasswordEdit() == "") lineEdit_PasswordEdit -> setHidden(true);
	else                                       lineEdit_PasswordEdit -> setHidden(false);

	// lineEdit_PasswordTake
	if   (quiz -> getQuizPasswordTake() == "") lineEdit_PasswordTake -> setHidden(true);
	else                                       lineEdit_PasswordTake -> setHidden(false);
}
