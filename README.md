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


```bash
git clone git@github.com:pkestene/AMR_mandelbrot.git
```


## How to build ?

### Build for Kokkos/OpenMP target device

To build kokkos/OpenMP backend

```bash
mkdir -p _build/openmp; cd _build/openmp
cmake -DAMR_MANDELBROT_KOKKOS_BUILD=ON -DAMR_MANDELBROT_KOKKOS_BACKEND=OpenMP ../..
make
# run application
./compute_mandelbrot_amr 6 11
```

Optionally, you can (recommended) activate HWLOC support by using the flag `-DKOKKOS_ENABLE_HWLOC=ON`.


### Build for Kokkos/Cuda target device

Obviously, you need to have Nvidia/CUDA driver and toolkit installed on your platform.
Then you need to

```bash
# example build for cuda
mkdir -p _build/cuda; cd _build/cuda
cmake -DAMR_MANDELBROT_KOKKOS_BUILD=ON -DAMR_MANDELBROT_KOKKOS_BACKEND=Cuda -DKokkos_ENABLE_CUDA_LAMBDA=ON -DKokkos_ENABLE_HWLOC=ON ../..
make
# run application
./compute_mandelbrot_amr 6 11
```
