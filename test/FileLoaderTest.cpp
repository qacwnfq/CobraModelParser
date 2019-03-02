#define BOOST_TEST_MODULE FileLoaderTest
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>

#include "CobraModelParser/FileLoader.hpp"

BOOST_AUTO_TEST_SUITE(FILELOADER_SUITE)

    BOOST_AUTO_TEST_CASE(FILELOADER_THROWS_IF_FILE_NOT_FOUND) {
        BOOST_CHECK_THROW(CobraModelParser::FileLoader::loadFileContentsAsByteQueue("nonExistingFile"),
                          CobraModelParser::FileNotFoundException);
    }

    BOOST_AUTO_TEST_CASE(MatlabV5ParserImpl_parsesModel) {
        CobraModelParser::ByteQueue byteQueue = CobraModelParser::FileLoader::loadFileContentsAsByteQueue(
                "iJO1366.mat");
        BOOST_CHECK(byteQueue.getRemainingBytes() == 38792568);
    }

BOOST_AUTO_TEST_SUITE_END()
