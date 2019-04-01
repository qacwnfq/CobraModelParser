#include <utility>

#ifndef COBRAMODELPARSER_BYTEQUEUE_HPP
#define COBRAMODELPARSER_BYTEQUEUE_HPP

#include "Byte.hpp"
#include <deque>
#include <vector>

namespace CobraModelParser {
    class ByteQueue {
    public:
        explicit ByteQueue(std::deque<Byte> &bytes) : bytes(std::move(bytes)) {}

        size_t getNumberOfBytes() {
            return bytes.size();
        }

        std::vector<Byte> pop_front(size_t numberOfBytesToPop) {
            std::vector<Byte> poppedBytes;
            poppedBytes.reserve(numberOfBytesToPop);

            poppedBytes.insert(poppedBytes.begin(),
                               std::make_move_iterator(bytes.begin()),
                               std::make_move_iterator(bytes.begin() + numberOfBytesToPop));
            for(size_t i=0; i<numberOfBytesToPop; ++i) {
                bytes.pop_front();
            }

            return poppedBytes;
        }

        std::vector<Byte> pop_back(size_t numberOfBytesToPop) {
            std::vector<Byte> poppedBytes;
            poppedBytes.reserve(numberOfBytesToPop);

            poppedBytes.insert(poppedBytes.begin(),
                               std::make_move_iterator(bytes.end()-numberOfBytesToPop),
                               std::make_move_iterator(bytes.end()));
            for(size_t i=0; i<numberOfBytesToPop; ++i) {
                bytes.pop_back();
            }

            return poppedBytes;
        }

    private:
        std::deque<Byte> bytes;
    };
}

#endif //COBRAMODELPARSER_BYTEQUEUE_HPP
