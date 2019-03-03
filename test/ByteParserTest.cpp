#define BOOST_TEST_MODULE ByteParserTest
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>

#include "CobraModelParser/ByteParser.hpp"

BOOST_AUTO_TEST_SUITE(BYTEPARSER_SUITE)

    BOOST_AUTO_TEST_CASE(SIZE_T_LITTLE_ENDIAN_1_BYTE) {
        size_t expected = 122;
        std::vector<CobraModelParser::Byte> bytes = {122};

        CobraModelParser::ByteParser byteParser("IM");
        size_t actual = byteParser.parseNumericType<size_t>(bytes);
        BOOST_CHECK(actual == expected);
    }

    BOOST_AUTO_TEST_CASE(SIZE_T_BIG_ENDIAN_1_BYTE) {
        size_t expected = 6;
        std::vector<CobraModelParser::Byte> bytes = {6};

        CobraModelParser::ByteParser byteParser("MI");
        size_t actual = byteParser.parseNumericType<size_t>(bytes);
        BOOST_CHECK(actual == expected);
    }

    BOOST_AUTO_TEST_CASE(SIZE_T_LITTLE_ENDIAN_2_BYTES) {
        size_t expected = 513;
        std::vector<CobraModelParser::Byte> bytes = {0x01, 0x02};

        CobraModelParser::ByteParser byteParser("IM");
        size_t actual = byteParser.parseNumericType<size_t>(bytes);
        BOOST_CHECK(actual == expected);
    }

    BOOST_AUTO_TEST_CASE(SIZE_T_BIG_ENDIAN_2_BYTES) {
        size_t expected = 258;
        std::vector<CobraModelParser::Byte> bytes = {0x01, 0x02};

        CobraModelParser::ByteParser byteParser("MI");
        size_t actual = byteParser.parseNumericType<size_t>(bytes);
        BOOST_CHECK(actual == expected);
    }

    BOOST_AUTO_TEST_CASE(SIZE_T_LITTLE_ENDIAN_4_BYTES) {
        size_t expected = 16909060;
        std::vector<CobraModelParser::Byte> bytes = {0x04, 0x03, 0x02, 0x01};

        CobraModelParser::ByteParser byteParser("IM");
        size_t actual = byteParser.parseNumericType<size_t>(bytes);
        BOOST_CHECK(actual == expected);
    }

    BOOST_AUTO_TEST_CASE(SIZE_T_BIG_ENDIAN_4_BYTES) {
        size_t expected = 16909060;
        std::vector<CobraModelParser::Byte> bytes = {0x01, 0x02, 0x03, 0x04};

        CobraModelParser::ByteParser byteParser("MI");
        size_t actual = byteParser.parseNumericType<size_t>(bytes);
        BOOST_CHECK(actual == expected);
    }

    BOOST_AUTO_TEST_CASE(SIZE_T_THROWS_EXCEPTION_WHEN_NO_ENDIAN) {
        std::vector<CobraModelParser::Byte> bytes;

        CobraModelParser::ByteParser byteParser;
        BOOST_CHECK_THROW(byteParser.parseNumericType<size_t>(bytes),
                          CobraModelParser::UnknownEndianIndicatorException);
    }

    BOOST_AUTO_TEST_CASE(BIT_FROM_BYTE_THROWS_EXCEPTION_WHEN_INDEX_WRONG) {
        CobraModelParser::ByteParser byteParser;
        CobraModelParser::Byte byte = 0x6C;

        BOOST_CHECK_THROW(byteParser.getBitFromByte(byte, 8), CobraModelParser::IndexException);
        BOOST_CHECK_THROW(byteParser.getBitFromByte(byte, -1), CobraModelParser::IndexException);
    }

    BOOST_AUTO_TEST_CASE(BIT_FROM_BYTE) {
        CobraModelParser::ByteParser byteParser;
        CobraModelParser::Byte byte = 0x6C;

        BOOST_CHECK(!byteParser.getBitFromByte(byte, 0));
        BOOST_CHECK(!byteParser.getBitFromByte(byte, 1));
        BOOST_CHECK(byteParser.getBitFromByte(byte, 2));
        BOOST_CHECK(byteParser.getBitFromByte(byte, 3));
        BOOST_CHECK(!byteParser.getBitFromByte(byte, 4));
        BOOST_CHECK(byteParser.getBitFromByte(byte, 5));
        BOOST_CHECK(byteParser.getBitFromByte(byte, 6));
        BOOST_CHECK(!byteParser.getBitFromByte(byte, 7));

    }

BOOST_AUTO_TEST_SUITE_END()
