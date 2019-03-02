#define BOOST_TEST_MODULE ByteQueueTest
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>

#include "CobraModelParser/ByteQueue.hpp"

BOOST_AUTO_TEST_SUITE(BYTEQUEUE_SUITE)

    BOOST_AUTO_TEST_CASE(CHECK_THROWS_IF_BYTES_ARE_NOT_MULTIPLE_OF_BLOCK_SIZE) {
        std::vector<char> corruptBytes(1);
        BOOST_CHECK_THROW(CobraModelParser::ByteQueue byteQueue(corruptBytes),
                CobraModelParser::ByteQueueConstructionException);
    }

    BOOST_AUTO_TEST_CASE(CHECK_BYTEQUEUE_POPS) {
        std::vector<char> bytes(256);
        CobraModelParser::ByteQueue bytequeue(bytes);
        bytequeue.popByteBlock();
        BOOST_CHECK(bytequeue.getRemainingBytes() == 248);
        bytequeue.popByteBlocks(31);
        BOOST_CHECK(bytequeue.getRemainingBytes() == 0);
    }

    BOOST_AUTO_TEST_CASE(CHECK_BYTEQUEUE_UNDEFINED_POPS) {
        std::vector<char> bytes(256);
        CobraModelParser::ByteQueue bytequeue(bytes);
        bytequeue.popUndefinedByteBlock();
        BOOST_CHECK(bytequeue.getRemainingBytes() == 248);
        bytequeue.popUndefinedByteBlocks(31);
        BOOST_CHECK(bytequeue.getRemainingBytes() == 0);
    }

BOOST_AUTO_TEST_SUITE_END()
