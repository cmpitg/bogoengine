find_package (GTest REQUIRED)
include_directories (${GTEST_INCLUDE_DIRS} ${COMMON_INCLUDES} ../src)

add_executable (test_helpers test_helpers.cpp)

target_link_libraries (test_helpers bogoengine ${GTEST_BOTH_LIBRARIES} pthread)
# target_link_libraries (test_helper gtest pthread)
