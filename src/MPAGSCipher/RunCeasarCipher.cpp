#include <iostream>
#include <string>
#include <vector>
#include "RunCeasarCipher.hpp"

std::string runCeasarCipher(const std::string& inputText, const std::size_t key,
                            const bool encrypt)
{
    std::string outputText;
    const std::vector<char> alphabet={'A','B','C','D','E','F','G','H',
                                    'I','J','K','L','M','N','O','P','Q',
                                    'R','S','T','U','V','W','X','Y','Z'};
const std::size_t alphabetSize{alphabet.size()};

const std::size_t truncatedKey{key % alphabetSize};

char processedChar{'x'};
for (const auto& origChar : inputText){
    for (size_t i{0}; i<alphabetSize;++i){
        if (origChar == alphabet[i]) {
                // Apply the appropriate shift (depending on whether we're encrypting
                // or decrypting) and determine the new character
                // Can then break out of the loop over the alphabet
                if (encrypt) {
                    processedChar = alphabet[(i + truncatedKey) % alphabetSize];
                } else {
                    processedChar = alphabet[(i + alphabetSize - truncatedKey) %
                                             alphabetSize];
                }
                break;
            }

    }
    outputText +=processedChar;
    }
    return outputText;
}

