#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//! Transliterate char to string

bool processCommandLine(const std::vector<std::string>& args,bool& helpRequested,bool& versionRequested,std::string& inputFileName,std::string& outputFileName );
#endif 