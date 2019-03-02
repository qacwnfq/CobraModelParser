#ifndef COBRAMODELPARSER_MATLABV5_PARSERIMPL_HPP
#define COBRAMODELPARSER_MATLABV5_PARSERIMPL_HPP

#include <algorithm>
#include <fstream>
#include <vector>
#include <ostream>

#include "CobraModelParser/Exceptions.hpp"
#include "CobraModelParser/FileLoader.hpp"
#include "CobraModelParser/ModelBuilder.hpp"
#include "CobraModelParser/Parser.hpp"
#include "CobraModelParser/MatlabV5/Header.hpp"

namespace CobraModelParser::MatlabV5 {

    class ParserImpl : public Parser {
    public:
        Model parseModelFromFile(std::string filename) override {
            ByteParser byteParser;
            ByteQueue byteQueue = FileLoader::loadFileContentsAsByteQueue(filename);
            Header header(byteQueue, byteParser);

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
    };
}

#endif //COBRAMODELPARSER_MATLABV5_PARSERIMPL_HPP
