#ifndef COBRAMODELPARSER_MATLABV5_HEADER_HPP
#define COBRAMODELPARSER_MATLABV5_HEADER_HPP

#include "CobraModelParser/ByteParser.hpp"
#include "CobraModelParser/ByteQueue.hpp"

namespace CobraModelParser {
    namespace MatlabV5 {
        class Header {
        public:
            Header(ByteQueue &byteQueue, ByteParser &byteParser) {
                std::vector<Byte> headerBytes = byteQueue.popByteBlocks(sizeInByteBlocks);
                headerText = byteParser.parseString(
                        std::vector<Byte>(headerBytes.begin(), headerBytes.begin() + headerTextSize));

                const std::string expectedType = "MATLAB 5.0 MAT-file";
                if (std::mismatch(expectedType.begin(), expectedType.end(),
                                  headerText.begin()).first != expectedType.end()) {
                    throw UnexpectedFileTypeException(expectedType);
                }

                endianIndicator = byteParser.parseString(
                        std::vector<Byte>(headerBytes.begin() + headerTextSize + versionFlagSize,
                                          headerBytes.end())
                );

                byteParser.setEndianIndicator(endianIndicator);

                version = byteParser.parseHexadeximalAsString(
                        std::vector<Byte>(headerBytes.begin() + headerTextSize,
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
            static constexpr size_t sizeInByteBlocks = (headerTextSize + versionFlagSize + endianIndicatorFlagSize) /
                                                       ByteQueue::BYTE_BLOCK_SIZE;

            std::string headerText;
            std::string version;
            std::string endianIndicator;
        };
    }
}

#endif //COBRAMODELPARSER_MATLABV5_HEADER_HPP
