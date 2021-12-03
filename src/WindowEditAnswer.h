/// @file   WindowEditAnswer.h
/// @author Kenneth McAlinden
/// @date   30 November 2021
/// @brief  Header for WindowEditAnswer.cpp



#ifndef WINDOWEDITANSWER
#define WINDOWEDITANSWER

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QMessageBox>
#include <vector>

#include "Quiz.h"
#include "Question.h"
#include "Answer.h"



namespace UI { class WindowEditAnswer; }



class WindowEditQuestion; // Forward declaration.



/// @class   WindowEditAnswer
/// @author  Kenneth McAlinden
/// @brief   Edit Answer Widget Class
/// @details The Edit Answer Widget class used to edit an answer
class WindowEditAnswer : public QMainWindow {
	Q_OBJECT

	private:
		QLabel                *label_Letter;
		QLineEdit             *lineEdit_Letter;
		QLabel                *label_Points;
		QLineEdit             *lineEdit_Points;
		QRadioButton          *radioButton_AnswerTypeTF;
		QRadioButton          *radioButton_AnswerTypeMC;
		QRadioButton          *radioButton_AnswerTypeWA;
		QPlainTextEdit        *plainTextEdit_Text;
		QLabel                *label_Input;
		QLineEdit             *lineEdit_Input;
		QLabel                *label_Correct;
		QLineEdit             *lineEdit_Correct;
		QPlainTextEdit        *plainTextEdit_Feedback;
		QPushButton           *pushButton_Cancel;
		QPushButton           *pushButton_Ok;
		QMessageBox            messageBox;
		WindowEditQuestion    *windowEditQuestion;
		Quiz                  *quiz;
		Quiz                  *quizTemp;
		Quiz                  *quizTempTemp;
		Quiz                  *quizTempTempTemp;
		Question              *question;
		Question              *questionTemp;
		Answer                *answer;
		std::vector<Question>  quizQuestionsTemp;
		std::vector<Answer>    questionAnswersTemp;

	private slots:
		void cancel();
		void ok();
		bool isNumber(const std::string& answerPointsInput);

	public:
		explicit WindowEditAnswer(Quiz *quiz = new Quiz(), Quiz *quizTemp = new Quiz(), Quiz *quizTempTemp = new Quiz(), Quiz *quizTempTempTemp = new Quiz(), Question *question = new Question(), Question *questionTemp = new Question(), Answer *answer = new Answer(), QWidget *parent = nullptr);
		~WindowEditAnswer();

	signals:
		void switchWindow();
};



#endif
