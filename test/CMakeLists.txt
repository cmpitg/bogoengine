add_subdirectory (../gtest gtest/)
include_directories (BEFORE ${gtest_SOURCE_DIR}/include)

add_executable (
  test_utils
  test_utils.cpp
  )

target_link_libraries (test_utils bogoengine gtest)
