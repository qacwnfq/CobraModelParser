#ifndef COBRAMODELPARSER_MATLABPARSERV5IMPL_HPP
#define COBRAMODELPARSER_MATLABPARSERV5IMPL_HPP

#include <algorithm>
#include <fstream>
#include <vector>
#include <ostream>

#include "CobraModelParser/Exceptions.hpp"
#include "CobraModelParser/MatlabV5DataElement.hpp"
#include "CobraModelParser/ModelBuilder.hpp"
#include "CobraModelParser/Parser.hpp"

namespace CobraModelParser {

    class MatlabV5ParserImpl : public Parser {
    private:
        struct Header;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    public:
        Model parseModelFromFile(std::string filename) override {
            checkFileExists(filename);

            Header header = parseHeader(filename);

            auto dataElements = parseBody(filename, header);
            assert(dataElements.size() == 1);

            return ModelBuilder()
                    .setModelDescription(header.headerText)
                    .setModelOrigin(filename)
                    .setData(dataElements[0])
                    .build(header.endianIndicator);
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        std::vector<MatlabV5DataElement> parseBody(const std::string &filename, const Header &header) const {
            std::ifstream file(filename, std::ios::binary | std::ios::in);
            file.seekg(Header::size, std::ifstream::beg);

            std::vector<MatlabV5DataElement> dataElements;

            while (!file.eof()) {
                MatlabV5DataElement dataElement = MatlabV5DataElement::fromFileStream(file, header.endianIndicator);
                if (dataElement.getDataType().getSymbol() != "EMPTY") {
                    dataElements.push_back(dataElement);
                }
            }
            file.close();

            return dataElements;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        Header parseHeader(std::string filename) const {
            Header header;

            header = parseHeaderText(filename, header);
            checkFileIsMatlabV5Format(header, filename);

            header = parseVersionFlag(filename, header);
            header = parseEndianIndicatorFlag(filename, header);

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

        Header parseVersionFlag(const std::string &filename, Header header) const {
            std::ifstream file(filename, std::ios::binary | std::ios::in);
            file.seekg(Header::headerTextSize, std::ifstream::beg);

            std::vector<char> version(Header::versionFlagSize);
            file.read(&version[0], Header::versionFlagSize);
            header.version = std::string(version.begin(), version.end());

            file.close();
            return header;

        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        Header parseEndianIndicatorFlag(const std::string &filename, Header header) const {
            std::ifstream file(filename, std::ios::binary | std::ios::in);
            file.seekg(Header::headerTextSize + Header::versionFlagSize, std::ifstream::beg);

            std::vector<char> endianIndicator(Header::endianIndicatorFlagSize);
            file.read(&endianIndicator[0], Header::endianIndicatorFlagSize);
            header.endianIndicator = std::string(endianIndicator.begin(), endianIndicator.end());

            file.close();
            return header;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    private:

        void checkFileIsMatlabV5Format(Header header, const std::string &filename) const {
            const std::string expectedType = "MATLAB 5.0 MAT-file";
            if (std::mismatch(expectedType.begin(), expectedType.end(),
                              header.headerText.begin()).first != expectedType.end()) {
                throw UnexpectedFileTypeException(expectedType, filename);

            }
        };

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        struct Header {
            friend std::ostream &operator<<(std::ostream &os, const Header &header) {
                os << "headerText: " << header.headerText << " version: " << header.version << " endianIndicator: "
                   << header.endianIndicator;
                return os;
            }

            static constexpr size_t headerTextSize = 124;
            static constexpr size_t versionFlagSize = 2;
            static constexpr size_t endianIndicatorFlagSize = 2;
            static constexpr size_t size = headerTextSize + versionFlagSize + endianIndicatorFlagSize;

            std::string headerText;
            std::string version;
            std::string endianIndicator;
        };


    };
}

#endif //COBRAMODELPARSER_MATLABPARSERV5IMPL_HPP
