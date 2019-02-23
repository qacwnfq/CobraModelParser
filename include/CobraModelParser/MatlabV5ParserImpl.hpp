#ifndef COBRAMODELPARSER_MATLABPARSERV5IMPL_HPP
#define COBRAMODELPARSER_MATLABPARSERV5IMPL_HPP

#include <algorithm>
#include <fstream>
#include <vector>
#include <ostream>

#include "CobraModelParser/Exceptions.hpp"
#include "CobraModelParser/Parser.hpp"

namespace CobraModelParser {

    class MatlabV5ParserImpl : public Parser {

        struct Header;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    public:
        Model parseModelFromFile(std::string filename) override {
            checkFileExists(filename);
            parseHeader(filename);

            return Model();
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        Header parseHeader(std::string filename) const {
            Header header;

            header = parseHeaderText(filename, header);
            checkFileIsMatlabV5Format(header, filename);

            header = parseHeaderFlags(filename, header);

            return header;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        Header parseHeaderText(const std::string &filename, Header header) const {
            std::ifstream file(filename, std::ios::binary | std::ios::in);
            std::vector<char> headerText(Header::headerTextSize);
            file.read(&headerText[0], Header::headerTextSize);
            header.headerText = std::string(headerText.begin(), headerText.end());
            file.close();
            return header;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        Header parseHeaderFlags(const std::string &filename, Header header) const {
            std::ifstream file(filename, std::ios::binary | std::ios::in);
            file.seekg(Header::headerTextSize);
            file.seekg(0, file.end);
            std::cout << file.gcount() << std::endl;
            file.seekg(Header::headerTextSize, file.beg);


            std::vector<char> version(Header::versionFlagSize);
            file.read(&version[0], Header::versionFlagSize);
            header.version = std::string(version.begin(), version.end());

            std::vector<char> endianIndicator(Header::endianIndicatorFlagSize);
            file.read(&endianIndicator[0], Header::endianIndicatorFlagSize);
            header.endianIndicator = std::string(endianIndicator.begin(), endianIndicator.end());

            std::cout << version[0] << std::endl;
            std::cout << version[1] << std::endl;
            std::cout << endianIndicator[0] << std::endl;
            std::cout << endianIndicator[1] << std::endl;
            std::cout << header << std::endl;

            file.close();
            return header;
        }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    private:
        void checkFileIsMatlabV5Format(Header header, const std::string& filename) const {
            const std::string expectedType = "MATLAB 5.0 MAT-file";
            if (std::mismatch(expectedType.begin(), expectedType.end(),
                              header.headerText.begin()).first != expectedType.end()) {
                throw UnexpectedFileType(expectedType, filename);

            }
        };

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        struct Header {
            friend std::ostream &operator<<(std::ostream &os, const Header &header) {
                os << "headerText: " << header.headerText << " version: " << header.version << " endianIndicator: "
                   << header.endianIndicator;
                return os;
            }

            static constexpr size_t headerTextSize = 116;
            static constexpr size_t versionFlagSize = 2;
            static constexpr size_t endianIndicatorFlagSize = 2;

            std::string headerText;
            std::string version;
            std::string endianIndicator;
        };


    };
}

#endif //COBRAMODELPARSER_MATLABPARSERV5IMPL_HPP
