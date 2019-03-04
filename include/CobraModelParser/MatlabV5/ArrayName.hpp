#ifndef COBRAMODELPARSER_MATLABV5_ARRAYNAME_HPP
#define COBRAMODELPARSER_MATLABV5_ARRAYNAME_HPP

#include <cmath>
#include <string>
#include <CobraModelParser/ByteQueue.hpp>
#include <CobraModelParser/ByteParser.hpp>
#include <ostream>

#include "Tag.hpp"
#include "TagParser.hpp"

namespace CobraModelParser {
    namespace MatlabV5 {
        class ArrayName {
        public:
            ArrayName(const Tag &tag, const std::string &name) : tag(tag), name(name) {}

            friend std::ostream &operator<<(std::ostream &os, const ArrayName &name) {
                os << "tag: " << name.tag << " name: " << name.name;
                return os;
            }

            ArrayName() = default;

            const Tag &getTag() const {
                return tag;
            }

            const std::string &getName() const {
                return name;
            }

            static ArrayName
            fromByteQueue(ByteQueue &byteQueue, const ByteParser &byteParser, const TagParser &tagParser) {
                Tag tag = tagParser.parseTag(byteQueue);

                const std::vector<Byte> &byteBlocks = byteQueue.popByteBlocks(
                        std::ceil(static_cast<long double>(tag.getNumberOfBytes()) / ByteQueue::BYTE_BLOCK_SIZE));

                std::string name = byteParser.parseString(std::vector<Byte>(byteBlocks.begin(),
                        byteBlocks.begin()+tag.getNumberOfBytes()));

                return ArrayName(tag, name);
            }


        private:
            Tag tag;
            std::string name;
        };
    }
}

#endif //COBRAMODELPARSER_MATLABV5_ARRAYNAME_HPP
