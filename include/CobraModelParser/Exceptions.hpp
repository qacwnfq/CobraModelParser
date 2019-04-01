#ifndef COBRAMODELPARSER_EXCEPTIONS_HPP
#define COBRAMODELPARSER_EXCEPTIONS_HPP

#include <exception>
#include <stdio.h>
#include <string>

#include "CobraModelParser/MatlabV5/ArrayType.hpp"
#include "CobraModelParser/MatlabV5/DataType.hpp"

namespace CobraModelParser {

    class FileNotFoundException : public std::exception {
    public:

        FileNotFoundException(const std::string &filename) : filename(filename) {}

        const char *what() const throw() override {
            std::string message = "File " + filename + " could not be found.";
            char *buffer = new char[message.size() + 1];
            std::memcpy(buffer, message.c_str(), message.size() + 1);
            return buffer;
        }


    private:
        std::string filename;

    };

    class UnexpectedFileTypeException : public std::exception {
    public:
        UnexpectedFileTypeException(const std::string &expectedFileType) :
                expectedFileType(expectedFileType) {}

        const char *what() const throw() override {
            std::string message = "File is not of type " + expectedFileType + ".";
            char *buffer = new char[message.size() + 1];
            std::memcpy(buffer, message.c_str(), message.size() + 1);
            return buffer;
        }

    private:
        std::string expectedFileType;

    };

    class UnknownDataTypeException : public std::exception {
    public:
        UnknownDataTypeException(const size_t &lookupValue) :
                lookupValue(lookupValue) {}

        const char *what() const throw() override {
            std::string message =
                    "Tried to parse unkown rawData type. Lookup value was " + std::to_string(lookupValue) + ".";
            char *buffer = new char[message.size() + 1];
            std::memcpy(buffer, message.c_str(), message.size() + 1);
            return buffer;
        }

    private:
        const size_t lookupValue;

    };

    class ReservedDataTypeException : public std::exception {
    public:
        const char *what() const throw() override {
            std::string message = "Data type is reserved but not defined by standard.";
            char *buffer = new char[message.size() + 1];
            std::memcpy(buffer, message.c_str(), message.size() + 1);
            return buffer;
        }
    };

    class UnexpectedDataTypeException : public std::exception {
    public:
        UnexpectedDataTypeException(std::string expectedType, std::string actualType)
                : expectedType(std::move(expectedType)), actualType(std::move(actualType)) {}

        const char *what() const throw() override {
            std::string message =
                    "Expected Data Type " + expectedType + ", but got " + actualType + ".";
            char *buffer = new char[message.size() + 1];
            std::memcpy(buffer, message.c_str(), message.size() + 1);
            return buffer;
        }

    private:
        std::string expectedType;
        std::string actualType;
    };

    class UnknownEndianIndicatorException : public std::exception {
    public:
        UnknownEndianIndicatorException(const std::string &indicator) : indicator(indicator) {}

        const char *what() const throw() override {
            std::string message = "Endian Indicator " + indicator + " is unkown.";
            char *buffer = new char[message.size() + 1];
            std::memcpy(buffer, message.c_str(), message.size() + 1);
            return buffer;
        }

    private:
        std::string indicator;
    };

    class UnexpectedSizeException : public std::exception {
    public:
        UnexpectedSizeException(size_t expectedSize, size_t actualSize) : expectedSize(expectedSize),
                                                                          actualSize(actualSize) {}

        const char *what() const throw() override {
            std::string message =
                    "Expected Size " + std::to_string(expectedSize) + ", but got " + std::to_string(actualSize) + ".";
            char *buffer = new char[message.size() + 1];
            std::memcpy(buffer, message.c_str(), message.size() + 1);
            return buffer;
        }

    private:
        size_t expectedSize;
        size_t actualSize;
    };

    class IndexException : public std::exception {
    public:
        IndexException(size_t upperBound, size_t actualIndex) : upperBound(upperBound), actualIndex(actualIndex) {}

        const char *what() const throw() override {
            std::string message =
                    "Expected Index to be between 0 and " + std::to_string(upperBound) + ", but got " +
                    std::to_string(actualIndex) + ".";
            char *buffer = new char[message.size() + 1];
            std::memcpy(buffer, message.c_str(), message.size() + 1);
            return buffer;
        }

    private:
        size_t upperBound;
        size_t actualIndex;
    };

    template<typename T>
    class ByteArrayTooLargeException : public std::exception {
    public:
        const char *what() const throw() override {
            std::string message = "ByteArray too large to parse into return type.";
            char *buffer = new char[message.size() + 1];
            std::memcpy(buffer, message.c_str(), message.size() + 1);
            return buffer;
        }
    };

}

#endif //COBRAMODELPARSER_EXCEPTIONS_HPP
