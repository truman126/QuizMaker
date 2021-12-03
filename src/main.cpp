/// @file   main.cpp
/// @author Kenneth McAlinden
/// @date   30 November 2021
/// @brief  Main class for program



#include <QApplication>
#include <QFile>
#include "QuizFile.h"
#include "WindowQuiz.h"



/// @brief   Main.
/// @details Shows the first window of the program and executes the application.
/// @param   argc Number of arguments.
/// @param   argv Vector of arguments.
/// @return  Execute application.
int main(int argc, char *argv[]) {
	QApplication application(argc, argv);

	// Set style for application.
	QFile styleSheetFile("../src/style.qss");
	styleSheetFile.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(styleSheetFile.readAll());
	application.setStyleSheet(styleSheet);

	WindowQuiz windowQuiz;

	windowQuiz.show();

	return application.exec();
}
