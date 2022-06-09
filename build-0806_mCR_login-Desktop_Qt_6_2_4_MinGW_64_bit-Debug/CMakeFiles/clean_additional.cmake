# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "0806_mCR_login_autogen"
  "CMakeFiles\\0806_mCR_login_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\0806_mCR_login_autogen.dir\\ParseCache.txt"
  )
endif()
