# Unit Tests
set(HEADERS ${INCLUDES_DIR} ${DOCTEST_INCLUDE_DIR})
set(TARGET jolly)

# Add unit tests
set(TEST_NAME test-${TARGET})
add_executable(${TEST_NAME} test_jolly.cpp)
target_include_directories(${TEST_NAME} PUBLIC ${HEADERS})
target_link_libraries(${TEST_NAME} PRIVATE ${PKG_DEPENDS} doctest fmt spdlog jolly)
add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})

# Optional test modules
if (COMPILE_SPDLOG_MACROS)
    set(TEST_NAME test-${TARGET}-spdlog)
    add_executable(${TEST_NAME} test_jolly_spdlog.cpp)
    target_include_directories(${TEST_NAME} PUBLIC ${HEADERS})
    target_link_libraries(${TEST_NAME} PRIVATE ${PKG_DEPENDS} doctest fmt spdlog)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
else() # No-op
endif()

if (DISCOVER_TESTS)
    # Include doctest cmake module
    include(${DOCTEST_SOURCE_DIR}/scripts/cmake/doctest.cmake)

    # Discover unit tests
    doctest_discover_tests(${TEST_NAME})
endif()
