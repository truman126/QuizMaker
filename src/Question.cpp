/// @file   Question.cpp
/// @author Jason Chan
/// @date   30 November 2021
/// @brief  Class for Question objects



#include "Question.h"



using namespace std;



/// @brief   Empty Constructor.
/// @details Empty Constructor that set's default values
Question::Question() {
    this -> questionNumber              = 0;
    this -> questionTitle               = "";
    this -> questionSettingRandomAnswer = false;
    this -> questionDescription         = "";
    this -> questionAnswers             = {};
    this -> questionPointsTotal         = 0;
    this -> questionPointsCorrect       = 0;
    this -> questionStatus              = 0;
}



/// @brief   Constructor
/// @details Constructor that initializes variables with parameter values
/// @param questionNumber: float for the question number
/// @param questionTitle: string for the question title
/// @param questionSettingRandomAnswer: bool for whether answer's are random
/// @param questionDescription: string for the question description
/// @param questionAnswers: vector that contains the question's answer objects
/// @param questionPointsTotal: float for the question's total points
/// @param questionPointsCorrect: float for the question's correct points
/// @param questionStatus: int for the question's current status
Question::Question(float questionNumber, string questionTitle,  bool questionSettingRandomAnswer, string questionDescription, vector<Answer> questionAnswers, float questionPointsTotal, float questionPointsCorrect, int questionStatus) {
    this -> questionNumber              = questionNumber;
    this -> questionTitle               = questionTitle;
    this -> questionSettingRandomAnswer = questionSettingRandomAnswer;
    this -> questionDescription         = questionDescription;
    this -> questionAnswers             = questionAnswers;
    this -> questionPointsTotal         = questionPointsTotal;
    this -> questionPointsCorrect       = questionPointsCorrect;
    this -> questionStatus              = questionStatus;
}



/// @brief   Destructor.
/// @details Desconstructor for Question Object
Question::~Question() {};



/// @brief   Get Method for Question Number
/// @details Getter for the Question number
/// @return  questionNumber: float for the question number
float Question::getQuestionNumber() {
    return this -> questionNumber;

}



/// @brief   Get Method for Question Title
/// @details Getter for the Question title
/// @return  questionTitle: string for the question's title
string Question::getQuestionTitle() {
    return questionTitle;
}



/// @brief   Get Method for Question Random Answer Flag
/// @details Getter for the Question Random Answer Flag, which determines if the question's answers are randomized
/// @return  questionSettingRandomAnswer: bool for the questionSettingRandomAnswer flag
bool Question::getQuestionSettingRandomAnswer() {
    return questionSettingRandomAnswer;
}



/// @brief   Get Method for Question Description
/// @details Getter for the Question Description
/// @return  questionDescription: string for the question description
string Question::getQuestionDescription() {
    return questionDescription;
}



/// @brief   Get Method for Question Answer's
/// @details Getter for the Question's Answer vector, which is randomized if questionSettingRandomAnswer is set to true
/// @return  questionAnswersRandom: vector of randomized answers
/// @return  questionAnswers: vector of answers unrandomized
vector<Answer> Question::getQuestionAnswers() {

  // Check if answers should be randomized
	if (this -> questionSettingRandomAnswer) {


		vector<Answer> questionAnswersRandom; ///< Random Answer Vector

    // copy the questionAnswers to questionAnswersRandom
		questionAnswersRandom = questionAnswers;

    // Shuffle questionAnswersRandom
		random_device rd;
		mt19937 g(rd());
		random_shuffle(questionAnswersRandom.begin(), questionAnswersRandom.end());
		shuffle(questionAnswersRandom.begin(), questionAnswersRandom.end(), g);

		return questionAnswersRandom;
	}

    return questionAnswers;
}



/// @brief   Get Method for Question Total Points
/// @details Getter for the Question Total Points from all it's answer's
/// @return  questionPointsTotal: float for the question's total points
float Question::getQuestionPointsTotal() {
    return questionPointsTotal;
}



/// @brief   Get Method for Question Correct Points
/// @details Getter for the Question correct points
/// @return  questionPointsCorrect: float for the question's total correct points
float Question::getQuestionPointsCorrect() {
    return questionPointsCorrect;
}




/// @brief   Get Method for Question Status
/// @details Getter for the Question status
/// @return  questionStatus: int for the question's current status
int Question::getQuestionStatus() {
    return questionStatus;
}



/// @brief   Set Method for the Question Number
/// @details Setter for the Question's number
/// @param  questionNumber: float for the question number
void Question::setQuestionNumber(float questionNumber) {
    this -> questionNumber = questionNumber;
}



/// @brief   Set Method for the Question Title
/// @details Setter for the Question's title
/// @param  questionTitle: string for the question title
void Question::setQuestionTitle(string questionTitle) {
    this -> questionTitle = questionTitle;
}



/// @brief   Set Method for the Question Random Answer Bool
/// @details Setter for the Question's Random Answer Flag
/// @param  questionSettingRandomAnswer: bool for the question random answer flag

void Question::setQuestionSettingRandomAnswer(bool questionSettingRandomAnswer) {
	this -> questionSettingRandomAnswer = questionSettingRandomAnswer;
}



/// @brief   Set Method for the Question Description
/// @details Setter for the Question's Description
/// @param  questionDescription: string for the question description
void Question::setQuestionDescription(string questionDescription) {
    this -> questionDescription = questionDescription;
}



/// @brief   Set Method for the Question Answer's
/// @details Setter for the Question's answer's
/// @param  questionAnswers: vector for the question's answers
void Question::setQuestionAnswers(vector<Answer> questionAnswers) {
    this-> questionAnswers = questionAnswers;
}



/// @brief   Set Method for the Question Total Points
/// @details Setter for the Question's Total Points
/// @param  questionPointsTotal: float for the question's total points
void Question::setQuestionPointsTotal(float questionPointsTotal) {
    this -> questionPointsTotal = questionPointsTotal;
}



/// @brief   Set Method for the Question Correct Points
/// @details Setter for the Question's correct points
/// @param  questionPointsCorrect: float for the question's correct points
void Question::setQuestionPointsCorrect(float questionPointsCorrect) {
    this -> questionPointsCorrect = questionPointsCorrect;
}



/// @brief   Set Method for the Question Status
/// @details Setter for the Question's status
/// @param  questionStatus: int for the question status
void Question::setQuestionStatus(int questionStatus) {
    this -> questionStatus = questionStatus;
}
