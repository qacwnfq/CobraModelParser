#define BOOST_TEST_MODULE ByteParserTest
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>

#include "CobraModelParser/ByteParser.hpp"

BOOST_AUTO_TEST_SUITE(BYTEPARSER_SUITE)

    BOOST_AUTO_TEST_CASE(SIZE_T_LITTLE_ENDIAN_1_BYTE) {
        size_t expected = 122;
        std::vector<char> bytes = { 122 };

        size_t actual = CobraModelParser::ByteParser::parseSize_t(bytes, "IM");
        BOOST_CHECK(actual == expected);
    }

    BOOST_AUTO_TEST_CASE(SIZE_T_BIG_ENDIAN_1_BYTE) {
        size_t expected = 6;
        std::vector<char> bytes = { 6 };

        size_t actual = CobraModelParser::ByteParser::parseSize_t(bytes, "MI");
        BOOST_CHECK(actual == expected);
    }

    BOOST_AUTO_TEST_CASE(SIZE_T_LITTLE_ENDIAN_2_BYTES) {
        size_t expected = 403;
        std::vector<char> bytes = { 22, 3};

        size_t actual = CobraModelParser::ByteParser::parseSize_t(bytes, "IM");
        std::cout << "actual: " << actual << " , expected: " << expected << std::endl;
        BOOST_CHECK(actual == expected);
    }

    BOOST_AUTO_TEST_CASE(SIZE_T_BIG_ENDIAN_2_BYTES) {
        size_t expected = 403;
        std::vector<char> bytes = { 3, 22};

        size_t actual = CobraModelParser::ByteParser::parseSize_t(bytes, "MI");
        BOOST_CHECK(actual == expected);
    }

    BOOST_AUTO_TEST_CASE(SIZE_T_LITTLE_ENDIAN_4_BYTES) {
    }

    BOOST_AUTO_TEST_CASE(SIZE_T_BIG_ENDIAN_4_BYTES) {
    }

    BOOST_AUTO_TEST_CASE(SIZE_T_LITTLE_ENDIAN_8_BYTES) {
    }

    BOOST_AUTO_TEST_CASE(SIZE_T_BIG_ENDIAN_8_BYTES) {
    }

BOOST_AUTO_TEST_SUITE_END()
