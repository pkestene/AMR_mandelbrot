#ifndef MANDELBROT_AMR_POINT_H
#define MANDELBROT_AMR_POINT_H

#include <array>

namespace
{

/** typedef Point holding coordinates of a point. */
template <int dim>
using Point = std::array<double, dim>;

} // namespace

#endif // MANDELBROT_AMR_POINT_H
