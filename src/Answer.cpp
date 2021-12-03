/// @file   Answer.cpp
/// @author Truman Johnston
/// @date   30 November 2021
/// @brief  This class contains the code for the Answer object.



#include "Answer.h"



using namespace std;



/// @brief Empty Constructor
/// @details Empty Constructor for Answer object that set's default values
Answer::Answer() {
    answerLetter   = '?';
    answerType     = 0;
    answerText     = "";
    answerInput    = "";
    answerCorrect  = "";
    answerFeedback = "";
    answerPoints   = 0;
    answerStatus   = 0;
}



/// @brief  Constructor
/// @details Constructor for Answer object that set's parameter values to variables
/// @param answerLetter: char for the answer letter
/// @param answerType: int for the type of answer
/// @param answerText: string for the answer text
/// @param answerInput: string for the answer input
/// @param answerCorrect: string for the correct answer
/// @param answerFeedback: feedback for the given answer
/// @param answerPoints: float for the answer points
/// @param answerStatus: int for the answer status, input given or not
Answer::Answer(char answerLetter, int answerType, string answerText, string answerInput, string answerCorrect, string answerFeedback, float answerPoints, int answerStatus) {
	this -> answerLetter   = answerLetter;
	this -> answerType     = answerType;
	this -> answerText     = answerText;
	this -> answerInput    = answerInput;
	this -> answerCorrect  = answerCorrect;
	this -> answerFeedback = answerFeedback;
	this -> answerPoints   = answerPoints;
	this -> answerStatus   = answerStatus;
}



/// @brief   Destructor.
/// @details Deconstructor for the Answer class
Answer::~Answer() {};



/// @brief   Get Method for Answer Letter
/// @details Getter for the answer letter
/// @return  answerLetter: char for the answer's letter
char Answer::getAnswerLetter() {
    return answerLetter;
}



/// @brief   Get Method for Answer Type
/// @details Getter for the answer type
/// @return  answerType: int for the answer type
int Answer::getAnswerType() {
    return answerType;
}



/// @brief   Get Method for Answer Text
/// @details Getter for the answer text
/// @return  answerText: string for the answer text
string Answer::getAnswerText() {
    return answerText;
}



/// @brief   Get Method for Answer Input
/// @details Getter for the answer input
/// @return  answerInput: string for the answer input
string Answer::getAnswerInput() {
    return answerInput;
}



/// @brief   Get Method for correct Answer
/// @details Getter for the correct answer
/// @return  answerCorrect: string for the correct answer
string Answer::getAnswerCorrect() {
    return answerCorrect;
}



/// @brief   Get Method for Answer's Feedback
/// @details Getter for the answer's feedback
/// @return  answerFeedback: string for the answer's feedback
string Answer::getAnswerFeedback() {
    return answerFeedback;
}



/// @brief   Get Method for Answer Points
/// @details Getter for the answer points
/// @return  answerPoints: float for the answer's points
float Answer::getAnswerPoints() {
    return answerPoints;
}



/// @brief   Get Method for Answer Status
/// @details Getter for the answer status
/// @return  answerStatus: int for the answer's status
int Answer::getAnswerStatus() {
    return answerStatus;
}



/// @brief   Set Method for the Answer Letter
/// @details Setter for the answer letter
/// @param   answerLetter: char for the answer letter
void Answer::setAnswerLetter(char answerLetter) {
    this -> answerLetter = answerLetter;
}



/// @brief   Set Method for the Answer Type
/// @details Setter for the answer type
/// @param   answerType: int for the answer type
void Answer::setAnswerType(int answerType) {
    this -> answerType = answerType;
}



/// @brief   Set Method for the Answer Text
/// @details Setter for the answer text
/// @param   answerText: string for the answer text
void Answer::setAnswerText(string answerText) {
    this -> answerText = answerText;
}



/// @brief   Set Method for the Answer Input
/// @details Setter for the answer input
/// @param   answerInput: string for the answer input
void Answer::setAnswerInput(string answerInput) {
    this -> answerInput = answerInput;
}



/// @brief   Set Method for the Correct Answer
/// @details Setter for the correct answer
/// @param   answerCorrect: string for the correct answer
void Answer::setAnswerCorrect(string answerCorrect) {
    this -> answerCorrect = answerCorrect;
}



/// @brief   Set Method for the Answer Feedback
/// @details Setter for the answer feedback
/// @param   answerFeedback: string for the answer feedback
void Answer::setAnswerFeedback(string answerFeedback) {
    this -> answerFeedback = answerFeedback;
}



/// @brief   Set Method for the Answer Points
/// @details Setter for the answer points
/// @param   answerPoints: float for the answer points
void Answer::setAnswerPoints(float answerPoints) {
    this -> answerPoints = answerPoints;
}



/// @brief   Set Method for the Answer Status
/// @details Setter for the answer status
/// @param   answerStatus: int for the answer status
void Answer::setAnswerStatus(int answerStatus) {
    this -> answerStatus = answerStatus;
}
