/// @file   WindowQuiz.h
/// @author Kenneth McAlinden
/// @date   30 November 2021
/// @brief  Header for WindowQuiz.cpp



#ifndef WINDOWQUIZ
#define WINDOWQUIZ

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <QStringView>

#include "WindowEditQuiz.h"
#include "WindowTakeQuizTaker.h"
#include "WindowTakeQuiz.h"
#include "Quiz.h"
#include "QuizFile.h"



namespace UI { class MainWindow; }



/// @class   WindowQuiz
/// @author  Kenneth McAlinden
/// @brief   WindowQuiz Class
/// @details The WindowQuiz class is used to present and save quiz objects and also start quizzes
class WindowQuiz : public QMainWindow {
	Q_OBJECT

	private:
		QPushButton         *pushButton_New;
		QPushButton         *pushButton_Open;
		QPushButton         *pushButton_SaveAs;
		QLabel              *label_File;
		QLineEdit           *lineEdit_File;
		QLabel              *label_Title;
		QLineEdit           *lineEdit_Title;
		QLabel              *label_Maker;
		QLineEdit           *lineEdit_Maker;
		QLabel              *label_Taker;
		QLineEdit           *lineEdit_Taker;
		QPlainTextEdit      *plainTextEdit_Description;
		QLabel              *label_Points;
		QLineEdit           *lineEdit_Points;
		QLabel              *label_Status;
		QLineEdit           *lineEdit_Status;
		QLabel              *label_Date;
		QLineEdit           *lineEdit_Date;
		QLabel              *label_Time;
		QLineEdit           *lineEdit_Time;
		QLabel              *label_TimeLimit;
		QLineEdit           *lineEdit_TimeLimit;
		QLabel              *label_TimeUsed;
		QLineEdit           *lineEdit_TimeUsed;
		QLineEdit           *lineEdit_SettingRandomQuestion;
		QLineEdit           *lineEdit_SettingJump;
		QLineEdit           *lineEdit_SettingChange;
		QLineEdit           *lineEdit_SettingBack;
		QLineEdit           *lineEdit_SettingPointsQuiz;
		QLineEdit           *lineEdit_SettingPointsQuestion;
		QLineEdit           *lineEdit_PasswordEdit;
		QPushButton         *pushButton_Edit;
		QLineEdit           *lineEdit_PasswordTake;
		QPushButton         *pushButton_Take;
		QMessageBox          messageBox;
		WindowEditQuiz      *windowEditQuiz;
		WindowTakeQuizTaker *windowTakeQuizTaker;
		WindowTakeQuiz      *windowTakeQuiz;
		Quiz  				*quiz;
		QuizFile 		    *quizFile;

	private slots:
		void newQuiz();
		void openQuiz();
		void saveAsQuiz();
		void editQuiz();
		void takeQuiz();
		void updateWindow();

	public:
		explicit WindowQuiz(Quiz *quiz = new Quiz(), QWidget *parent = nullptr);
		~WindowQuiz();

	signals:
		void switchWindow();
};



#endif
