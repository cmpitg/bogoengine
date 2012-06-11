add_library (bogoengine
  engine.cpp
  engine.hpp
  utils.cpp
  utils.hpp
  charset.cpp
  charset.hpp
  )

target_link_libraries (bogoengine ${GLIBMM_LIBRARIES})
