/// @file   QuizFile.h
/// @author Truman Johnston
/// @date   30 November 2021
/// @brief  Header for QuizFile.cpp



#ifndef QUIZFILE
#define QUIZFILE

#include <QString>
#include <QChar>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Quiz.h"
#include "Question.h"
#include "Answer.h"
#include "Codec.h"

using namespace std;

/// @class   QuizFile
/// @author  Truman Johnston
/// @brief   QuizFile Class used to read/write Quiz Files
/// @details The QuizFile class is used to write a quiz object to the file system and also read a file into a quiz object
class QuizFile {
	private:
		Quiz       			  *quizTemp;
		QFile       		  *file;
		QString      		   saveFilename;
		QString      		   openFilename;
		std::string			   multiLineString;
		std::string			   currentLine;
		std::string			   endOfString;
		QTextStream  		   in;
		QTextStream  		   out;
		std::vector<Answer>    answers;
		std::vector<Question>  questions;
		Question 			  *question;
		Answer 				   answer;
		int 				   numQuestions;
		int 				   numAnswers;
		Codec   			   *codec;

	public:
		explicit QuizFile(Quiz *quizTemp = new Quiz());
		~QuizFile();
		void readFile(QString);
		void writeFile(QString);
};



#endif
