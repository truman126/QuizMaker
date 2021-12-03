/// @file   Codec.h
/// @author Truman Johnston
/// @date   30 November 2021
/// @brief  Header for Codec.cpp



#ifndef CODEC
#define CODEC

#include <string>
#include <iostream>
#include <fstream>
#include <QDir>
#include <QString>
#include <cstdio>



/// @class   Codec
/// @author  Truman Johnston
/// @brief   Codec Class used to Encrypt/Decrypt Quiz Files
/// @details This class is used to Encrypt/Decrypt files in order to hinder anybody from editing the files for their benefit
class Codec {
	private:
		std::string  tempLocation;
		std::string  filename;
        std::string  tempFilename;
        std::fstream fps;
        std::fstream fpt;
        char         ch;

	public:
		Codec(std::string filename);
		~Codec();
		void encrypt();
		void decrypt();
};

#endif
