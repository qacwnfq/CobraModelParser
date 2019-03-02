#define BOOST_TEST_MODULE TagParserTest
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>

#include "CobraModelParser/MatlabV5/TagParser.hpp"

BOOST_AUTO_TEST_SUITE(TAGPARSER_SUITE)

    BOOST_AUTO_TEST_CASE(PARSE_TAG_BIG_ENDIAN) {

        CobraModelParser::ByteParser byteParser;
        byteParser.setEndianIndicator("MI");

        std::vector<CobraModelParser::byte> tag {
                0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x08
        };
        CobraModelParser::MatlabV5::DataType expectedType =
                CobraModelParser::MatlabV5::DataTypeTable::lookUp(1);
        size_t expectedNumberOfBytes = 8;

        CobraModelParser::MatlabV5::TagParser tagParser(byteParser);
        CobraModelParser::MatlabV5::Tag actualTag = tagParser.parseTag(tag);

        BOOST_CHECK(actualTag.getType() == expectedType);
        BOOST_CHECK(actualTag.getNumberOfBytes() == expectedNumberOfBytes);
    }

    BOOST_AUTO_TEST_CASE(PARSE_TAG_LITTLE_ENDIAN) {

            CobraModelParser::ByteParser byteParser;
            byteParser.setEndianIndicator("IM");

            std::vector<CobraModelParser::byte> tag {
                    0x01, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00
            };
            CobraModelParser::MatlabV5::DataType expectedType =
                    CobraModelParser::MatlabV5::DataTypeTable::lookUp(1);
            size_t expectedNumberOfBytes = 8;

            CobraModelParser::MatlabV5::TagParser tagParser(byteParser);
            CobraModelParser::MatlabV5::Tag actualTag = tagParser.parseTag(tag);

            BOOST_CHECK(actualTag.getType() == expectedType);
            BOOST_CHECK(actualTag.getNumberOfBytes() == expectedNumberOfBytes);
    }

BOOST_AUTO_TEST_SUITE_END()
