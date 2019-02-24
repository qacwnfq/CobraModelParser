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

    class UnexpectedFileType : public std::exception {
    public:
        UnexpectedFileType(const std::string &expectedFileType, const std::string &filename) :
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

    class UnknownDataType : public std::exception {
    public:
        UnknownDataType(const unsigned int &lookupValue) :
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

    class ReservedDataType : public std::exception {
    public:
        const char *what() const throw() override {
            std::string message = "Data type is reserved but not defined by standard.";
            char *buffer = new char[message.size() + 1];
            std::memcpy(buffer, message.c_str(), message.size() + 1);
            return buffer;
        }
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class UnkownEndianIndicator : public std::exception {
    public:
        UnkownEndianIndicator(const std::string& indicator) : indicator(indicator) {}

        const char *what() const throw() override {
            std::string message = "Endian Indicator " + indicator + " is unkown.";
            char *buffer = new char[message.size() + 1];
            std::memcpy(buffer, message.c_str(), message.size() + 1);
            return buffer;
        }

    private:
        std::string indicator;
    };


}

#endif //COBRAMODELPARSER_EXCEPTIONS_HPP
