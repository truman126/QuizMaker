/// @file   Answer.h
/// @author Truman Johnston
/// @date   30 November 2021
/// @brief  Header for Answer.cpp



#ifndef ANSWER
#define ANSWER

#include <string>



/// @class   Answer
/// @author  Truman Johnston
/// @brief   Answer Object
/// @details Answer object which is owned by Question object
class Answer {
	private:
		char        answerLetter;
		int         answerType;
		std::string answerText;
		std::string answerInput;
		std::string answerCorrect;
		std::string answerFeedback;
		float       answerPoints;
		int         answerStatus;

	public:
		Answer();
		Answer(char answerLetter, int answerType, std::string answerText, std::string answerInput, std::string answerCorrect, std::string answerFeedback, float answerPoints, int answerStatus);
		~Answer();
		char        getAnswerLetter();
		int         getAnswerType();
		std::string getAnswerText();
		std::string getAnswerInput();
		std::string getAnswerCorrect();
		std::string getAnswerFeedback();
		float       getAnswerPoints();
		int         getAnswerStatus();
		void        setAnswerLetter(char answerLetter);
		void        setAnswerType(int answerType);
		void        setAnswerText(std::string answerText);
		void        setAnswerInput(std::string answerInput);
		void        setAnswerCorrect(std::string answerCorrect);
		void        setAnswerFeedback(std::string answerFeedback);
		void        setAnswerPoints(float answerPoints);
		void        setAnswerStatus(int answerStatus);
};



#endif
