#ifndef IO_VTK_SHARED_H_
#define IO_VTK_SHARED_H_

#include <fstream>
#include <string>

namespace io {

/**
 * Write VTK unstructured grid header.
 */
void write_vtu_header(std::ostream &outFile);

/**
 * Write VTK unstructured grid metadata (date and time).
 */
void write_vtk_metadata(std::ostream &outFile, int iStep, double time);
/**
 * Write closing VTK unstructured grid statement.
 */
void close_vtu_grid(std::ostream &outFile);

/**
 * Write closing VTK file statement.
 */
void write_vtu_footer(std::ostream &outFile);

} // namespace io

#endif // IO_VTK_SHARED_H_
