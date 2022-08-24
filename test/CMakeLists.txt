# Unit Tests
set(HEADERS ${INCLUDES_DIR} ${DOCTEST_INCLUDE_DIR})
set(TARGET jolly)

# Add unit tests
set(TEST_NAME test-${TARGET})
add_executable(${TEST_NAME} test_jolly.cpp)
target_include_directories(${TEST_NAME} PUBLIC ${HEADERS})
target_link_libraries(${TEST_NAME} PRIVATE ${PKG_DEPENDS})
add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
#add_test(NAME ${TARGET} COMMAND ${TARGET})

# Doctest discover tests

# Include cmake module
include(${DOCTEST_SOURCE_DIR}/scripts/cmake/doctest.cmake)

# Discover unit tests
doctest_discover_tests(${TEST_NAME}
    #TEST_PREFIX test_
    TEST_PREFIX TEST
    WORKING_DIRECTORY ./)
#doctest_discover_tests(${TEST_NAME}
    #TEST_PREFIX TEST
    #WORKING_DIRECTORY ./)
