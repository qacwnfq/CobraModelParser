#ifndef COBRAMODELPARSER_EXCEPTIONS_HPP
#define COBRAMODELPARSER_EXCEPTIONS_HPP

#include <exception>
#include <stdio.h>
#include <string>

#include "CobraModelParser/MatlabV5ArrayDataType.hpp"
#include "CobraModelParser/MatlabV5DataType.hpp"

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

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class UnexpectedFileTypeException : public std::exception {
    public:
        UnexpectedFileTypeException(const std::string &expectedFileType, const std::string &filename) :
                expectedFileType(expectedFileType),
                filename(filename) {}

        const char *what() const throw() override {
            std::string message = "File " + filename + " is not of type " + expectedFileType + ".";
            char *buffer = new char[message.size() + 1];
            std::memcpy(buffer, message.c_str(), message.size() + 1);
            return buffer;
        }

    private:
        std::string expectedFileType;
        std::string filename;

    };

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class ReservedDataTypeException : public std::exception {
    public:
        const char *what() const throw() override {
            std::string message = "Data type is reserved but not defined by standard.";
            char *buffer = new char[message.size() + 1];
            std::memcpy(buffer, message.c_str(), message.size() + 1);
            return buffer;
        }
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class UnexpectedDataTypeException : public std::exception {
    public:
        UnexpectedDataTypeException(const MatlabV5DataType &expectedType, const MatlabV5DataType &actualType)
                : expectedType(expectedType), actualType(actualType) {}

        const char *what() const throw() override {
            std::string message =
                    "Expected Data Type " + expectedType.getSymbol() + ", but got " + actualType.getSymbol() + ".";
            char *buffer = new char[message.size() + 1];
            std::memcpy(buffer, message.c_str(), message.size() + 1);
            return buffer;
        }

    private:
        MatlabV5DataType expectedType;
        MatlabV5DataType actualType;
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class UnexpectedArrayDataTypeException : public std::exception {
    public:
        UnexpectedArrayDataTypeException(const MatlabV5ArrayDataType &expectedType, const MatlabV5ArrayDataType &actualType)
                : expectedType(expectedType), actualType(actualType) {}

        const char *what() const throw() override {
            std::string message =
                    "Expected Data Type " + expectedType.getSymbol() + ", but got " + actualType.getSymbol() + ".";
            char *buffer = new char[message.size() + 1];
            std::memcpy(buffer, message.c_str(), message.size() + 1);
            return buffer;
        }

    private:
        MatlabV5ArrayDataType expectedType;
        MatlabV5ArrayDataType actualType;
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
