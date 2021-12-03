/// @file   WindowEditQuiz.h
/// @author Kenneth McAlinden
/// @date   30 November 2021
/// @brief  Header for WindowEditQuiz.cpp



#ifndef WINDOWEDITQUIZ
#define WINDOWEDITQUIZ

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QTime>
#include <QMessageBox>
#include <QStringList>
#include <QString>
#include <string>
#include <vector>

#include "WindowEditQuestion.h"
#include "Quiz.h"
#include "Question.h"
#include "QuizFile.h"



namespace UI { class WindowEditQuiz; }



class WindowQuiz; // Forward declaration.



/// @class   WindowEditQuiz
/// @author  Kenneth McAlinden
/// @brief   WindowEditQuiz Class
/// @details The WindowEditQuiz class is used when editing a quiz object
class WindowEditQuiz : public QMainWindow {
	Q_OBJECT

	private:
		QLabel                *label_Title;
		QLineEdit             *lineEdit_Title;
		QLabel                *label_Maker;
		QLineEdit             *lineEdit_Maker;
		QLabel                *label_Taker;
		QLineEdit             *lineEdit_Taker;
		QPlainTextEdit        *plainTextEdit_Description;
		QLabel                *label_TimeLimit;
		QLineEdit             *lineEdit_TimeLimit;
		QLabel                *label_PasswordEdit;
		QLineEdit             *lineEdit_PasswordEdit;
		QLabel                *label_PasswordTake;
		QLineEdit             *lineEdit_PasswordTake;
		QCheckBox             *checkBox_SettingRandom;
		QCheckBox             *checkBox_SettingJump;
		QCheckBox             *checkBox_SettingChange;
		QCheckBox             *checkBox_SettingBack;
		QCheckBox             *checkBox_SettingPointsQuiz;
		QCheckBox             *checkBox_SettingPointsQuestion;
		QPushButton           *pushButton_Add;
		QPushButton           *pushButton_Delete;
		QPushButton           *pushButton_Edit;
		QTableWidget          *tableWidget_Questions;
		QPushButton           *pushButton_Cancel;
		QPushButton           *pushButton_Ok;
		QMessageBox            messageBox;
		WindowQuiz            *windowQuiz;
		WindowEditQuestion    *windowEditQuestion;
		Quiz                  *quiz;
		Quiz                  *quizTemp;
		Quiz                  *oldQuiz;
		QString				  *quizFileName;
		QuizFile			  *quizFile;
		std::vector<Question>  quizQuestions;
		std::vector<Question>  quizQuestionsTemp;
		std::string            quizPoints;
		static bool            compareQuestions(Question question1, Question question2);

	private slots:
		void addQuestion();
		void deleteQuestion();
		void editQuestion();
		void cancel();
		void ok();
		void selectionChanged();
		bool isNumber(const std::string& quizTimeLimitInput);
		void buildTableWidget_Questions();
		void setQuizAttributes();

	public:
		explicit WindowEditQuiz(Quiz *quiz = new Quiz(), Quiz *quizTemp = new Quiz(), QWidget *parent = nullptr);
		~WindowEditQuiz();

	signals:
		void switchWindow();
};



#endif
