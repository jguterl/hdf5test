#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>
#include “struct.h”
#include <h5cpp/core>
	// compound type descriptor must be sandwiched between core and io
	// to satisfy template dependencies in <h5cpp/io>
	#include “generated.h”
#include <h5cpp/io>
#include “utils.hpp”
#define CHUNK_SIZE 5
#define NROWS 4*CHUNK_SIZE
#define NCOLS 1*CHUNK_SIZE
int main(){
	//RAII will close resource, noo need H5Fclose( any_longer );
	h5::fd_t fd = h5::create(“example.h5",H5F_ACC_TRUNC);
	{
std::vector<double> v(10, 1.0);
h5::write(fd,“stl/vector/full.dat”, v); // simplest example
}
