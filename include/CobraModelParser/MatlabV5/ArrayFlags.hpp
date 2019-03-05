#include <utility>

#ifndef COBRAMODELPARSER_MATLABV5_ARRAYFLAGS_HPP
#define COBRAMODELPARSER_MATLABV5_ARRAYFLAGS_HPP

#include <ostream>
#include <CobraModelParser/ByteParser.hpp>
#include "CobraModelParser/ByteQueue.hpp"
#include "CobraModelParser/MatlabV5/ArrayType.hpp"
#include "CobraModelParser/MatlabV5/ArrayTypeTable.hpp"
#include "CobraModelParser/MatlabV5/TagParser.hpp"

namespace CobraModelParser {
    namespace MatlabV5 {
        class ArrayFlags {
        public:
            static ArrayFlags
            fromByteQueue(ByteQueue &byteQueue, const ByteParser &byteParser, const TagParser &tagParser) {
                Tag tag = tagParser.parseTag(byteQueue);
                if (tag.getType() != DataTypeTable::lookUp(6)) {
                    throw UnexpectedDataTypeException(DataTypeTable::lookUp(6).getSymbol(), tag.getType().getSymbol());
                }
                if (tag.getNumberOfBytes() != 8) {
                    throw UnexpectedSizeException(8, tag.getNumberOfBytes());
                }

                std::vector<Byte> byteBlock = byteQueue.popByteBlock();
                if(byteParser.getEndianIndicator() == "MI") {
                    std::reverse(byteBlock.begin(), byteBlock.end());
                }

                Byte flags = byteBlock[1];
                bool complex = byteParser.getBitFromByte(flags, 4);
                bool global = byteParser.getBitFromByte(flags, 5);
                bool logical = byteParser.getBitFromByte(flags, 6);

                const auto arrayTypeLookUp = byteParser.parseIntegerType<size_t>(
                        std::vector<Byte>(byteBlock.begin(), byteBlock.begin() + 1));
                const ArrayType &arrayType = ArrayTypeTable::lookUp(arrayTypeLookUp);

                return ArrayFlags(tag, arrayType, complex, global, logical);
            }

            ArrayFlags() = default;

            ArrayFlags(
                    Tag tag,
                    ArrayType arrayType,
                    bool complex,
                    bool global,
                    bool logical) : tag(std::move(tag)),
                                    arrayType(std::move(arrayType)),
                                    complex(complex),
                                    global(global),
                                    logical(logical) {}

            const Tag &getTag() const {
                return tag;
            }

            friend std::ostream &operator<<(std::ostream &os, const ArrayFlags &flags) {
                os << "arrayType: " << flags.arrayType << " complex: " << flags.complex << " global: " << flags.global
                   << " logical: " << flags.logical;
                return os;
            }


            const ArrayType &getArrayType() const {
                return arrayType;
            }

            bool isComplex() const {
                return complex;
            }

            bool isGlobal() const {
                return global;
            }

            bool isLogical() const {
                return logical;
            }

        private:
            Tag tag;
            ArrayType arrayType;
            bool complex;
            bool global;
            bool logical;
        };
    }
}

#endif //COBRAMODELPARSER_MATLABV5_ARRAYFLAGS_HPP
