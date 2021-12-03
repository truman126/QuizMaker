/// @file   WindowEditQuestion.h
/// @author Kenneth McAlinden
/// @date   30 November 2021
/// @brief  Header for WindowEditQuestion.cpp



#ifndef WINDOWEDITQUESTION
#define WINDOWEDITQUESTION

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QMessageBox>
#include <QString>
#include <string>
#include <algorithm>
#include <vector>

#include "WindowEditAnswer.h"
#include "Quiz.h"
#include "Question.h"



namespace UI { class WindowEditQuestion; }



class WindowEditQuiz; // Forward declaration.



/// @class   WindowEditQuestion
/// @author  Kenneth McAlinden
/// @brief   Edit Question Widget Class
/// @details The Edit Question Widget class used to edit a question
class WindowEditQuestion : public QMainWindow {
	Q_OBJECT

	private:
		QLabel                *label_Number;
		QLineEdit             *lineEdit_Number;
		QLabel                *label_Title;
		QLineEdit             *lineEdit_Title;
		QCheckBox             *checkBox_SettingRandomAnswer;
		QPlainTextEdit        *plainTextEdit_Description;
		QPushButton           *pushButton_AddAnswer;
		QPushButton           *pushButton_DeleteAnswer;
		QPushButton           *pushButton_EditAnswer;
		QTableWidget          *tableWidget_Answers;
		QPushButton           *pushButton_Cancel;
		QPushButton           *pushButton_Ok;
		QMessageBox            messageBox;
		WindowEditQuiz        *windowEditQuiz;
		WindowEditAnswer      *windowEditAnswer;
		Quiz                  *quiz;
		Quiz                  *quizTemp;
		Quiz                  *quizTempTemp;
		Question              *question;
		Question              *questionTemp;
		std::vector<Question>  quizQuestions;
		std::vector<Answer>    questionAnswersTemp;
		std::string            questionPoints;
		static bool            compareAnswers(Answer answer1, Answer answer2);

	private slots:
		void addAnswer();
		void deleteAnswer();
		void editAnswer();
		void cancel();
		void ok();
		void selectionChanged();

	public:
		explicit WindowEditQuestion(Quiz *quiz = new Quiz(), Quiz *quizTemp = new Quiz(), Quiz *quizTempTemp = new Quiz(), Question *question = new Question(), QWidget *parent = nullptr);
		~WindowEditQuestion();

	signals:
		void switchWindow();
};



#endif
