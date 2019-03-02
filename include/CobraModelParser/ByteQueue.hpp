#ifndef COBRAMODELPARSER_BYTEQUEUE_HPP
#define COBRAMODELPARSER_BYTEQUEUE_HPP

#include <algorithm>
#include <string>
#include <vector>

#include "CobraModelParser/Exceptions.hpp"
#include "Exceptions.hpp"

namespace CobraModelParser {
    class ByteQueue {
    public:
        ByteQueue(const std::vector<char> &bytes) : bytes(bytes) {
            if (bytes.size() % BYTE_BLOCK_SIZE != 0) {
                throw ByteQueueConstructionException(bytes.size(), BYTE_BLOCK_SIZE);
            }
            std::reverse(this->bytes.begin(), this->bytes.end());
        }

        std::vector<char> popByteBlock() {
            std::vector<char> byteBlock;
            for (size_t i = 0; i < BYTE_BLOCK_SIZE; ++i) {
                byteBlock.push_back(bytes[bytes.size() - 1]);
                bytes.pop_back();
            }
            return byteBlock;
        }

        std::vector<char> popByteBlocks(size_t numberOfByteBlocksToParse) {
            std::vector<char> byteBlocks;
            for (size_t i = 0; i < numberOfByteBlocksToParse; ++i) {
                std::vector<char> byteBlock = popByteBlock();
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
        static constexpr size_t BYTE_BLOCK_SIZE = 8;
        std::vector<char> bytes;
    };
}

#endif //COBRAMODELPARSER_BYTEQUEUE_HPP
