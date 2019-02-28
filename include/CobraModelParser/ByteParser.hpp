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

        template<typename T>
        static T parse(const std::vector<char> &bytes, const std::string &endianIndicator) {
            if (sizeof(T) < bytes.size()) {
                throw ByteArrayTooLargeException<T>();
            }

            T result = 0;
            if (endianIndicator == "IM") {
                auto rit = bytes.rbegin();
                for (size_t bitsToShift = (bytes.size() - 1) * 8; rit != bytes.rend(); ++rit, bitsToShift -= 8) {
                    result |= (static_cast<unsigned char>(*rit) << bitsToShift);
                }
            } else if (endianIndicator == "MI") {
                auto it = bytes.begin();
                for (size_t bitsToShift = (bytes.size() - 1) * 8; it != bytes.end(); ++it, bitsToShift -= 8) {
                    result |= (static_cast<unsigned char>(*it) << bitsToShift);
                }
            } else {
                throw UnknownEndianIndicatorException(endianIndicator);
            }

            return result;
        }


    };
}

#endif //COBRAMODELPARSER_BYTEPARSER_HPP
