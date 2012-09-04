add_subdirectory (../gtest gtest/)
include_directories (BEFORE ${gtest_SOURCE_DIR}/include)

add_executable (
  test_utils
  test_utils.cpp
  )

add_executable (
  test_engine
  test_engine.cpp
  )

target_link_libraries (test_utils bogoengine gtest)
target_link_libraries (test_engine bogoengine gtest)
