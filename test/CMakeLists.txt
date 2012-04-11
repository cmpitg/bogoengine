add_subdirectory (gtest-1.6.0)

add_executable (test_utils test_utils.cpp)

target_link_libraries (test_utils bogoengine gtest)
# target_link_libraries (test_helper gtest pthread)
