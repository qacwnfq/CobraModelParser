#ifndef COBRAMODELPARSER_EXCEPTIONS_HPP
#define COBRAMODELPARSER_EXCEPTIONS_HPP

#include <exception>
#include <stdio.h>
#include <string>

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
        UnknownDataTypeException(const unsigned int &lookupValue) :
                lookupValue(lookupValue) {}

        const char *what() const throw() override {
            std::string message =
                    "Tried to parse unkown data type. Lookup value was " + std::to_string(lookupValue) + ".";
            char *buffer = new char[message.size() + 1];
            std::memcpy(buffer, message.c_str(), message.size() + 1);
            return buffer;
        }

    private:
        const unsigned int lookupValue;

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

    class UnknownEndianIndicatorException : public std::exception {
    public:
        UnknownEndianIndicatorException(const std::string& indicator) : indicator(indicator) {}

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
