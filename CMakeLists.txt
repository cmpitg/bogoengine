cmake_minimum_required (VERSION 2.6)
project (BOGOENGINE)

# Find gtkmm
find_package (PkgConfig)
pkg_check_modules (GTKMM gtkmm-2.4)

# Include - headers
include_directories (src)
include_directories (${GTKMM_INCLUDE_DIRS} src)

# Linker - directories
link_directories (${GTKMM_LIBRARY_DIRS})

# Directories with CMakeLists.txt
add_subdirectory (src)
add_subdirectory (test)

# Output - executables
# add_executable ()

# Output - libraries
# add_library ()

# Linker - files
# target_link_libraries ()
