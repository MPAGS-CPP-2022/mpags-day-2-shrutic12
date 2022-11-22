#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "transformChar.hpp"
#include "processCommandLine.hpp"


std::string transformChar( const char in_char );


bool processCommandLine(const std::vector<std::string>& args,bool& helpRequested,bool& versionRequested,std::string& inputFileName,std::string& outputFileName );


int main(int argc, char* argv[])
{
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    

    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{""};
    std::string outputFile{""};
    std::string in_name{inputFile};
    
    
    // Process command line arguments - ignore zeroth element, as we know this
    // to be the program name and don't need to worry about it

    if (!processCommandLine(cmdLineArgs,helpRequested,versionRequested,inputFile,outputFile))
    {
        return 1;
    }
    // Handle help, if requested
    if (helpRequested) {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << std::endl;
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        //return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
        std::cout << "0.1.0" << std::endl;
        //return 0;
    }

    
    // Read in user input from stdin/file
    std::ifstream in_file {in_name};
    std::ifstream out_file{outputFile};
    // Warn that input file option not yet implemented
    char inputChar{'x'};
    std::string inputText;
    if (!inputFile.empty()) {
        std::ifstream inputStream(inputFile);

      if (!in_file.good())
        {
            std::cerr <<"error"<<std::endl;
            return 1;
        
        }
        while (inputStream >> inputChar) {
         // Uppercase alphabetic characters
        inputText+=transformChar(inputChar);

            // If the character isn't alphabetic or numeric, DONT add it
    }

    }
    else{
        while(std::cin >> inputChar){
            inputText += transformChar(inputChar);
        }

    }

        // Warn that output file option not yet implemented
    if (!outputFile.empty()) {
        //std::cerr << "[warning] output to file ('" << outputFile
        //            << "') not implemented yet, using stdout\n";
        std::ofstream outputStream{outputFile};

        if(!outputStream.good())
        {
            std::cerr << "Unable to open file for writing" <<std::endl;
            return 1;
        }
    else{ 
        outputStream <<inputText<<std::endl;

    }
    }

        
        // No requirement to return from main, but we do so for clarity
        // and for consistency with other functions
    
    return 0;
}

