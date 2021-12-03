QT       += core widgets

TARGET = QuizMaker

TEMPLATE = app 

SOURCES += 				\
	../src/main.cpp 			\
	../src/WindowQuiz.cpp		\
	../src/WindowEditQuiz.cpp		\
	../src/WindowEditQuestion.cpp	\
	../src/WindowEditAnswer.cpp		\
	../src/WindowTakeQuizTaker.cpp	\
	../src/WindowTakeQuiz.cpp		\
	../src/Answer.cpp			\
	../src/Question.cpp			\
	../src/Quiz.cpp			\
	../src/QuizFile.cpp			\
	../src/QWidget_Answer.cpp	\
	../src/Codec.cpp

HEADERS += 				\
	../src/WindowQuiz.h			\
	../src/WindowEditQuiz.h		\
	../src/WindowEditQuestion.h		\
	../src/WindowEditAnswer.h		\
	../src/WindowTakeQuizTaker.h	\
	../src/WindowTakeQuiz.h		\
	../src/Answer.h			\
	../src/Question.h			\
	../src/Quiz.h			\
	../src/QuizFile.h			\
	../src/QWidget_Answer.h			\
	../src/Codec.h
