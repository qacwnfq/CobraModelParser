#ifndef COBRAMODELPARSER_BYTEPARSER_HPP
#define COBRAMODELPARSER_BYTEPARSER_HPP

#include <numeric>
#include <string>
#include <vector>

#include "CobraModelParser/Byte.hpp"
#include "CobraModelParser/Exceptions.hpp"

namespace CobraModelParser {
    class ByteParser {
    public:
        const std::string &getEndianIndicator() const {
            return endianIndicator;
        }

        explicit ByteParser(const std::string &endianIndicator) {
            setEndianIndicator(endianIndicator);
        }

        ByteParser() = default;

        template<typename T>
        T parseNumericType(std::vector<Byte> bytes) const {
            if (sizeof(T) < bytes.size()) {
                throw ByteArrayTooLargeException<T>();
            }
            if (endianIndicator != "IM" && endianIndicator != "MI") {
                throw UnknownEndianIndicatorException(endianIndicator);
            }

            if (this->endianIndicator == "IM") {
                std::reverse(bytes.begin(), bytes.end());
            }

            T result = 0;
            auto it = bytes.begin();
            for (size_t bitsToShift = (bytes.size() - 1) * BYTE_SIZE;
                 it != bytes.end(); ++it, bitsToShift -= BYTE_SIZE) {
                result |= (*it << bitsToShift);
            }
            return result;
        }

        std::string parseString(std::vector<Byte> bytes) const {
            size_t indexOfNull = bytes.size();
            for(size_t index=0; index<bytes.size(); ++index) {
                if(bytes[index] == 0) {
                    indexOfNull = index;
                    break;
                }
            }
            bytes.erase(bytes.begin()+indexOfNull, bytes.end());
            return std::string(bytes.begin(), bytes.end());
        }

        std::string parseHexadeximalAsString(std::vector<Byte> bytes) const {
            if (endianIndicator != "IM" && endianIndicator != "MI") {
                throw UnknownEndianIndicatorException(endianIndicator);
            }

            if (this->endianIndicator == "IM") {
                std::reverse(bytes.begin(), bytes.end());
            }
            std::stringstream hexadecimal;
            for(auto const& byte: bytes) {
                hexadecimal << std::hex << (int)byte;
            }
            return hexadecimal.str();
        }

        bool getBitFromByte(Byte byte, size_t index) const {
            if(index<0 || index > 7) {
                throw IndexException(7, index);
            }
            return static_cast<bool>((byte >> index) & 0x01);
        }

        void setEndianIndicator(const std::string &endianIndicator) {
            if (endianIndicator != "IM" && endianIndicator != "MI") {
                throw UnknownEndianIndicatorException(endianIndicator);
            }
            ByteParser::endianIndicator = endianIndicator;
        }

    private:
        std::string endianIndicator = "UNDEFINED";

        static constexpr size_t BYTE_SIZE = 8;

    };
}

#endif //COBRAMODELPARSER_BYTEPARSER_HPP
