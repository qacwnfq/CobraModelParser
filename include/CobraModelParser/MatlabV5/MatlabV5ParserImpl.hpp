#ifndef COBRAMODELPARSER_MATLABPARSERV5IMPL_HPP
#define COBRAMODELPARSER_MATLABPARSERV5IMPL_HPP

#include <algorithm>
#include <fstream>
#include <vector>
#include <ostream>

#include "CobraModelParser/Exceptions.hpp"
#include "CobraModelParser/FileLoader.hpp"
#include "MatlabV5DataElement.hpp"
#include "CobraModelParser/ModelBuilder.hpp"
#include "CobraModelParser/Parser.hpp"

namespace CobraModelParser {

    class MatlabV5ParserImpl : public Parser {
    private:
        struct Header;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    public:
        Model parseModelFromFile(std::string filename) override {
            ByteQueue byteQueue = FileLoader::loadFileContentsAsByteQueue(filename);
            Header header(byteQueue);

//            auto dataElements = parseBody(filename, header);
//            assert(dataElements.size() == 1);
//
            return ModelBuilder()
                    .setModelDescription(header.getHeaderText())
                    .setModelOrigin(filename)
//                    .setData(dataElements[0])
                    .build();
        }

        std::vector<MatlabV5DataElement> parseBody(const std::string &filename, const Header &header) const {
//            std::ifstream file(filename, std::ios::binary | std::ios::in);
//            file.seekg(Header::totalSize, std::ifstream::beg);
//
            std::vector<MatlabV5DataElement> dataElements;

//            while (!file.eof()) {
//                MatlabV5DataElement dataElement = MatlabV5DataElement::fromFileStream(file, header.endianIndicator);
//                if (dataElement.getDataType().getSymbol() != "EMPTY") {
//                    dataElements.push_back(dataElement);
//                }
//            }
//            file.close();

            return dataElements;
        }


    private:

        class Header {
        public:

            Header(ByteQueue &byteQueue) {
                ByteParser byteParser;
                std::vector<char> headerBytes = byteQueue.popByteBlocks(totalSize);
                headerText = byteParser.parseString(
                        std::vector<char>(headerBytes.begin(), headerBytes.begin() + headerTextSize));

                const std::string expectedType = "MATLAB 5.0 MAT-file";
                if (std::mismatch(expectedType.begin(), expectedType.end(),
                                  headerText.begin()).first != expectedType.end()) {
                    throw UnexpectedFileTypeException(expectedType);
                }

                endianIndicator = byteParser.parseString(
                        std::vector<char>(headerBytes.begin() + headerTextSize + versionFlagSize,
                                          headerBytes.begin() + totalSize)
                );

                std::cout << endianIndicator << std::endl;

                byteParser.setEndianIndicator(endianIndicator);

                version = byteParser.parseHexadeximalAsString(
                        std::vector<char>(headerBytes.begin() + headerTextSize,
                                          headerBytes.begin() + headerTextSize + versionFlagSize)
                );

            }

            friend std::ostream &operator<<(std::ostream &os, const Header &header) {
                os << "headerText: " << header.headerText << " version: " << header.version << " endianIndicator: "
                   << header.endianIndicator;
                return os;
            }

            const std::string &getHeaderText() const {
                return headerText;
            }

            const std::string &getVersion() const {
                return version;
            }

            const std::string &getEndianIndicator() const {
                return endianIndicator;
            }

        private:

            static constexpr size_t headerTextSize = 124;
            static constexpr size_t versionFlagSize = 2;
            static constexpr size_t endianIndicatorFlagSize = 2;
            static constexpr size_t totalSize = headerTextSize + versionFlagSize + endianIndicatorFlagSize;

            std::string headerText;
            std::string version;
            std::string endianIndicator;
        };
    };
}

#endif //COBRAMODELPARSER_MATLABPARSERV5IMPL_HPP
