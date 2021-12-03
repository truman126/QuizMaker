/// @file   Codec.cpp
/// @author Truman Johnston
/// @date   30 November 2021
/// @brief  This class contains code for the Codec object



#include "Codec.h"



/// @brief Constructor.
/// @details Constructor for Codec class
/// @param filename: string for the quiz filename
Codec::Codec(std::string filename) {

    // Set filename and set tempLocation
    this->filename = filename;
    tempLocation   = (QDir::homePath() + QString("/QuizMaker/Temp/tempfile.quiz")).toStdString();
}



/// @brief Destructor.
Codec::~Codec(){};



/// @brief Method used to encrypt Quiz files
void Codec::encrypt() {
    tempFilename = filename;
    tempFilename.replace(tempFilename.end() - 4, tempFilename.end(), "txt");

    // Rename filename with tempFilename
    std::rename(filename.c_str(), tempFilename.c_str());

    // Open tempFilename for reading & tempLocation for writing
    fps.open(tempFilename, std::fstream::in);
    fpt.open(tempLocation, std::fstream::out);

    while (fps >> std::noskipws >> ch) {
        ch = ch + 1;
        fpt << ch;
    }

    // Close tempFilename & tempLocation
    fps.close();
    fpt.close();

    // Open tempFilename for writing & tempLocation for reading
    fps.open(tempFilename, std::fstream::out);
    fpt.open(tempLocation, std::fstream::in);

    while (fpt >> std::noskipws >> ch) {
        std::cout << ch + "\n";
        fps << ch;
    }

    // Close tempFilename & tempLocation
    fps.close();
    fpt.close();

    // Rename tempFilename with filename
    std::rename(tempFilename.c_str(), filename.c_str());
}



/// @brief Method to decrypt Quiz files
void Codec::decrypt() {
    tempFilename = filename;
    tempFilename.replace(tempFilename.end() - 4, tempFilename.end(), "txt");

    // Rename filename with tempFilename
    std::rename(filename.c_str(), tempFilename.c_str());

    // Open tempFilename for reading & tempLocation for writing
    fps.open(tempFilename, std::fstream::in);
    fpt.open(tempLocation, std::fstream::out);

    while (fps >> std::noskipws >> ch) {
        ch = ch - 1;
        fpt << ch;
    }

    // Close tempFilename & tempLocation
    fps.close();
    fpt.close();

    // Open tempFilename for writing & tempLocation for reading
    fps.open(tempFilename, std::fstream::out);
    fpt.open(tempLocation, std::fstream::in);

    while (fpt >> std::noskipws >> ch) {
        std::cout << ch + "\n";
        fps << ch;
    }

    // Close tempFilename & tempLocation
    fps.close();
    fpt.close();

    // Rename tempFilename with filename
    std::rename(tempFilename.c_str(), filename.c_str());

    // Remove tempLocation
    std::remove(tempLocation.c_str());
}
