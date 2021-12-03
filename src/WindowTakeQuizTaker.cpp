/// @file   WindowTakeQuizTaker.cpp
/// @author Kenneth McAlinden
/// @author Roy Zhu
/// @date   30 November 2021
/// @brief  WindowTakeQuizTaker class used to enter taker name



#include "WindowTakeQuizTaker.h"
#include "WindowQuiz.h"



/// @brief   Constructor.
/// @details Constructor for the WindowTakeQuizTaker class
/// @param   *parent: Qwidget pointer that points to the main window
/// @param   *quiz: Quiz pointer that points to the quiz object
/// @param   *quizTemp: Quiz pointer that points to a temp quiz
WindowTakeQuizTaker::WindowTakeQuizTaker(Quiz *quiz, Quiz *quizTemp, QWidget *parent) : QMainWindow(parent) {
	this -> setFixedSize(960, 624);
	this -> setWindowTitle("Quiz Maker: Enter Name");

	this -> quiz     = quiz;
	this -> quizTemp = quizTemp;

	// label_Taker
	label_Taker = new QLabel("Taker", this);
	label_Taker -> setGeometry(QRect(QPoint(256, 304), QSize(64, 16)));

	// lineEdit_Taker
	lineEdit_Taker = new QLineEdit(this);
	lineEdit_Taker -> setPlaceholderText("enter your name...");
	lineEdit_Taker -> setGeometry(QRect(QPoint(320, 296), QSize(384, 32)));

	// pushButton_Cancel
	pushButton_Cancel = new QPushButton("Cancel", this);
	pushButton_Cancel -> setGeometry(QRect(QPoint(16, 576), QSize(448, 32)));
	connect(pushButton_Cancel, &QPushButton::released, this, &WindowTakeQuizTaker::cancel);

	// pushButton_Start
	pushButton_Start = new QPushButton("Start", this);
	pushButton_Start -> setGeometry(QRect(QPoint(496, 576), QSize(448, 32)));
	//pushButton_Start -> setDisabled(true);
	connect(pushButton_Start, &QPushButton::released, this, &WindowTakeQuizTaker::startQuiz);
}



/// @brief   Destructor.
/// @details Desconstructor for the WindowTakeQuizTaker class
WindowTakeQuizTaker::~WindowTakeQuizTaker() {};




/// @brief Cancel Method for the WindowTakeQuizTaker class
/// @details Cancel Method for the WindowTakeQuizTaker class which presents the WindowQuiz window
void WindowTakeQuizTaker::cancel() {
	// Switch window.
	windowQuiz = new WindowQuiz(quiz);

	connect(windowQuiz, &WindowQuiz::switchWindow, this, &WindowQuiz::show);

	this       -> close();
	windowQuiz -> show();
}



/// @brief Method to start a quiz
/// @details Method to start a quiz, save taker, and present the WindowTakeQuiz window
void WindowTakeQuizTaker::startQuiz() {
	quizTemp -> setQuizTaker(lineEdit_Taker -> text().toStdString());

	// Switch window.
	windowTakeQuiz = new WindowTakeQuiz(quiz, quizTemp);

	connect(windowTakeQuiz, &WindowTakeQuiz::switchWindow, this, &WindowTakeQuiz::show);

	this           -> close();
	windowTakeQuiz -> show();
}
