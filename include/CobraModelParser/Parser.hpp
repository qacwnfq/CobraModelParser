#ifndef COBRAMODELPARSER_PARSER_HPP
#define COBRAMODELPARSER_PARSER_HPP

#include <fstream>
#include <string>

#include "CobraModelParser/Exceptions.hpp"
#include "MatlabV5File.hpp"
#include "FileLoader.hpp"
#include "Header.hpp"

namespace CobraModelParser {

    class Parser {
    public:
        MatlabV5File parseMatlabV5File(std::string fileName) {
            ByteQueue byteQueue = FileLoader::loadFileContents(fileName);
            ByteParser byteParser;
            Header header = Header(byteQueue, byteParser);
            std::cout << header << std::endl;
            DataElementNode dataElementNode;

            return MatlabV5File(header, dataElementNode, fileName);

        };
    };

}
#endif //COBRAMODELPARSER_PARSER_HPP
