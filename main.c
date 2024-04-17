#include "macro.h"
#include "fhandling.h"
#include "algorithm.h"
#include "binary.h"
#include "read_path.h"




int main(){

	
	int binary = 1; //0 zwykly, 1 binarny

	char* name = "maze.txt";
	char* bname = "maze.bin";


	if (binary == 0) {
		FILE* f = copy_file(name);
		resetPointer(f);
		struct maze s = mazeData(f);
		alg(f, s);
		read_path(f, s);
	}
	
	else if (binary == 1) {
		decode(bname);
		FILE* f = copy_file("decoded.txt");
		resetPointer(f);
		struct maze s = mazeData(f);
		alg(f, s);
		read_path(f, s);
	}
}
