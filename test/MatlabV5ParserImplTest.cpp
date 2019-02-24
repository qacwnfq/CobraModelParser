#define BOOST_TEST_MODULE MatlabV5ParserImpl
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>
#include <memory>

#include "CobraModelParser/MatlabV5ParserImpl.hpp"

BOOST_AUTO_TEST_SUITE(MatlabV5ParserImpl_suite)

    BOOST_AUTO_TEST_CASE(MatlabV5ParserImpl_throwsIfFileIsNotFound) {
        CobraModelParser::MatlabV5ParserImpl parser;

        BOOST_CHECK_THROW(parser.parseModelFromFile("nonExistingFile"), CobraModelParser::FileNotFoundException);
    }

    BOOST_AUTO_TEST_CASE(MatlabV5ParserImpl_throwsIfMatlabFileIsNotV5) {
        CobraModelParser::MatlabV5ParserImpl parser;

        BOOST_CHECK_THROW(parser.parseModelFromFile("unparsableFile.mat"), CobraModelParser::UnexpectedFileTypeException);
    }

    BOOST_AUTO_TEST_CASE(MatlabV5ParserImpl_parsesModel) {
        CobraModelParser::MatlabV5ParserImpl parser;
        parser.parseModelFromFile("iJO1366.mat");
    }

BOOST_AUTO_TEST_SUITE_END()