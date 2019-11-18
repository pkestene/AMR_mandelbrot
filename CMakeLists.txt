cmake_minimum_required(VERSION 3.3)

project(AMR_mandelbrot CXX C)

# C++11 is for Kokkos
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

#
# Make sure Kokkos is available (as a git submodule)
#
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/kokkos/Makefile.kokkos")
  execute_process(
    COMMAND git submodule update --init --recursive
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
endif()

#
# sources to build
#

# first build kokkos
add_subdirectory(external/kokkos)

# pass Kokkos include directories to our target application
include_directories(${Kokkos_INCLUDE_DIRS_RET})

# build the miniapp
add_subdirectory(src)

##################### PRINT CONFIGURE STATUS ######################
message("//===================================================")
message("  ${PROJECT_NAME} build configuration:")
message("//===================================================")
message("  C++ Compiler : ${CMAKE_CXX_COMPILER_ID} "
                         "${CMAKE_CXX_COMPILER_VERSION} "
                         "${CMAKE_CXX_COMPILER_WRAPPER}")
message("                 ${CMAKE_CXX_COMPILER}")
message("  Kokkos OpenMP enabled : ${Kokkos_ENABLE_OPENMP}")
message("  Kokkos CUDA   enabled : ${Kokkos_ENABLE_CUDA}")
if (Kokkos_ENABLE_CUDA)
  message("  Kokkos CUDA   Lambda  : ${Kokkos_ENABLE_CUDA_LAMBDA}")
  message("  Kokkos CUDA   flags   : ${KOKKOS_CUDA_OPTIONS}")
endif(Kokkos_ENABLE_CUDA)
message("  Kokkos HWLOC  enabled : ${Kokkos_ENABLE_HWLOC}")
