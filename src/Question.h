/// @file   Question.h
/// @author Jason Chan
/// @date   30 November 2021
/// @brief  Header for Question.cpp



#ifndef QUESTION
#define QUESTION

#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>

#include "Answer.h"



/// @class   Question
/// @author  Jason Chan
/// @brief   Question Object
/// @details Question object which is owned by the Quiz Object
class Question {
	private:
		float               questionNumber;
		std::string         questionTitle;
		bool                questionSettingRandomAnswer;
		std::string         questionDescription;
		std::vector<Answer> questionAnswers;
		float               questionPointsTotal;
		float               questionPointsCorrect;
		int                 questionStatus;

	public:
		Question();
		Question(float questionNumber, std::string questionTitle, bool questionSettingRandomAnswer, std::string questionDescription, std::vector<Answer> questionAnswers, float questionPointsTotal, float questionPointsCorrect, int questionStatus);
		~Question();
		float               getQuestionNumber();
		std::string         getQuestionTitle();
		bool                getQuestionSettingRandomAnswer();
		std::string         getQuestionDescription();
		std::vector<Answer> getQuestionAnswers();
		float               getQuestionPointsTotal();
		float               getQuestionPointsCorrect();
		int                 getQuestionStatus();
		void                setQuestionNumber(float questionNumber);
		void                setQuestionTitle(std::string questionTitle);
		void                setQuestionSettingRandomAnswer(bool questionSettingRandomAnswer);
		void                setQuestionDescription(std::string questionDescription);
		void                setQuestionAnswers(std::vector<Answer> questionAnswers);
		void                setQuestionPointsTotal(float questionPointsTotal);
		void                setQuestionPointsCorrect(float questionPointsCorrect);
		void                setQuestionStatus(int questionStatus);
};



#endif
