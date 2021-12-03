/// @file   Quiz.cpp
/// @author Navjeeven Mann
/// @date   30 November 2021
/// @brief  Class for Quiz Objects



#include "Quiz.h"



using namespace std;



/// @brief   Constructor.
/// @details Constructor that initializes the quiz object with default values
Quiz::Quiz() {
	this -> quizFile                  = "";
    this -> quizTitle                 = "";
    this -> quizMaker                 = "";
    this -> quizTaker                 = "";
    this -> quizDescription           = "";
    this -> quizPointsCorrect         = 0;
    this -> quizPointsTotal           = 0;
    this -> quizStatus                = 0;
    this -> quizDate                  = "";
    this -> quizTime                  = "";
    this -> quizTimeLimit             = "";
    this -> quizTimeUsed              = "";
    this -> quizSettingRandomQuestion = false;
    this -> quizSettingJump           = false;
    this -> quizSettingChange         = false;
    this -> quizSettingBack           = false;
    this -> quizSettingPointsQuiz     = false;
    this -> quizSettingPointsQuestion = false;
    this -> quizPasswordEdit          = "";
    this -> quizPasswordTake          = "";
    this -> quizQuestions             = {};
}



/// @brief   Constructor.
/// @details Constructor that initializes Quiz object with given parameters
/// @param quizFile: string for quiz filename
/// @param quizTitle: string for quiz title
/// @param quizMaker: string for quiz maker
/// @param quizTaker: string for quiz taker
/// @param quizDescription: string for quiz description
/// @param quizPointsCorrect: float for quiz correct points
/// @param quizPointsTotal: float for quiz total points
/// @param quizStatus: int for quiz status
/// @param quizDate: string for quiz date
/// @param quizTime: string for quiz time
/// @param quizTimeLimit: string for quiz time limit
/// @param quizTimeUsed: string for quiz time used
/// @param quizSettingRandomQuestion: bool for quiz random question
/// @param quizSettingJump: bool for quiz setting jump to allow jump to question
/// @param quizSettingChange: bool for quiz setting change question
/// @param quizSettingBack: bool for quiz setting back to move backwards
/// @param quizSettingPointsQuiz: bool for quiz points shown on end of quiz
/// @param quizSettingPointsQuestion: bool for quiz points be shown for each question
/// @param quizPasswordEdit: string for quiz edit password
/// @param quizPasswordTake: string for quiz take password
/// @param quizQuestions: vector<Question> for quiz questions
Quiz::Quiz(string quizFile, string quizTitle, string quizMaker, string quizTaker, string quizDescription, float quizPointsCorrect, float quizPointsTotal, int quizStatus, string quizDate, string quizTime, string quizTimeLimit, string quizTimeUsed, bool quizSettingRandomQuestion, bool quizSettingJump, bool quizSettingChange, bool quizSettingBack, bool quizSettingPointsQuiz, bool quizSettingPointsQuestion, string quizPasswordEdit, string quizPasswordTake, vector<Question> quizQuestions) {
	this -> quizFile                  = quizFile;
	this -> quizTitle                 = quizTitle;
	this -> quizMaker                 = quizMaker;
	this -> quizTaker                 = quizTaker;
	this -> quizDescription           = quizDescription;
	this -> quizPointsCorrect         = quizPointsCorrect;
	this -> quizPointsTotal           = quizPointsTotal;
	this -> quizStatus                = quizStatus;
	this -> quizDate                  = quizDate;
	this -> quizTime                  = quizTime;
	this -> quizTimeLimit             = quizTimeLimit;
	this -> quizTimeUsed              = quizTimeUsed;
	this -> quizSettingRandomQuestion = quizSettingRandomQuestion;
	this -> quizSettingJump           = quizSettingJump;
	this -> quizSettingChange         = quizSettingChange;
	this -> quizSettingBack           = quizSettingBack;
	this -> quizSettingPointsQuiz     = quizSettingPointsQuiz;
	this -> quizSettingPointsQuestion = quizSettingPointsQuestion;
	this -> quizPasswordEdit          = quizPasswordEdit;
	this -> quizPasswordTake          = quizPasswordTake;
}



/// @brief   Destructor.
/// @details .
Quiz::~Quiz() {};



/// @brief   Get Method for Quiz Filename
/// @details Getter for the Quiz Filename
/// @return  quizFile: string for the quiz filename
string Quiz::getQuizFile() {
  return this -> quizFile;
}



/// @brief   Get Method for Quiz Title
/// @details Getter for the Quiz Title
/// @return  quizTitle: string for the quiz title
string Quiz::getQuizTitle() {
  return this -> quizTitle;
}



/// @brief   Get Method for Quiz Maker
/// @details Getter for the Quiz Maker
/// @return  quizMaker: string for the quiz maker
string Quiz::getQuizMaker() {
  return this -> quizMaker;
}



/// @brief   Get Method for Quiz Taker
/// @details Getter for the Quiz Taker
/// @return  quizTaker: string for the quiz taker
string Quiz::getQuizTaker() {
  return this -> quizTaker;
}



/// @brief   Get Method for Quiz Description
/// @details Getter for the Quiz Description
/// @return  quizFile: string for the quiz description
string Quiz::getQuizDescription() {
  return this -> quizDescription;
}



/// @brief   Get Method for Quiz Points Correct
/// @details Getter for the Quiz Points Correct
/// @return  quizPointsCorrect: float for the number of correct points for a quiz
float Quiz::getQuizPointsCorrect() {
  return this -> quizPointsCorrect;
}



/// @brief   Get Method for Quiz Points Total
/// @details Getter for the Quiz Points Total
/// @return  quizPointsTotal: float for the quiz' total points
float Quiz::getQuizPointsTotal() {
  return this -> quizPointsTotal;
}



/// @brief   Get Method for Quiz Status
/// @details Getter for the Quiz Status
/// @return  quizStatus: int for the quiz current status
int Quiz::getQuizStatus() {
  return this -> quizStatus;
}



/// @brief   Get Method for Quiz Date
/// @details Getter for the Quiz Date
/// @return  quizDate: string for the quiz date
string Quiz::getQuizDate() {
  return this -> quizDate;
}



/// @brief   Get Method for Quiz Filename
/// @details Getter for the Quiz Filename
/// @return  quizTime: string for the quiz current time
string Quiz::getQuizTime() {
  return this -> quizTime;
}



/// @brief   Get Method for Quiz Time Limit
/// @details Getter for the Quiz Time Limit
/// @return  quizTimeLimit: string for the quiz time limit
string Quiz::getQuizTimeLimit() {
  return this -> quizTimeLimit;
}



/// @brief   Get Method for Quiz Time Used
/// @details Getter for the Quiz Time Used
/// @return  quizTimeUsed: string for the quiz time used already
string Quiz::getQuizTimeUsed() {
  return this -> quizTimeUsed;
}



/// @brief   Get Method for Quiz Random Question
/// @details Getter for the Quiz Random Question Flag which randomizes questions
/// @return  quizSettingRandomQuestion: bool for the quiz random question flag
bool Quiz::getQuizSettingRandomQuestion() {
  return this -> quizSettingRandomQuestion;
}



/// @brief   Get Method for Quiz Jump Setting
/// @details Getter for the Quiz Jump Setting
/// @return  quizSettingJump: bool for the quiz jump setting to jump question to question
bool Quiz::getQuizSettingJump(){
  return this -> quizSettingJump;
}



/// @brief   Get Method for Quiz Setting Change
/// @details Getter for the Quiz Setting Change
/// @return  quizSettingChange: bool for the quiz setting change to allow answer changes
bool Quiz::getQuizSettingChange(){
  return this -> quizSettingChange;
}



/// @brief   Get Method for Quiz Setting Back
/// @details Getter for the Quiz Setting Back
/// @return  quizSettingBack: bool for the quiz setting to move back to a question
bool Quiz::getQuizSettingBack(){
  return this -> quizSettingBack;
}



/// @brief   Get Method for Quiz Setting Points
/// @details Getter for the Quiz Setting Points
/// @return  quizSettingPointsQuiz: bool for the quiz setting point to see points after a quiz is taken
bool Quiz::getQuizSettingPointsQuiz() {
  return this -> quizSettingPointsQuiz;
}



/// @brief   Get Method for Quiz Setting Points Question
/// @details Getter for the Quiz Settings Points Question
/// @return  quizSettingPointsQuestion: bool for the quiz setting point to see points after a question is answered
bool Quiz::getQuizSettingPointsQuestion() {
  return this -> quizSettingPointsQuestion;
}



/// @brief   Get Method for Quiz Edit Password
/// @details Getter for the Quiz Edit Password
/// @return  quizPasswordEdit: string for the quiz edit password
string Quiz::getQuizPasswordEdit() {
  return this -> quizPasswordEdit;
}



/// @brief   Get Method for Quiz Take Password
/// @details Getter for the Quiz Take Password
/// @return  quizPasswordTake: string for the quiz take password
string Quiz::getQuizPasswordTake() {
  return this -> quizPasswordTake;
}



/// @brief   Get Method for Quiz Questions
/// @details Getter for the Quiz Questions
/// @return  quizQuestions: vector<Question> with questions
/// @return  quizQuestionsRandom: vector<Question> with randomized questions
vector<Question> Quiz::getQuizQuestions() {

	// Check if quizStatus is 0 and questions should be randomized
	if ((quizStatus == 0) && (this -> quizSettingRandomQuestion)) {
		vector<Question> quizQuestionsRandom; ///< Vector for random questions

		// Copy quizQuestions to quizQuestionsRandom
		quizQuestionsRandom = quizQuestions;

		// Shuffle quizQuestionsRandom
		random_device rd;
		mt19937 g(rd());
		random_shuffle(quizQuestionsRandom.begin(), quizQuestionsRandom.end());
		shuffle(quizQuestionsRandom.begin(), quizQuestionsRandom.end(), g);

		return quizQuestionsRandom;
	}

	else return this -> quizQuestions;
}



/// @brief   Set Method for Quiz Filename
/// @details Setter for the Quiz Filename
/// @param  newFile: string for the quiz filename
void Quiz::setQuizFile(string newFile) {
  this -> quizFile = newFile;
}



/// @brief   Set Method for Quiz Title
/// @details Setter for the Quiz Title
/// @param  newTitle: string for the quiz title
void Quiz::setQuizTitle(string newTitle) {
  this -> quizTitle = newTitle;
}



/// @brief   Set Method for Quiz Maker
/// @details Setter for the Quiz Maker
/// @param  newMaker: string for the quiz maker
void Quiz::setQuizMaker(string newMaker) {
  this -> quizMaker = newMaker;
}



/// @brief   Set Method for Quiz Taker
/// @details Setter for the Quiz Taker
/// @param  newTaker: string for the quiz taker
void Quiz::setQuizTaker(string newTaker) {
  this -> quizTaker = newTaker;
}



/// @brief   Set Method for Quiz Description
/// @details Setter for the Quiz Description
/// @param  newDescription: string for the quiz description
void Quiz::setQuizDescription(string newDescription) {
  this -> quizDescription = newDescription;
}



/// @brief   Set Method for Quiz Points Correct
/// @details Setter for the Quiz Points Correct
/// @param  quizPointsCorrect: float for the quiz points correct
void Quiz::setQuizPointsCorrect(float quizPointsCorrect) {
  this -> quizPointsCorrect = quizPointsCorrect;
}



/// @brief   Set Method for Quiz Points Total
/// @details Setter for the Quiz Points Total
/// @param  quizPointsTotal: float for the quiz total points
void Quiz::setQuizPointsTotal(float quizPointsTotal) {
  this -> quizPointsTotal = quizPointsTotal;
}



/// @brief   Set Method for Quiz Status
/// @details Setter for the Quiz Status, not yet taken: 0, taken (not completed): 1, taken (completed): 2
/// @param  quizStatus: int for the quiz current status
void Quiz::setQuizStatus(int quizStatus) {
  this -> quizStatus = quizStatus;
}



/// @brief   Set Method for Quiz Date
/// @details Setter for the Quiz Date
/// @param  quizDate: string for the quiz date
void Quiz::setQuizDate(string quizDate) {
  this -> quizDate = quizDate;
}



/// @brief   Set Method for Quiz Time
/// @details Setter for the Quiz current time
/// @param  quizTime: string for the quiz current time
void Quiz::setQuizTime(string quizTime) {
  this -> quizTime = quizTime;
}



/// @brief   Set Method for Quiz Time Limit
/// @details Setter for the Quiz Time Limit
/// @param  quizTimeLimit: string for the quiz time limit
void Quiz::setQuizTimeLimit(string quizTimeLimit) {
  this -> quizTimeLimit = quizTimeLimit;
}



/// @brief   Set Method for Quiz Time Used
/// @details Setter for the Quiz Time Used
/// @param  quizTimeUsed: string for the quiz time used
void Quiz::setQuizTimeUsed(string quizTimeUsed) {
  this -> quizTimeUsed = quizTimeUsed;
}



/// @brief   Set Method for Quiz Random Question
/// @details Setter for the Quiz Random Question flag
/// @param  quizSettingRandomQuestion: bool for the quiz random question flag
void Quiz::setQuizSettingRandomQuestion(bool quizSettingRandomQuestion) {
  this -> quizSettingRandomQuestion = quizSettingRandomQuestion;
}



/// @brief   Set Method for Quiz Setting Jump
/// @details Setter for the Quiz Setting Jump flag, which allows taker's to jump to questions
/// @param  quizSettingJump: bool for the quiz setting jump flag
void Quiz::setQuizSettingJump(bool quizSettingJump){
  this -> quizSettingJump = quizSettingJump;
}



/// @brief   Set Method for Quiz Setting Change
/// @details Setter for the Quiz Setting Change, which allows taker's to change answers
/// @param  quizSettingChange: bool for the quiz setting change flag
void Quiz::setQuizSettingChange(bool quizSettingChange){
  this -> quizSettingChange = quizSettingChange;
}



/// @brief   Set Method for Quiz Setting Back
/// @details Setter for the Quiz Setting Back, which allows taker's to move backwards
/// @param  quizSettingBack: bool for the quiz setting back
void Quiz::setQuizSettingBack(bool quizSettingBack){
  this -> quizSettingBack = quizSettingBack;
}



/// @brief   Set Method for Quiz Points
/// @details Setter for the Quiz Points to see points after submission
/// @param  quizSettingPointsQuiz: bool for the quiz setting points
void Quiz::setQuizSettingPointsQuiz(bool quizSettingPointsQuiz) {
  this -> quizSettingPointsQuiz = quizSettingPointsQuiz;
}



/// @brief   Set Method for Quiz Question Points
/// @details Setter for the Quiz Question Points to see points after question submission
/// @param  quizSettingPointsQuestion: bool for the quiz setting points question
void Quiz::setQuizSettingPointsQuestion(bool quizSettingPointsQuestion) {
  this -> quizSettingPointsQuestion = quizSettingPointsQuestion;
}



/// @brief   Set Method for Quiz Edit Password
/// @details Setter for the Quiz Edit Password
/// @param  quizPasswordEdit: string for the quiz edit password
void Quiz::setQuizPasswordEdit(string quizPasswordEdit) {
  this -> quizPasswordEdit = quizPasswordEdit;
}



/// @brief   Set Method for Quiz Take Password
/// @details Setter for the Quiz Take Password
/// @param  quizPasswordTake: string for the quiz take password
void Quiz::setQuizPasswordTake(string quizPasswordTake) {
  this -> quizPasswordTake = quizPasswordTake;
}



/// @brief   Set Method for Quiz Questions
/// @details Setter for the Quiz Questions
/// @param  quizQuestions: vector<Question>  for the quiz questons
void Quiz::setQuizQuestions(vector<Question> quizQuestions) {
  this -> quizQuestions = quizQuestions;
}




/// @brief   Method to add a new question
/// @details Method to add a new question to the vector of questions
/// @param  question: Question to be added to the list of questions
void Quiz::addQuestion(Question question) {
  this -> quizQuestions.push_back(question);
}
