/// @file   QWidget_Answer.h
/// @author Kenneth McAlinden
/// @date   30 November 2021
/// @brief  Header for QWidget_Answer.cpp



#ifndef QWIDGET_ANSWER
#define QWIDGET_ANSWER

#include <QWidget>
#include <QLabel>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QCheckBox>
#include <QRadioButton>
#include <string>

#include "Answer.h"
#include "WindowTakeQuiz.h"



namespace UI { class WindowTakeQuiz; }



/// @class   QWidget_Answer
/// @author  Kenneth McAlinden
/// @brief   Answer Widget Class
/// @details The Answer Widget class used to create the answer view
class QWidget_Answer : public QWidget {
	Q_OBJECT

	private:
		QLineEdit      *lineEdit_Letter;
		QPlainTextEdit *plainTextEdit_Text;
		QRadioButton   *radioButton_InputT;
		QRadioButton   *radioButton_InputF;
		QCheckBox      *checkBox_InputMC;
		QPlainTextEdit *plainTextEdit_InputWA;
		QLineEdit      *lineEdit_Points;
		QPlainTextEdit *plainTextEdit_Feedback;

	public:
		explicit QWidget_Answer(Answer *answer = new Answer(), QWidget *parent = 0);
		~QWidget_Answer();
		int         getQWidget_AnswerInputTF();
		bool        getQWidget_AnswerInputMC();
		std::string getQWidget_AnswerInputWA();
		void        setQWidget_AnswerLetter(char answerLetter);
		void        setQWidget_AnswerText(std::string answerText);
		void        setQWidget_AnswerInputTF(bool answerInputTF);
		void        setQWidget_AnswerInputMC(bool answerInputMC);
		void        setQWidget_AnswerInputWA(std::string answerInputWA);
		void        setQWidget_AnswerPoints(float answerInput, float answerCorrect);
		void        setQWidget_AnswerFeedback(std::string answerFeedback);
		void        disableQObjects(int answerType);
};



#endif
