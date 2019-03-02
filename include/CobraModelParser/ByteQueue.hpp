#ifndef COBRAMODELPARSER_BYTEQUEUE_HPP
#define COBRAMODELPARSER_BYTEQUEUE_HPP

#include <algorithm>
#include <string>
#include <vector>

#include "CobraModelParser/Byte.hpp"
#include "CobraModelParser/Exceptions.hpp"

namespace CobraModelParser {
    class ByteQueue {
    public:
        static constexpr size_t BYTE_BLOCK_SIZE = 8;

        ByteQueue(const std::vector<byte> &bytes) : bytes(bytes) {
            if (bytes.size() % BYTE_BLOCK_SIZE != 0) {
                throw ByteQueueConstructionException(bytes.size(), BYTE_BLOCK_SIZE);
            }
            std::reverse(this->bytes.begin(), this->bytes.end());
        }

        std::vector<byte> popByteBlock() {
            std::vector<byte> byteBlock;
            for (size_t i = 0; i < BYTE_BLOCK_SIZE; ++i) {
                byteBlock.push_back(bytes[bytes.size() - 1]);
                bytes.pop_back();
            }
            return byteBlock;
        }

        std::vector<byte> popByteBlocks(size_t numberOfByteBlocksToParse) {
            std::vector<byte> byteBlocks;
            for (size_t i = 0; i < numberOfByteBlocksToParse; ++i) {
                std::vector<byte> byteBlock = popByteBlock();
                byteBlocks.insert(byteBlocks.end(), byteBlock.begin(), byteBlock.end());
            }
            return byteBlocks;
        }

        void popUndefinedByteBlock() {
            for (size_t i = 0; i < BYTE_BLOCK_SIZE; ++i) {
                bytes.pop_back();
            }
        }

        void popUndefinedByteBlocks(size_t numberofByteBlocksToParse) {
            for (size_t i = 0; i < numberofByteBlocksToParse; ++i) {
                popUndefinedByteBlock();
            }
        }

        size_t getRemainingBytes() {
            return bytes.size();
        }

    private:
        std::vector<byte> bytes;
    };
}

#endif //COBRAMODELPARSER_BYTEQUEUE_HPP
