cmake_minimum_required(VERSION 2.8.12)
cmake_policy(SET CMP0042 OLD)

project(mdp C)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

# dependencies
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
find_package(CZMQ REQUIRED)
find_package(ZeroMQ REQUIRED)

# determine version
foreach(which MAJOR MINOR PATCH)
  file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/include/mdp.h" MDP_VERSION_STRING REGEX "#define MDP_VERSION_${which}")
  string(REGEX MATCH "#define MDP_VERSION_${which} ([0-9_]+)" MDP_REGEX_MATCH "${MDP_VERSION_STRING}")
  if (NOT MDP_REGEX_MATCH)
    message(FATAL_ERROR "failed to parse MDP_VERSION_${which} from mdp.h")
  endif()
  set(MDP_${which}_VERSION ${CMAKE_MATCH_1})
endforeach(which)

set(MDP_VERSION ${MDP_MAJOR_VERSION}.${MDP_MINOR_VERSION}.${MDP_PATCH_VERSION})

message(STATUS "version: ${MDP_VERSION}")
message(STATUS "install: ${CMAKE_INSTALL_PREFIX}")

# pkgconfig
set(VERSION "${MDP_VERSION}")
set(prefix "${CMAKE_INSTALL_PREFIX}")
set(exec_prefix "\${prefix}")
set(libdir "\${prefix}/lib${LIB_SUFFIX}")
set(includedir "\${prefix}/include")
configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/libmdp.pc.in"
  "${CMAKE_CURRENT_BINARY_DIR}/libmdp.pc"
@ONLY)

install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/libmdp.pc"
  DESTINATION "lib${LIB_SUFFIX}/pkgconfig"
)

add_subdirectory(src)
