add_subdirectory(io)

##############################################
add_executable(compute_mandelbrot_amr
  compute_mandelbrot_amr.cpp
  shared/morton_utils.h
  shared/amr_key.h
  shared/enums.h)
target_include_directories(compute_mandelbrot_amr
  PUBLIC
  ${CMAKE_SOURCE_DIR}/src
  )
target_link_libraries(compute_mandelbrot_amr kokkos io hwloc dl)
