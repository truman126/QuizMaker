/// @file   QWidget_Answer.cpp
/// @author Kenneth McAlinden
/// @date   30 November 2021
/// @brief  Class for QWidget_Answer



#include "QWidget_Answer.h"



using namespace std;



/// @brief   Constructor.
/// @details QWidget_Answer Constructor that sets UI elements on screen
/// @param   *answer: Answer pointer for the answer object being edited
/// @param   *parent: QWidget pointer to the parent widget
QWidget_Answer::QWidget_Answer(Answer *answer, QWidget *parent) : QWidget(parent) {
	// lineEdit_Letter
	lineEdit_Letter = new QLineEdit(this);
	string answerLetter;
	answerLetter.push_back(answer -> getAnswerLetter());
	lineEdit_Letter -> setText(QString::fromStdString(answerLetter));
	lineEdit_Letter -> setGeometry(QRect(QPoint(0, 0), QSize(32, 78)));
	lineEdit_Letter -> setReadOnly(true);
	lineEdit_Letter -> setStyleSheet("color: rgb(223, 223, 223); font-weight: bold; background-color: rgb(14, 28, 84);");

	// plainTextEdit_Text
	plainTextEdit_Text = new QPlainTextEdit(this);
	plainTextEdit_Text -> setGeometry(QRect(QPoint(48, 0), QSize(320, 78)));
	plainTextEdit_Text -> setPlainText(QString::fromStdString(answer -> getAnswerText()));
	plainTextEdit_Text -> setReadOnly(true);
	plainTextEdit_Text -> setStyleSheet("color: rgb(223, 223, 223); background-color: rgb(14, 28, 84);");

	// radioButton_InputT
	if (answer -> getAnswerType() == 0) {
		radioButton_InputT = new QRadioButton("True", this);
		radioButton_InputT -> setGeometry(QRect(QPoint(384, 0), QSize(216, 35)));
		radioButton_InputT -> setChecked(false);
		if (answer -> getAnswerInput() == "true") radioButton_InputT -> setChecked(true);

		// radioButton_InputF
		radioButton_InputF = new QRadioButton("False", this);
		radioButton_InputF -> setGeometry(QRect(QPoint(384, 43), QSize(216, 35)));
		radioButton_InputF -> setChecked(false);
		if (answer -> getAnswerInput() == "false") radioButton_InputF -> setChecked(true);
	}

	// checkBox_InputMC
	if (answer -> getAnswerType() == 1) {
		checkBox_InputMC = new QCheckBox(this);
		checkBox_InputMC -> setGeometry(QRect(QPoint(384, 0), QSize(216, 78)));
		if (answer -> getAnswerInput() == "selected") checkBox_InputMC -> setChecked(true);
	}

	// plainTextEdit_InputWA
	if (answer -> getAnswerType() == 2) {
		plainTextEdit_InputWA = new QPlainTextEdit(this);
		plainTextEdit_InputWA -> setGeometry(QRect(QPoint(384, 0), QSize(216, 78)));
		plainTextEdit_InputWA -> setPlainText(QString::fromStdString(answer -> getAnswerInput()));
	}

	// lineEdit_Points
	lineEdit_Points = new QLineEdit(this);
	lineEdit_Points -> setGeometry(QRect(QPoint(616, 0), QSize(120, 78)));
	lineEdit_Points -> setAlignment(Qt::AlignCenter);

	// lineEdit_Number: Trim trailing zeroes.
	string answerPoints = to_string(answer -> getAnswerPoints());
	answerPoints.erase(answerPoints.find_last_not_of("0") + 1, string::npos);
	if (answerPoints.back() == '.') answerPoints.pop_back();
	if (answer -> getAnswerInput() == "")                                lineEdit_Points -> setText(QString::fromStdString(answerPoints));
	else if (answer -> getAnswerInput() == answer -> getAnswerCorrect()) lineEdit_Points -> setText(QString::fromStdString(answerPoints + " / " + answerPoints));
	else                                                                 lineEdit_Points -> setText(QString::fromStdString("0 / " + answerPoints));
	lineEdit_Points -> setReadOnly(true);
	lineEdit_Points -> setStyleSheet("color: rgb(223, 223, 223); background-color: rgb(14, 28, 84);");

	// plainTextEdit_Feedback
	plainTextEdit_Feedback = new QPlainTextEdit(this);
	plainTextEdit_Feedback -> setPlainText(QString::fromStdString(answer -> getAnswerFeedback()));
	plainTextEdit_Feedback -> setGeometry(QRect(QPoint(0, 80), QSize(736, 64)));
	plainTextEdit_Feedback -> setReadOnly(true);
	plainTextEdit_Feedback -> setStyleSheet("font-size: 10pt; font-style: italic; padding: 8px; color: rgb(128, 159, 191); background-color: rgb(16, 32, 96);");
	if (answer -> getAnswerFeedback() == "") plainTextEdit_Feedback -> setHidden(true);
}



/// @brief   Destructor.
/// @details Deconstructor for QWidget_Answer
QWidget_Answer::~QWidget_Answer() {};



/// @brief  Get TF Radio Button
/// @details Getter to check if T/F Radio Button is selected
/// @return 2 if T selected, 1 if F selected, 0 if none selected
int QWidget_Answer::getQWidget_AnswerInputTF() {
	if      (radioButton_InputT -> isChecked()) return 2;
	else if (radioButton_InputF -> isChecked()) return 1;
	else                                        return 0;
}



/// @brief  Get MC Selection
/// @details Getter to check MC selection
/// @return 1 if selected or 0 if not
bool QWidget_Answer::getQWidget_AnswerInputMC() {
	if   (checkBox_InputMC -> isChecked()) return 1;
	else                                   return 0;
}



/// @brief  Get Word Answer
/// @details Getter to check the word answer
/// @return string of word box text
string QWidget_Answer::getQWidget_AnswerInputWA() {
	return plainTextEdit_InputWA -> toPlainText().toStdString();
}



/// @brief  Set Answer Letter
/// @details Setter to set answer letter
/// @param answerLetter: char to set the answer letter that's selected
void QWidget_Answer::setQWidget_AnswerLetter(char answerLetter) {
	string answerLetterString;
	answerLetterString.push_back(answerLetter);
	lineEdit_Letter -> setText(QString::fromStdString(answerLetterString));
}



/// @brief  Set Answer Text
/// @details Setter to set answer text
/// @param answerText: string to set the answer text
void QWidget_Answer::setQWidget_AnswerText(string answerText) {
	plainTextEdit_Text -> setPlainText(QString::fromStdString(answerText));
}



/// @brief  Set Answer TF Input
/// @details Setter to set answer tf
/// @param answerInputTF: bool to set the T/F
void QWidget_Answer::setQWidget_AnswerInputTF(bool answerInputTF) {
	if (answerInputTF == true) {
		radioButton_InputT -> setChecked(true);
		radioButton_InputF -> setChecked(false);
	}
	else {
		radioButton_InputT -> setChecked(false);
		radioButton_InputF -> setChecked(true);
	}
}



/// @brief  Set Answer MC
/// @details Setter to set answer mc
/// @param answerInputMC: bool to set the answer mc
void QWidget_Answer::setQWidget_AnswerInputMC(bool answerInputMC) {
	if   (answerInputMC == true) checkBox_InputMC -> setChecked(true);
	else                         checkBox_InputMC -> setChecked(false);
}



/// @brief  Set Answer Word Answer
/// @details Setter to set answer text
/// @param answerInputWA: string to set the answer text
void QWidget_Answer::setQWidget_AnswerInputWA(string answerInputWA) {
	plainTextEdit_InputWA -> setPlainText(QString::fromStdString(answerInputWA));
}



/// @brief  Set Answer Points
/// @details Setter to set answer points
/// @param answerInput: float to set the answer input points
/// @param answerCorrect: float to set the answer correct points
void QWidget_Answer::setQWidget_AnswerPoints(float answerInput, float answerCorrect) {
	if   (answerInput == answerCorrect) lineEdit_Points -> setText(QString::fromStdString(to_string(answerInput) + " / " + to_string(answerCorrect)));
	else                                lineEdit_Points -> setText(QString::fromStdString("0 / " + to_string(answerCorrect)));
}



/// @brief  Set Answer Feedback
/// @details Setter to set answer feedback
/// @param answerFeedback: string to set the answer feedback
void QWidget_Answer::setQWidget_AnswerFeedback(string answerFeedback) {
	plainTextEdit_Feedback -> setPlainText(QString::fromStdString(answerFeedback));
}



/// @brief  Set Answer Type
/// @details Setter to set answer type, enabling/disabling certain parts of the widget
/// @param answerType: int to set the answer widget style
void QWidget_Answer::disableQObjects(int answerType) {
	if (answerType == 0) {
		                 radioButton_InputT -> setDisabled(true);
		                 radioButton_InputF -> setDisabled(true);
	}
	if (answerType == 1) checkBox_InputMC      -> setDisabled(true);
	if (answerType == 2) plainTextEdit_InputWA -> setDisabled(true);
}
