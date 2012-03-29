add_library (bogoengine
  engine.cpp
  engine.hpp)

target_link_libraries (bogoengine ${GTKMM_LIBRARIES})
