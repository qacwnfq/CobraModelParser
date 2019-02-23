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

}

#endif //COBRAMODELPARSER_EXCEPTIONS_HPP
