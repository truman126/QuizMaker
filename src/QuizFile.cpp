/// @file   QuizFile.cpp
/// @author Truman Johnston
/// @date   30 November 2021
/// @brief  Class for Quiz Reading/Writing



#include "QuizFile.h"



using namespace std;



/// @brief   Constructor.
/// @details Constructor for the quiz file class that creates a folder for Quiz files if not already existing
/// @param   *quizTemp: Quiz Pointers that points to quiz object to be written
QuizFile::QuizFile(Quiz *quizTemp) {
	this->quizTemp = quizTemp;

	// Check if the directory where quiz files are saved exists. If not, this conditional is executed and the folder "QuizMaker is created."
	if (!QDir(QDir::homePath() + QString("/QuizMaker")).exists())
		cout << QDir().mkdir(QDir::homePath() + QString("/QuizMaker"));
	if (!QDir(QDir::homePath() + QString("/QuizMaker/Temp")).exists())
		cout << QDir().mkdir(QDir::homePath() + QString("/QuizMaker/Temp"));
}



/// @brief   Destructor.
/// @details Desconstructor for the QuizFile class
QuizFile::~QuizFile() {};



/// @brief   Method to read and parse a quiz file
/// @details Method that reads and parses' a file into the quizTemp pointer
/// @param   openFilename: QString that is used to locate the quiz file
void QuizFile::readFile(QString openFilename) {
	this->openFilename = openFilename;

	// Open file
	file = new QFile(openFilename);

	multiLineString = "";

	if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
		return;

	// Decrypt file
	codec = new Codec(openFilename.toStdString());
	codec->decrypt();

	QTextStream in(file);

	// Set initial data to quizTemp pointer
	quizTemp->setQuizFile(in.readLine().toStdString());
	quizTemp->setQuizTitle(in.readLine().toStdString());
	quizTemp->setQuizMaker(in.readLine().toStdString());
	quizTemp->setQuizTaker(in.readLine().toStdString());
	currentLine = in.readLine().toStdString();

	// Read file contents
	while (currentLine != "eos") {
		multiLineString += currentLine + "\n";
		currentLine = in.readLine().toStdString();
	}

	// Set content data to quizTemp pointer
	quizTemp->setQuizDescription(multiLineString.substr(0, multiLineString.length()-1));
	multiLineString = "";
	quizTemp->setQuizPointsCorrect(in.readLine().toFloat());
	quizTemp->setQuizPointsTotal(in.readLine().toFloat());
	quizTemp->setQuizStatus(in.readLine().toInt());
	quizTemp->setQuizDate((in.readLine().toStdString()));
	quizTemp->setQuizTime((in.readLine().toStdString()));
	quizTemp->setQuizTimeLimit((in.readLine().toStdString()));
	quizTemp->setQuizTimeUsed((in.readLine().toStdString()));
	quizTemp->setQuizSettingRandomQuestion(in.readLine().toInt() == 1 ? true : false);
	quizTemp->setQuizSettingJump(in.readLine().toInt() == 1 ? true : false);
	quizTemp->setQuizSettingChange(in.readLine().toInt() == 1 ? true : false);
	quizTemp->setQuizSettingBack(in.readLine().toInt() == 1 ? true : false);
	quizTemp->setQuizSettingPointsQuiz(in.readLine().toInt() == 1 ? true : false);
	quizTemp->setQuizSettingPointsQuestion(in.readLine().toInt() == 1 ? true : false);
	quizTemp->setQuizPasswordEdit(in.readLine().toStdString());
	quizTemp->setQuizPasswordTake(in.readLine().toStdString());

	// Questions
	in.readLine().toStdString();

	numQuestions = in.readLine().toInt();

	// If more than one question
	if (numQuestions > 0) {

		// Loop through file, reading and parsing question objects
		for (int qIndex = 0; qIndex < numQuestions; qIndex++) {
			question = new Question();

			// Set question initial data
			question->setQuestionNumber(in.readLine().toFloat());
			question->setQuestionTitle(in.readLine().toStdString());
			question->setQuestionSettingRandomAnswer(in.readLine().toInt() == 1 ? true : false);
			currentLine = in.readLine().toStdString();

			// Read question content from file
			while (currentLine != "eos") {
				multiLineString += currentLine + "\n";
				currentLine = in.readLine().toStdString();
			}

			// Set question content data
			question->setQuestionDescription(multiLineString.substr(0, multiLineString.length()-1));
			multiLineString = "";

			question->setQuestionPointsTotal(in.readLine().toFloat());
			question->setQuestionPointsCorrect(in.readLine().toFloat());
			question->setQuestionStatus(in.readLine().toInt());

			// Answers
			in.readLine().toStdString();

			numAnswers = in.readLine().toInt();

			// If more than one answer
			if (numAnswers > 0) {
				vector<Answer> answers;

				// Loop through file, reading and parsing answer objects
				for (int aIndex = 0; aIndex < numAnswers; aIndex++) {
					answer = Answer();

					// Set answer initial data
					answer.setAnswerLetter(in.readLine().toStdString().c_str()[0]);
					answer.setAnswerType(in.readLine().toInt());
					currentLine = in.readLine().toStdString();

					// Read answer content from file
					while (currentLine != "eos") {
						multiLineString += currentLine + "\n";
						currentLine = in.readLine().toStdString();
					}

					// Set answer data content
					answer.setAnswerText(multiLineString.substr(0, multiLineString.length()-1));
					multiLineString = "";

					answer.setAnswerInput(in.readLine().toStdString());
					answer.setAnswerCorrect(in.readLine().toStdString());
					currentLine = in.readLine().toStdString();

					while (currentLine != "eos") {
						multiLineString += currentLine + "\n";
						currentLine = in.readLine().toStdString();
					}

					answer.setAnswerFeedback(multiLineString.substr(0, multiLineString.length()-1));
					multiLineString = "";

					answer.setAnswerPoints(in.readLine().toFloat());
					answer.setAnswerStatus(in.readLine().toInt());

					answers.push_back(answer);
				}

				question->setQuestionAnswers(answers);
			}

			quizTemp->addQuestion(*question);
		}
	}

	file->close();

	codec->encrypt();
}



/// @brief   Method to write a Quiz to a file
/// @details Method to write a Quiz to a file
/// @param   saveFilename: QString to save the Quiz with saveFilename variable name
void QuizFile::writeFile(QString saveFilename) {
	this->saveFilename = saveFilename;
	endOfString = "eos";

	// Create the codec object, decrypt the file if necessary
	codec = new Codec(saveFilename.toStdString());

	// Check if saveFilename is empty, if so create a directory
	if (saveFilename.isEmpty())
		saveFilename = QDir::homePath() + QString("/QuizMaker") + QString("Quiz.quiz");

	file = new QFile(saveFilename);

	// Open the file.
	if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
		return;

	QTextStream out(file);

	/// Write Quiz Details to File
	out << QString::fromStdString(quizTemp->getQuizFile()) << "\n"
		<< QString::fromStdString(quizTemp->getQuizTitle()) << "\n"
		<< QString::fromStdString(quizTemp->getQuizMaker()) << "\n"
		<< QString::fromStdString(quizTemp->getQuizTaker()) << "\n"
		<< QString::fromStdString(quizTemp->getQuizDescription()) << "\n"
		<< QString::fromStdString(endOfString) << "\n"
		<< QString::number(quizTemp->getQuizPointsCorrect()) << "\n"
		<< QString::number(quizTemp->getQuizPointsTotal()) << "\n"
		<< QString::number(quizTemp->getQuizStatus()) << "\n"
		<< QString::fromStdString(quizTemp->getQuizDate()) << "\n"
		<< QString::fromStdString(quizTemp->getQuizTime()) << "\n"
		<< QString::fromStdString(quizTemp->getQuizTimeLimit()) << "\n"
		<< QString::fromStdString(quizTemp->getQuizTimeUsed()) << "\n"
		<< QString::number(quizTemp->getQuizSettingRandomQuestion()) << "\n"
		<< QString::number(quizTemp->getQuizSettingJump()) << "\n"
		<< QString::number(quizTemp->getQuizSettingChange()) << "\n"
		<< QString::number(quizTemp->getQuizSettingBack()) << "\n"
		<< QString::number(quizTemp->getQuizSettingPointsQuiz()) << "\n"
		<< QString::number(quizTemp->getQuizSettingPointsQuestion()) << "\n"
		<< QString::fromStdString(quizTemp->getQuizPasswordEdit()) << "\n"
		<< QString::fromStdString(quizTemp->getQuizPasswordTake()) << "\n";

	// Question
	questions = quizTemp->getQuizQuestions();

	// Write Question Detail to File
	out << "Questions\n"
		<< questions.size() << "\n";

	for (int qIndex = 0; qIndex < questions.size(); qIndex++) {
		out << QString::number(questions[qIndex].getQuestionNumber()) << "\n"
			<< QString::fromStdString(questions[qIndex].getQuestionTitle()) << "\n"
			<< QString::number(questions[qIndex].getQuestionSettingRandomAnswer()) << "\n"
			<< QString::fromStdString(questions[qIndex].getQuestionDescription()) << "\n"
			<< QString::fromStdString(endOfString) << "\n"
			<< QString::number(questions[qIndex].getQuestionPointsTotal()) << "\n"
			<< QString::number(questions[qIndex].getQuestionPointsCorrect()) << "\n"
			<< QString::number(questions[qIndex].getQuestionStatus()) << "\n";

		// Answer
		answers = questions[qIndex].getQuestionAnswers();

		// Write Answer to File
		out << "Answers\n"
			<< answers.size() << "\n";

		for (int aIndex = 0; aIndex < answers.size(); aIndex++) {
			out << QString(QChar(answers[aIndex].getAnswerLetter())) << "\n"
				<< QString::number(answers[aIndex].getAnswerType()) << "\n"
				<< QString::fromStdString(answers[aIndex].getAnswerText()) << "\n"
				<< QString::fromStdString(endOfString) << "\n"
				<< QString::fromStdString(answers[aIndex].getAnswerInput()) << "\n"
				<< QString::fromStdString(answers[aIndex].getAnswerCorrect()) << "\n"
				<< QString::fromStdString(answers[aIndex].getAnswerFeedback()) << "\n"
				<< QString::fromStdString(endOfString) << "\n"
				<< QString::number(answers[aIndex].getAnswerPoints()) << "\n"
				<< QString::number(answers[aIndex].getAnswerStatus()) << "\n";
		}
	}

	file->close();

	codec->encrypt();
}
