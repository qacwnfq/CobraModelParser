#define BOOST_TEST_MODULE matlab2EigenTest
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>

#include "matlab2Eigen/matlab2Eigen.hpp"

BOOST_AUTO_TEST_SUITE(MATLAB2EIGEN_SUITE)
BOOST_AUTO_TEST_CASE(MATLAB_V5) {
        matlab2Eigen("iJO1366.mat");
//        BOOST_CHECK(sum==expectedSum);
}
BOOST_AUTO_TEST_SUITE_END()