#include <sstream>

#include "IO_VTK_shared.h"

namespace { namespace io {

// =======================================================
// =======================================================
static bool isBigEndian()
{
  const int i = 1;
  return ( (*(char*)&i) == 0 );
}

// =======================================================
// =======================================================
void write_vtu_header(std::ostream& outFile)
{

  // print data and time
  outFile << "<!-- \n";
  outFile << "# vtk DataFile Version 3.0"
	  << '\n'
	  << "#This file was generated by AMR_mandelbrot";
  outFile << ".";
  outFile << "\n-->\n";

  
  // write xml data header

  outFile << "<VTKFile type=\"UnstructuredGrid\" version=\"1.0\"";
  
  if (isBigEndian()) {
    outFile << " byte_order=\"BigEndian\"";
  } else {
    outFile << " byte_order=\"LittleEndian\"";
  }

  // if (outputVtkAppended)
  //   outFile << " header_type=\"UInt64\"";

  outFile << ">\n";
  
  outFile << "  <UnstructuredGrid>\n";
  
} // write_vtu_header

// =======================================================
// =======================================================
void write_vtk_metadata(std::ostream& outFile,
			int iStep,
			double time)
{

  outFile << "  <FieldData>\n";

  outFile << "    <DataArray type=\"Int32\" Name=\"CYCLE\" NumberOfTuples=\"1\" format=\"ascii\">"
	  << iStep
	  << "    </DataArray>\n";

  outFile << "    <DataArray type=\"Float32\" Name=\"TIME\" NumberOfTuples=\"1\" format=\"ascii\">"
      << time
      << "    </DataArray>\n";

  outFile << "  </FieldData>\n";
  
} // write_vtk_metadata


// =======================================================
// =======================================================
void close_vtu_grid(std::ostream& outFile)
{

  outFile << "  </UnstructuredGrid>\n";
  
} // close_vtu_grid

// =======================================================
// =======================================================
void write_vtu_footer(std::ostream& outFile)
{

  outFile << "</VTKFile>\n";
  
} // write_vtu_footer

} // namespace io

} // namespace