/// @file   WindowTakeQuizTaker.h
/// @author Kenneth McAlinden
/// @date   30 November 2021
/// @brief  Header for WindowTakeQuizTaker.cpp



#ifndef WINDOWTAKEQUIZTAKER
#define WINDOWTAKEQUIZTAKER

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "WindowTakeQuiz.h"
#include "Quiz.h"



namespace UI { class WindowTakeQuizTaker; }



class WindowQuiz; // Forward declaration.



/// @class   WindowTakeQuizTaker
/// @author  Kenneth McAlinden
/// @brief   WindowTakeQuizTaker class
/// @details The WindowTakeQuizTaker class is used to set a taker for the quiz
class WindowTakeQuizTaker : public QMainWindow {
	Q_OBJECT

	private:
		QLabel         *label_Taker;
		QLineEdit      *lineEdit_Taker;
		QPushButton    *pushButton_Cancel;
		QPushButton    *pushButton_Start;
		WindowQuiz     *windowQuiz;
		WindowTakeQuiz *windowTakeQuiz;
		Quiz           *quiz;
		Quiz           *quizTemp;

	private slots:
		void cancel();
		void startQuiz();

	public:
		explicit WindowTakeQuizTaker(Quiz *quiz = new Quiz(), Quiz *quizTemp = new Quiz(), QWidget *parent = nullptr);
		~WindowTakeQuizTaker();

	signals:
		void switchWindow();
};



#endif
