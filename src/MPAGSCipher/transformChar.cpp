#include <cctype>
#include <iostream>
#include <string>
#include <vector>




std::string transformChar( const char in_char )
{
    std::string result{""};
    std::string tmp{""};
    /*
    Take a char as an input and return a string after applying transliteration
    input : char
    output : string 
    
    */
   
    if (std::isalpha(in_char)) {
            tmp = std::toupper(in_char);
            
        }

    // Transliterate digits to English words
        switch (in_char) {
            case '0':
                tmp = "ZERO";
                break;
            case '1':
                tmp = "ONE";
                break;
            case '2':
                tmp = "TWO";
                break;
            case '3':
                tmp = "THREE";
                break;
            case '4':
                tmp = "FOUR";
                break;
            case '5':
                tmp = "FIVE";
                break;
            case '6':
                tmp = "SIX";
                break;
            case '7':
                tmp = "SEVEN";
                break;
            case '8':
                tmp = "EIGHT";
                break;
            case '9':
                tmp = "NINE";
                break;
        }
        
    return tmp;


}