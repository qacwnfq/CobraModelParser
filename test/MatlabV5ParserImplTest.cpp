#define BOOST_TEST_MODULE MatlabV5ParserImpl
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>

#include "CobraModelParser/ParserImpl.hpp"

BOOST_AUTO_TEST_SUITE(MatlabV5ParserImpl_suite)

    BOOST_AUTO_TEST_CASE(MatlabV5ParserImpl_throwsIfMatlabFileIsNotV5) {
        CobraModelParser::MatlabV5::ParserImpl parser;

        BOOST_CHECK_THROW(parser.parseModelFromFile("unparsableFile.mat"),
                          CobraModelParser::UnexpectedFileTypeException);
    }

    BOOST_AUTO_TEST_CASE(MatlabV5ParserImpl_parsesModel_iJO1366) {
        CobraModelParser::MatlabV5::ParserImpl parser;
        CobraModelParser::Model model = parser.parseModelFromFile("iJO1366.mat");
        BOOST_CHECK(model.getOrigin() == "iJO1366.mat");
    }

    BOOST_AUTO_TEST_CASE(MatlabV5ParserImpl_parsesModel_iJO1366_2) {
        CobraModelParser::MatlabV5::ParserImpl parser;
        CobraModelParser::Model model = parser.parseModelFromFile("iJO1366_2.mat");
        BOOST_CHECK(model.getOrigin() == "iJO1366_2.mat");
    }

BOOST_AUTO_TEST_SUITE_END()