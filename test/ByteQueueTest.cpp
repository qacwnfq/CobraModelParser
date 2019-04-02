#define BOOST_TEST_MODULE ByteQueueTest
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>

#include "CobraModelParser/ByteQueue.hpp"

BOOST_AUTO_TEST_SUITE(BYTEQUEUE_SUITE)

    BOOST_AUTO_TEST_CASE(SIZE_IS_CORRECT) {
        std::deque<CobraModelParser::Byte> bytes = {0x9A, 0x99, 0x99, 0x99, 0x99, 0x19, 0x25, 0x40};
        CobraModelParser::ByteQueue byteQueue(bytes);
        BOOST_CHECK(byteQueue.getNumberOfBytes() == 8);
    }

    BOOST_AUTO_TEST_CASE(POP_FRONT_REDUCES_SIZE_CORRECTLY) {
        std::deque<CobraModelParser::Byte> bytes = {0x40, 0x1E, 0x00, 0x0, 0x0, 0x0, 0x0, 0x0};
        CobraModelParser::ByteQueue byteQueue(bytes);
        byteQueue.pop_front(3);
        BOOST_CHECK(byteQueue.getNumberOfBytes() == 5);
    }

    BOOST_AUTO_TEST_CASE(POP_BACK_REDUCES_SIZE_CORRECTLY) {
        std::deque<CobraModelParser::Byte> bytes = {0x40, 0x1E, 0x00, 0x0, 0x0, 0x0, 0x0, 0x0};
        CobraModelParser::ByteQueue byteQueue(bytes);
        byteQueue.pop_back(2);
        BOOST_CHECK(byteQueue.getNumberOfBytes() == 6);
    }


BOOST_AUTO_TEST_SUITE_END()
