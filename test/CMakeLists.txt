find_package (GTest REQUIRED)
include_directories (${GTEST_INCLUDE_DIRS} ${COMMON_INCLUDES} ../src)

add_executable (test_utils test_utils.cpp)

target_link_libraries (test_utils bogoengine ${GTEST_BOTH_LIBRARIES} pthread)
# target_link_libraries (test_helper gtest pthread)
