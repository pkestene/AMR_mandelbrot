# AMR_mandelbrot

Compute Mandelbrot Set using adaptive mesh refinement technique and [C++/kokkos](https://github.com/kokkos/kokkos/) library for multi-architecture execution. 
This is not intended to be efficient computation, but just a simple illustrative example of use of class Kokkos::UnorderedMap container (multi-architecture hash map data container). Mandelbrot set is computed iteratively, refined cells are inserted into the hashmap based data structure.

The following source code is self-contained; C++/kokkos library sources are included as a git submodule.

Example of Mandelbrot set with level_min=6 and level_max=11

```bash
./compute_mandelbrot_amr 6 11
```

![mandelbrot set](https://github.com/pkestene/AMR_mandelbrot/blob/master/mandelbrot_level_6_11.png)

# How to build ?

## Get the sources

Make sure to clone this repository recursively, this will also download kokkos source as a git submodule.

```bash
git clone --recurse-submodules https://github.com/pkestene/AMR_mandelbrot.git
```

Kokkos is built as part of this project with the cmake build system.

## build the code

### build for Kokkos/OpenMP execution

To build kokkos/OpenMP backend

```bash
mkdir build_openmp; cd build_openmp
ccmake -DKokkos_ENABLE_OPENMP=ON -DCMAKE_BUILD_TYPE=Release ..
make
```

Optionally, you can (recommended) activate HWLOC support by turning ON the flag Kokkos_ENABLE_HWLOC.

```bash
ccmake -DKokkos_ENABLE_OPENMP=ON -DCMAKE_BUILD_TYPE=Release -DKokkos_ENABLE_HWLOC=ON ..
```

### build for Kokkos/Cuda

Obviously, you need to have Nvidia/CUDA driver and toolkit installed on your platform.
Then you need to

 1. tell cmake to use kokkos compiler wrapper for cuda:
 
    ```shell
    export CXX=/complete/path/to/kokos/bin/nvcc_wrapper
    ```
    
 2. activate CUDA backend in the ccmake interface. 
    * Just turn on Kokkos_ENABLE_CUDA 
    * select cuda architecture, e.g. set Kokkos_ARCH_KEPLER37=ON (for Nvidia K80 boards)
    
    ```bash
    # example build for cuda
    mkdir build_cuda; cd build_cuda
    ccmake -DKokkos_ENABLE_CUDA=ON -DKokkos_ARCH_KEPLER37=ON -DKokkos_ENABLE_CUDA_LAMBDA=ON -DKokkos_ENABLE_HWLOC=ON ..
    make
    ```


