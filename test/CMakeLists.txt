add_subdirectory (../gtest gtest/)

add_executable (test_utils test_utils.cpp)

target_link_libraries (test_utils bogoengine gtest)

