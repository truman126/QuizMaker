/// @file   WindowEditAnswer.cpp
/// @author Kenneth McAlinden
/// @author Truman Johnston
/// @date   30 November 2021
/// @brief  WindowEditAnswer class used to edit answers



#include "WindowEditAnswer.h"
#include "WindowEditQuestion.h"



using namespace std;



/// @brief   Constructor.
/// @details WindowEditAnswer Constructor that initializes the view with parameter values
/// @param   *quiz: first Quiz pointer
/// @param   *quizTemp: second Quiz pointer
/// @param   *quizTempTemp: third Quiz pointer
/// @param   *quizTempTempTemp: fourth Quiz pointer
/// @param   *question: first Question pointer
/// @param   *questionTemp: second Question pointer
/// @param   *answer: answer pointer
/// @param   *parent: widget parent pointer
WindowEditAnswer::WindowEditAnswer(Quiz *quiz, Quiz *quizTemp, Quiz *quizTempTemp, Quiz *quizTempTempTemp, Question *question, Question *questionTemp, Answer *answer, QWidget *parent) : QMainWindow(parent) {
	this -> setFixedSize(960, 624);
	this -> setWindowTitle("Quiz Maker: Edit Answer");

	this -> quiz             = quiz;
	this -> quizTemp         = quizTemp;
	this -> quizTempTemp     = quizTempTemp;
	this -> quizTempTempTemp = quizTempTempTemp;
	this -> question         = question;
	this -> questionTemp     = questionTemp;
	this -> answer           = answer;

	// label_Letter
	label_Letter = new QLabel("Letter", this);
	label_Letter -> setGeometry(QRect(QPoint(16, 24), QSize(72, 16)));

	// lineEdit_Letter
	lineEdit_Letter = new QLineEdit(this);
	lineEdit_Letter -> setGeometry(QRect(QPoint(88, 16), QSize(144, 32)));
	lineEdit_Letter -> setMaxLength(1);
	string answerLetter;
	answerLetter.push_back(answer -> getAnswerLetter());
	if (answerLetter != "?") lineEdit_Letter -> setText(QString::fromStdString(answerLetter));

	// label_Points
	label_Points = new QLabel("Points", this);
	label_Points -> setGeometry(QRect(QPoint(248, 24), QSize(72, 16)));

	// lineEdit_Points
	lineEdit_Points = new QLineEdit(this);
	lineEdit_Points -> setGeometry(QRect(QPoint(320, 16), QSize(144, 32)));
	lineEdit_Points -> setMaxLength(4);

	// lineEdit_Points: Trim trailing zeroes.
	if (answer -> getAnswerPoints() != 0) {
		string answerPoints = to_string(answer -> getAnswerPoints());

		answerPoints.erase(answerPoints.find_last_not_of("0") + 1, string::npos);

		if (answerPoints.back() == '.') answerPoints.pop_back();

		lineEdit_Points -> setText(QString::fromStdString(answerPoints));
	}

	// radioButton_AnswerTypeTF
	radioButton_AnswerTypeTF = new QRadioButton("True or false", this);
	radioButton_AnswerTypeTF -> setGeometry(QRect(QPoint(16, 72), QSize(136, 32)));
	if (answer -> getAnswerType() == 0) radioButton_AnswerTypeTF -> setChecked(true);

	// radioButton_AnswerTypeMC
	radioButton_AnswerTypeMC = new QRadioButton("Multiple choice", this);
	radioButton_AnswerTypeMC -> setGeometry(QRect(QPoint(168, 72), QSize(144, 32)));
	if (answer -> getAnswerType() == 1) radioButton_AnswerTypeMC -> setChecked(true);

	// radioButton_AnswerTypeWA
	radioButton_AnswerTypeWA = new QRadioButton("Word answer", this);
	radioButton_AnswerTypeWA -> setGeometry(QRect(QPoint(328, 72), QSize(136, 32)));
	if (answer -> getAnswerType() == 2) radioButton_AnswerTypeWA -> setChecked(true);

	// plainTextEdit_Text
	plainTextEdit_Text = new QPlainTextEdit(this);
	plainTextEdit_Text -> setPlaceholderText("enter answer text...");
	plainTextEdit_Text -> setGeometry(QRect(QPoint(16, 128), QSize(928, 136)));
	plainTextEdit_Text -> setPlainText(QString::fromStdString(answer -> getAnswerText()));

	// label_Input
	label_Input = new QLabel("Input", this);
	label_Input -> setGeometry(QRect(QPoint(16, 304), QSize(72, 16)));
	label_Input -> setStyleSheet("color: rgb(128, 223, 255);");

	// lineEdit_Input
	lineEdit_Input = new QLineEdit(this);
	lineEdit_Input -> setPlaceholderText("leave blank to let taker choose input");
	lineEdit_Input -> setGeometry(QRect(QPoint(88, 296), QSize(856, 32)));
	lineEdit_Input -> setText(QString::fromStdString(answer -> getAnswerInput()));

	// label_Correct
	label_Correct = new QLabel("Correct", this);
	label_Correct -> setGeometry(QRect(QPoint(16, 352), QSize(72, 16)));
	label_Correct -> setStyleSheet("color: rgb(128, 223, 255);");

	// lineEdit_Correct
	lineEdit_Correct = new QLineEdit(this);
	lineEdit_Correct -> setPlaceholderText("enter correct response (\"true\" or \"false\" if True or False, \"selected\" or \"unselected\" if Multiple Choice)...");
	lineEdit_Correct -> setGeometry(QRect(QPoint(88, 344), QSize(856, 32)));
	lineEdit_Correct -> setText(QString::fromStdString(answer -> getAnswerCorrect()));

	// plainTextEdit_Feedback
	plainTextEdit_Feedback = new QPlainTextEdit(this);
	plainTextEdit_Feedback -> setPlaceholderText("(optional) enter feedback seen by taker after quiz is completed...");
	plainTextEdit_Feedback -> setGeometry(QRect(QPoint(16, 408), QSize(928, 136)));
	plainTextEdit_Feedback -> setPlainText(QString::fromStdString(answer -> getAnswerFeedback()));

	// pushButton_Cancel
	pushButton_Cancel = new QPushButton("Cancel", this);
	pushButton_Cancel -> setGeometry(QRect(QPoint(16, 576), QSize(448, 32)));
	connect(pushButton_Cancel, &QPushButton::released, this, &WindowEditAnswer::cancel);

	// pushButton_Ok
	pushButton_Ok = new QPushButton("Ok", this);
	pushButton_Ok -> setGeometry(QRect(QPoint(496, 576), QSize(448, 32)));
	connect(pushButton_Ok, &QPushButton::released, this, &WindowEditAnswer::ok);
}



/// @brief   Destructor.
/// @details WindowEditAnswer Deconstructor
WindowEditAnswer::~WindowEditAnswer() {};



/// @brief   Cancel Method
/// @details WindowEditAnswer Cancel Method, which closes the widget screen
void WindowEditAnswer::cancel() {
	// Switch window.
	windowEditQuestion = new WindowEditQuestion(quiz, quizTemp, quizTempTemp, question);

	connect(windowEditQuestion, &WindowEditQuestion::switchWindow, this, &WindowEditQuestion::show);

	this               -> close();
	windowEditQuestion -> show();
}



/// @brief   Ok Method.
/// @details Ok Method to submit answer
void WindowEditAnswer::ok() {
    // Only allow "true" and "false" to be the correct input if answer type is TF.
    if (radioButton_AnswerTypeTF -> isChecked()) {

			// Present error if input is not true or false
    	if ((lineEdit_Correct -> text().toStdString() != "true") && (lineEdit_Correct -> text().toStdString() != "false")) {
    		messageBox.critical(0, "Error", "Correct input must be either \"true\" or \"false\" for True or False!");

    		lineEdit_Correct -> setText("");
    		lineEdit_Correct -> setFocus();

    		return;
    	}
    }

    // Only allow "selected" and "unselected" to be the correct input if answer type is MC.
    if (radioButton_AnswerTypeMC -> isChecked()) {

			// Present error if MC is not selected or unselected
    	if ((lineEdit_Correct -> text().toStdString() != "selected") && (lineEdit_Correct -> text().toStdString() != "unselected")) {
    		messageBox.critical(0, "Error", "Correct input must be either \"selected\" or \"unselected\" for Multiple Choice!");

    		lineEdit_Correct -> setText("");
    		lineEdit_Correct -> setFocus();

    		return;
    	}
    }

		// Present error if letter is not inputed
    if ((lineEdit_Letter -> text().isEmpty()) || (isNumber(lineEdit_Letter -> text().toStdString()) == true)) {

    	messageBox.critical(0, "Error", "Enter a letter for the answer!");

    	lineEdit_Letter -> setFocus();
    }

		// Present error if decimal not inputted
    else if (isNumber(lineEdit_Points -> text().toStdString()) == false) {
		messageBox.critical(0, "Error", "Points must be a decimal number (ex. 1, 2.0, 3.25)!");

		lineEdit_Points -> setFocus();
	}

    else {
    	// Make a copy of Question's Answer vector.
    	questionAnswersTemp = questionTemp -> getQuestionAnswers();

    	// Check if letter already exists for an answer to this question.
    	for (int i = 0; i < questionAnswersTemp.size(); i++) {

				// Present error if duplicate letter added
    		if ((lineEdit_Letter -> text().toStdString().c_str()[0] == questionAnswersTemp[i].getAnswerLetter()) && (lineEdit_Letter -> text().toStdString().c_str()[0] != answer -> getAnswerLetter())) {
    			messageBox.critical(0, "Error", "An answer with this letter already exists for this question!");

    			string answerLetter;
					// Add answerLetter
    			answerLetter.push_back(answer -> getAnswerLetter());

    			if (answerLetter == "?") lineEdit_Letter -> setText("");
    			else                     lineEdit_Letter -> setText(QString::fromStdString(answerLetter));

    			lineEdit_Letter -> setFocus();

    			return;
    		}
    	}

    	// Make a copy of Quiz's Question vector.
		quizQuestionsTemp = quizTempTempTemp -> getQuizQuestions();

    	// Remove old Question from Quiz's Question vector.
    	for (int i = 0; i < quizQuestionsTemp.size(); i++) {
    		if ((quizQuestionsTemp[i].getQuestionNumber() != 0) && (quizQuestionsTemp[i].getQuestionNumber() == questionTemp -> getQuestionNumber())) {
    			quizQuestionsTemp.erase(quizQuestionsTemp.begin() + i);
    		}
    	}

    	// Remove old Answer from Question's Answer vector.
    	for (int i = 0; i < questionAnswersTemp.size(); i++) {
    		if ((questionAnswersTemp[i].getAnswerLetter() != '?') && (questionAnswersTemp[i].getAnswerLetter() == answer -> getAnswerLetter())) {
    			questionAnswersTemp.erase(questionAnswersTemp.begin() + i);
    		}
    	}

    // Set data for Answer.
		answer -> setAnswerLetter(lineEdit_Letter -> text().toStdString().c_str()[0]);

		// Set answerType
		if      (radioButton_AnswerTypeTF->isChecked()) answer -> setAnswerType(0);
		else if (radioButton_AnswerTypeMC->isChecked()) answer -> setAnswerType(1);
		else if (radioButton_AnswerTypeWA->isChecked()) answer -> setAnswerType(2);

		// Set answer data
		answer -> setAnswerText(plainTextEdit_Text -> toPlainText().toStdString());
		answer -> setAnswerInput(lineEdit_Input -> text().toStdString());
		answer -> setAnswerCorrect(lineEdit_Correct -> text().toStdString());
		answer -> setAnswerFeedback(plainTextEdit_Feedback -> toPlainText().toStdString());

		if (lineEdit_Points -> text().toStdString() != "") answer -> setAnswerPoints(stof(lineEdit_Points -> text().toStdString()));
		else                                               answer -> setAnswerPoints(0);

		if (lineEdit_Input -> text().toStdString() == "") answer -> setAnswerStatus(0);
		else                                              answer -> setAnswerStatus(1);

		// Add Answer to temporary Question Answer vector.
		questionAnswersTemp.push_back(*answer);

		// Set Question's Answer vector to temporary Question Answer vector.
		questionTemp -> setQuestionAnswers(questionAnswersTemp);

		quizQuestionsTemp.push_back(*questionTemp);

		quizTempTempTemp -> setQuizQuestions(quizQuestionsTemp);

		// Switch window.
		windowEditQuestion = new WindowEditQuestion(quiz, quizTemp, quizTempTempTemp, questionTemp);

		connect(windowEditQuestion, &WindowEditQuestion::switchWindow, this, &WindowEditQuestion::show);

		this               -> close();
		windowEditQuestion -> show();
    }
}



/// @brief  Check if string is a number
/// @param  answerPointsInput: string of point value
/// @return true is number, false if else
bool WindowEditAnswer::isNumber(const string& answerPointsInput) {
	for (char const &answerPointsInputChar : answerPointsInput) if ((isdigit(answerPointsInputChar) != 0) || (answerPointsInputChar == '.')) return true;

	return false;
}
