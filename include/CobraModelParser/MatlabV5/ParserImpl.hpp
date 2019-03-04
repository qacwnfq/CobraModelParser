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
#include "CobraModelParser/MatlabV5/ArrayFlags.hpp"
#include "CobraModelParser/MatlabV5/Header.hpp"
#include "ArrayDimensions.hpp"
#include "ArrayName.hpp"
#include "FieldNameLength.hpp"
#include "FieldNames.hpp"

namespace CobraModelParser {
    namespace MatlabV5 {
        class ParserImpl : public Parser {
        public:
            Model parseModelFromFile(std::string filename) override {
                ByteParser byteParser;
                ByteQueue byteQueue = FileLoader::loadFileContentsAsByteQueue(filename);

                Header header(byteQueue, byteParser);
                const std::pair<Eigen::MatrixXd, Eigen::VectorXd> &data = parseBody(byteQueue, byteParser);

                return ModelBuilder()
                        .setModelOrigin(filename)
                        .setModelDescription(header.getHeaderText())
                        .setData(data.first, data.second)
                        .build();
            }

        private:
            std::pair<Eigen::MatrixXd, Eigen::VectorXd>
            parseBody(ByteQueue &byteQueue, const ByteParser &byteParser) const {
                TagParser tagParser(byteParser);
                Tag tag = tagParser.parseTag(byteQueue);
                if (byteQueue.getRemainingBytes() != tag.getNumberOfBytes()) {
                    throw UnexpectedSizeException(byteQueue.getRemainingBytes(), tag.getNumberOfBytes());
                }
                auto expectedType = DataTypeTable::lookUp(14);
                if (expectedType != tag.getType()) {
                    throw UnexpectedDataTypeException(expectedType.getSymbol(), tag.getType().getSymbol());
                }

                const ArrayFlags &arrayFlags = ArrayFlags::fromByteQueue(byteQueue, byteParser, tagParser);
                std::cout << "arrayFlags" << std::endl;
                std::cout << arrayFlags << std::endl;

                const ArrayDimensions &arrayDimensions = ArrayDimensions::fromByteQueue(byteQueue, byteParser,
                                                                                        tagParser);
                std::cout << arrayDimensions << std::endl;

                const ArrayName &name = ArrayName::fromByteQueue(byteQueue, byteParser, tagParser);
                std::cout << "name: " << name << std::endl;

                const FieldNameLength &fieldNameLength = FieldNameLength::fromByteQueue(byteQueue, byteParser);
                std::cout << "field name length " << fieldNameLength << std::endl;

                const FieldNames &fieldNames = FieldNames::fromByteQueue(byteQueue, byteParser, tagParser, fieldNameLength);

                return std::make_pair(Eigen::MatrixXd(), Eigen::VectorXd());
            }

        };
    }
}

#endif //COBRAMODELPARSER_MATLABV5_PARSERIMPL_HPP
