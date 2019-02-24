find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(resources/constraintBasedModel.mat ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(resources/iJO1366.mat ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(resources/matrix.mat ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(resources/unparsableFile.mat ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(resources/vector.mat ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)


project(CobraModelParserTest CXX)

set(LIBRARY_TESTS_SOURCES
        ByteParserTest.cpp
        ModelTest.cpp
        MatlabV5ParserImplTest.cpp
        )

set(TEST_REPORTS_DIR "reports")
add_custom_target(make-nups-test-report-dir ALL
        COMMAND ${CMAKE_COMMAND} -E make_directory
        ${PROJECT_BINARY_DIR}/${TEST_REPORTS_DIR}
        )
include_directories(${Boost_INCLUDE_DIRS} ${LIBRARY_HEADER_DIR})
foreach (TEST_SOURCE ${LIBRARY_TESTS_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_include_directories(${TEST_NAME} PRIVATE
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
            $<INSTALL_INTERFACE:include/${LIBRARY_NAME}>
            ${Boost_INCLUDE_DIRS}
            )
    target_link_libraries(${TEST_NAME}
            ${LIBRARY_NAME}
            ${Boost_LIBRARIES}
            )
    set_target_properties(${TEST_NAME} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY .)
    add_test(NAME ${TEST_NAME}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMAND $<TARGET_FILE:${TEST_NAME}> --log_format=XML --log_sink=${PROJECT_BINARY_DIR}/${TEST_REPORTS_DIR}/${TEST_NAME}.xml --log_level=all --report_level=detailed)
endforeach (TEST_SOURCE)
