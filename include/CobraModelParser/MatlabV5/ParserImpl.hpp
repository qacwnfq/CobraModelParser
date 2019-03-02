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
#include "CobraModelParser/MatlabV5/Body.hpp"

namespace CobraModelParser {
    namespace MatlabV5 {
        class ParserImpl : public Parser {
        public:
            Model parseModelFromFile(std::string filename) override {
                ByteParser byteParser;
                ByteQueue byteQueue = FileLoader::loadFileContentsAsByteQueue(filename);

                Header header(byteQueue, byteParser);
                Body body(byteQueue, byteParser);
                //            auto dataElements = parseBody(filename, header);
                //            assert(dataElements.size() == 1);
                //
                return ModelBuilder()
                .setModelOrigin(filename)
                .setModelDescription(header.getHeaderText())
                .build();
            }

        private:
            ModelBuilder addBodyDataToModel(ModelBuilder& modelBuilder) {

            }
        };
    }
}

#endif //COBRAMODELPARSER_MATLABV5_PARSERIMPL_HPP
