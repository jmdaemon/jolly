# Include doctest cmake module
include(${DOCTEST_SOURCE_DIR}/scripts/cmake/doctest.cmake)
#include(${DOCTEST_SOURCE_DIR}/scripts/cmake/doctest)
#message(STATUS "Including CMake Module: ${DOCTEST_SOURCE_DIR}/scripts/cmake/doctest.cmake")
#include(${DOCTEST_SOURCE_DIR}/scripts/cmake/doctest)

#list(APPEND CMAKE_MODULE_PATH ${DOCTEST_SOURCE_DIR}/scripts/cmake)

#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${DOCTEST_SOURCE_DIR}/scripts/cmake)
#include(doctest)

# Unit Tests

set(HEADERS ${INCLUDES_DIR} ${DOCTEST_INCLUDE_DIR})
set(TARGET jolly)

# Add unit tests
set(TEST_NAME test-${TARGET})
add_executable(${TEST_NAME} test_jolly.cpp)
target_include_directories(${TEST_NAME} PUBLIC ${HEADERS})
target_link_libraries(${TEST_NAME} PRIVATE ${PKG_DEPENDS} doctest)
#add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})

# Discover unit tests
doctest_discover_tests(${TEST_NAME})
#doctest_discover_tests()
#doctest_discover_tests(
    #${TEST_NAME}
    ##TEST_PREFIX test_
    #WORKING_DIRECTORY .)
