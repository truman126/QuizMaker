/// @file   Quiz.h
/// @author Navjeeven Mann
/// @date   30 November 2021
/// @brief  Header for Quiz.cpp



#ifndef QUIZ
#define QUIZ

#include <string>
#include <vector>
#include <random>
#include <algorithm>

#include "Question.h"




/// @class   Quiz
/// @author  Navjeeven Mann
/// @brief   Quiz Object
/// @details Quiz object used in the program
class Quiz {
	private:
		std::string           quizFile;
		std::string           quizTitle;
		std::string           quizMaker;
		std::string           quizTaker;
		std::string           quizDescription;
		float                 quizPointsCorrect;
		float                 quizPointsTotal;
		int                   quizStatus;
		std::string           quizDate;
		std::string           quizTime;
		std::string           quizTimeLimit;
		std::string           quizTimeUsed;
		bool                  quizSettingRandomQuestion;
		bool                  quizSettingJump;
		bool                  quizSettingChange;
		bool                  quizSettingBack;
		bool                  quizSettingPointsQuiz;
		bool                  quizSettingPointsQuestion;
		std::string           quizPasswordEdit;
		std::string           quizPasswordTake;
		std::vector<Question> quizQuestions;
	public:
		Quiz();
		Quiz(std::string quizFile, std::string quizTitle, std::string quizMaker, std::string quizTaker, std::string quizDescription, float quizPointsCorrect, float quizPointsTotal, int quizStatus, std::string quizDate, std::string quizTime, std::string quizTimeLimit, std::string quizTimeUsed, bool quizSettingRandomQuestion, bool quizSettingJump, bool quizSettingChange, bool quizSettingBack, bool quizSettingPointsQuiz, bool quizSettingPointsQuestion, std::string quizPasswordEdit, std::string quizPasswordTake, std::vector<Question> quizQuestions);
		~Quiz();
		std::string           getQuizFile();
		std::string           getQuizTitle();
		std::string           getQuizMaker();
		std::string           getQuizTaker();
		std::string           getQuizDescription();
		float                 getQuizPointsCorrect();
		float                 getQuizPointsTotal();
		int                   getQuizStatus();
		std::string           getQuizDate();
		std::string           getQuizTime();
		std::string           getQuizTimeLimit();
		std::string           getQuizTimeUsed();
		bool                  getQuizSettingRandomQuestion();
		bool                  getQuizSettingJump();
		bool                  getQuizSettingChange();
		bool                  getQuizSettingBack();
		bool                  getQuizSettingPointsQuiz();
		bool                  getQuizSettingPointsQuestion();
		std::string           getQuizPasswordEdit();
		std::string           getQuizPasswordTake();
		std::vector<Question> getQuizQuestions();
		void                  setQuizFile(std::string quizFile);
		void                  setQuizTitle(std::string quizTitle);
		void                  setQuizMaker(std::string quizMaker);
		void                  setQuizTaker(std::string quizTaker);
		void                  setQuizDescription(std::string quizDescription);
		void                  setQuizPointsCorrect(float quizPointsCorrect);
		void                  setQuizPointsTotal(float quizPointsTotal);
		void                  setQuizStatus(int quizStatus);
		void                  setQuizDate(std::string quizDate);
		void                  setQuizTime(std::string quizTime);
		void                  setQuizTimeLimit(std::string quizTimeLimit);
		void                  setQuizTimeUsed(std::string quizTimeUsed);
		void                  setQuizSettingRandomQuestion(bool quizSettingRandomQuestion);
		void                  setQuizSettingJump(bool quizSettingJump);
		void                  setQuizSettingChange(bool quizSettingChange);
		void                  setQuizSettingBack(bool quizSettingBack);
		void                  setQuizSettingPointsQuiz(bool quizSettingPointsQuiz);
		void                  setQuizSettingPointsQuestion(bool quizSettingPointsQuestion);
		void                  setQuizPasswordEdit(std::string quizPasswordEdit);
		void                  setQuizPasswordTake(std::string quizPasswordTake);
		void                  setQuizQuestions(std::vector<Question> quizQuestions);
		void                  addQuestion(Question question);
};



#endif
