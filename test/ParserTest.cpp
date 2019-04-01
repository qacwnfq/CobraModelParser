#define BOOST_TEST_MODULE Parser
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>
#include <CobraModelParser/Parser.hpp>

BOOST_AUTO_TEST_SUITE(MatlabV5ParserImpl_suite)

    BOOST_AUTO_TEST_CASE(MatlabV5ParserImpl_throwsIfMatlabFileIsNotV5) {
        CobraModelParser::Parser parser;

        BOOST_CHECK_THROW(parser.parseMatlabV5File("unparsableFile.mat"),
                          CobraModelParser::UnexpectedFileTypeException);
    }

    BOOST_AUTO_TEST_CASE(MatlabV5ParserImpl_parses_ecoli_core_model) {
        CobraModelParser::Parser parser;
        auto matlabFile = parser.parseMatlabV5File("ecoli_core_model.mat");
        BOOST_CHECK(matlabFile.getFileName() == "ecoli_core_model.mat");
    }

    BOOST_AUTO_TEST_CASE(MatlabV5ParserImpl_parsesModel_iJO1366) {
        CobraModelParser::Parser parser;
        auto matlabFile = parser.parseMatlabV5File("iJO1366.mat");
        BOOST_CHECK(matlabFile.getFileName() == "iJO1366.mat");
    }

BOOST_AUTO_TEST_SUITE_END()