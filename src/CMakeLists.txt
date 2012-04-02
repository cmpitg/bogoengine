add_library (bogoengine
  engine.cpp
  engine.hpp
  utils.cpp
  utils.hpp
  )

target_link_libraries (bogoengine ${GLIBMM_LIBRARIES})
