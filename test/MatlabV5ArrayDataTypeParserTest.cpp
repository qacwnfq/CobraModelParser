#define BOOST_TEST_MODULE MatlabV5ArrayDataTypeParserTest
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>

#include "CobraModelParser/MatlabV5/MatlabV5ArrayDataTypeParser.hpp"

BOOST_AUTO_TEST_SUITE(MATLABV5ARRAYDATATYPEPARSER_SUITE)

    BOOST_AUTO_TEST_CASE(THROWS_EXCEPTION_ON_UNEXPECTED_DATA_TYPE) {
//        CobraModelParser::MatlabV5DataType type(12, "miINT64", "64-bit, signed");
//        CobraModelParser::MatlabV5DataElement corruptElement(type, std::vector<char>());
//
//        BOOST_CHECK_THROW(
//                CobraModelParser::MatlabV5ArrayDataTypeParser::parseModelFromMatlabV5DataElement(corruptElement, "IM"),
//                CobraModelParser::UnexpectedDataTypeException);
    }

BOOST_AUTO_TEST_SUITE_END()
