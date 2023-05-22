cmake_minimum_required(VERSION 3.0.0)
project(RattleTrap VERSION 0.1.0)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_STANDARD 17)

add_compile_definitions(TESTING)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(CTest)
enable_testing()

# Define constants for directories
# ---------------------------------------------------------------------------
set(COMMON_DIRECTORY Common)
set(COMPONENTS_DIRECTORY Components)
set(COMPONENTS_TEST_DIRECTORY ComponentsTest)
set(CONTROL_DIRECTORY Control)
set(CONTROL_TEST_DIRECTORY ControlTest)

# Define file lists
# ---------------------------------------------------------------------------
file(
  GLOB
  COMMON_SOURCES
  ${COMMON_DIRECTORY}/*.h
)
file(
  GLOB
  COMPONENTS_SOURCES
  ${COMPONENTS_DIRECTORY}/*.h
)
file(
  GLOB
  COMPONENTS_TEST_SOURCES
  ${COMPONENTS_DIRECTORY}/${COMPONENTS_TEST_DIRECTORY}/*.cc
)
file(
  GLOB
  CONTROL_SOURCES
  ${CONTROL_DIRECTORY}/*.h
)
file(
  GLOB
  CONTROL_TEST_SOURCES
  ${CONTROL_DIRECTORY}/${CONTROL_TEST_DIRECTORY}/*.cc
)

# Define executables and file sources
# ---------------------------------------------------------------------------
add_executable(
  ComponentsTest
  # ${COMMON_SOURCES}
  ${COMPONENTS_SOURCES}
  ${COMPONENTS_TEST_SOURCES}
)
add_executable(
  ControlTest
  # ${COMMON_SOURCES}
  # ${COMPONENTS_SOURCES}
  # ${COMPONENTS_TEST_SOURCES}
  ${CONTROL_SOURCES}
  ${CONTROL_TEST_SOURCES}
)

# Define additional include directories
# ---------------------------------------------------------------------------
target_include_directories(
  ComponentsTest
  PRIVATE
  ${CMAKE_SOURCE_DIR}/${COMMON_DIRECTORY}/
  ${CMAKE_SOURCE_DIR}/${COMPONENTS_DIRECTORY}/
  ${CMAKE_SOURCE_DIR}/${COMPONENTS_DIRECTORY}/${COMPONENTS_TEST_DIRECTORY}
)
target_include_directories(
  ControlTest
  PRIVATE
  ${CMAKE_SOURCE_DIR}/${COMMON_DIRECTORY}/
  ${CMAKE_SOURCE_DIR}/${COMPONENTS_DIRECTORY}/
  ${CMAKE_SOURCE_DIR}/${COMPONENTS_DIRECTORY}/${COMPONENTS_TEST_DIRECTORY}
  ${CMAKE_SOURCE_DIR}/${CONTROL_DIRECTORY}/
  ${CMAKE_SOURCE_DIR}/${CONTROL_DIRECTORY}/${CONTROL_TEST_DIRECTORY}
)

# Linkers
# ---------------------------------------------------------------------------
target_link_libraries(
  ComponentsTest
  GTest::gtest_main
  GTest::gmock_main
)
target_link_libraries(
  ControlTest
  GTest::gtest_main
  GTest::gmock_main
)

# Add tests
# ---------------------------------------------------------------------------
include(GoogleTest)
gtest_discover_tests(ComponentsTest)
gtest_discover_tests(ControlTest)
