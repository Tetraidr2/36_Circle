# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "36_Circle_autogen"
  "CMakeFiles\\36_Circle_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\36_Circle_autogen.dir\\ParseCache.txt"
  )
endif()
