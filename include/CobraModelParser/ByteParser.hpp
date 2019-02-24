#ifndef COBRAMODELPARSER_BYTEPARSER_HPP
#define COBRAMODELPARSER_BYTEPARSER_HPP

#include <numeric>
#include <string>
#include <vector>

#include "CobraModelParser/Exceptions.hpp"

namespace CobraModelParser {
    class ByteParser {
    public:
        ByteParser() = delete;

        static size_t parseSize_t(const std::vector<char> &chars, const std::string &endianIndicator) {

            std::vector<unsigned char> shiftedBits;
            if (endianIndicator == "IM") {
                std::vector<char>::const_reverse_iterator rit = chars.rbegin();
                for (size_t bitsToShift = (chars.size() - 1) * 8; rit != chars.rend(); ++rit, bitsToShift -= 8) {
                    unsigned char shifted = static_cast<unsigned char>(*rit) << bitsToShift;
                    shiftedBits.push_back(shifted);
                }
            } else if (endianIndicator == "MI") {
                std::vector<char>::const_iterator it = chars.begin();
                for (size_t bitsToShift = (chars.size() - 1) * 8; it != chars.end(); ++it, bitsToShift -= 8) {
                    unsigned char shifted = static_cast<unsigned char>(*it) << bitsToShift;
                    shiftedBits.push_back(shifted);
                }
            } else {
                throw UnkownEndianIndicator(endianIndicator);
            }

            unsigned char result = 0;
            std::vector<unsigned  char>::const_reverse_iterator rit = shiftedBits.rbegin();
            for(;rit!=shiftedBits.rend(); ++rit) {
                result |= *rit;
            }

            return static_cast<size_t>(result);
        }


    };
}

#endif //COBRAMODELPARSER_BYTEPARSER_HPP
