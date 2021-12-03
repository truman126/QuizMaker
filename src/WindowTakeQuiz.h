/// @file   WindowTakeQuiz.h
/// @author Kenneth McAlinden
/// @date   30 November 2021
/// @brief  Header for WindowTakeQuiz.cpp



#ifndef WINDOWTAKEQUIZ
#define WINDOWTAKEQUIZ

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QPlainTextEdit>
#include <QTableWidget>
#include <QHeaderView>
#include <QPushButton>
#include <QListWidget>
#include <QListWidgetItem>
#include <QDate>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
#include <QString>
#include <vector>

#include "Quiz.h"
#include "QWidget_Answer.h"



namespace UI { class WindowTakeQuiz; }



class WindowQuiz; // Forward declaration.



/// @class   WindowTakeQuiz
/// @author  Kenneth McAlinden
/// @brief   WindowTakeQuiz class
/// @details The WindowTakeQuiz class is used to take a quiz
class WindowTakeQuiz : public QMainWindow {
	Q_OBJECT

	private:
		QLineEdit             *lineEdit_Number;
		QLineEdit             *lineEdit_Title;
		QPlainTextEdit        *plainTextEdit_Description;
		QLabel                *label_TimeLimit;
		QLineEdit             *lineEdit_TimeLimit;
		QLabel                *label_TimeUsed;
		QLineEdit             *lineEdit_TimeUsed;
		QLabel                *label_Points;
		QLineEdit             *lineEdit_Points;
		QTableWidget          *tableWidget_Questions;
		QPushButton           *pushButton_Jump;
		QPushButton           *pushButton_Previous;
		QPushButton           *pushButton_Next;
		QListWidget           *listWidget_QWidget_Answers;
		QListWidgetItem       *item;
		QMessageBox            messageBox;
		WindowQuiz            *windowQuiz;
		Quiz                  *quiz;
		Quiz                  *quizTemp;
		Question               question;
		Answer                *answer;
		std::vector<Question>  quizQuestions;
		std::vector<Answer>    questionAnswers;
		std::string            quizTimeLimit;
		int                    questionIndex;
		int                    quizTimeUsedhh;
		int                    quizTimeUsedmm;
		int                    quizTimeUsedss;
		QTime                  time_TimeUsed;
		std::string            quizTimeUsed;

	private slots:
		void buildAnswerLists();
		void jumpToQuestion();
		void selectionChanged();
		void previousQuestion();
		void nextQuestion();
		void submitQuiz();
		void calculateQuizStatus();
		void updateWindow(int button);
		void updateQuiz();
		void updateTableWidget_Questions();
		void updateLineEdit_TimeUsed();

	public:
		explicit WindowTakeQuiz(Quiz *quiz = new Quiz(), Quiz *quizTemp = new Quiz(), QWidget *parent = nullptr);
		~WindowTakeQuiz();

	signals:
		void switchWindow();
};



#endif
