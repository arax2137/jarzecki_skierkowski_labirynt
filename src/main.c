#include "macro.h"
#include "fhandling.h"
#include "algorithm.h"
#include "binary.h"
#include "read_path.h"


int main(int argc, char *argv[]){



	int opt;
	
	int type = 0; // 0 - txt, 1 - bin
	char *name = malloc(20);
	
	while((opt = getopt(argc, argv, "n:t:")) != -1){
	
	switch(opt){
	
	case 'n':
		strcpy(name, optarg);
		break;
	case 't':
		if(strcmp("bin",optarg) == 0) 
			type = 1;
		else if(strcmp("txt",optarg) == 0)
			type = 0;
		}
	}

	if (type == 0) {
		FILE* f = copy_file(name);
		resetPointer(f);
		struct maze s = mazeData(f);
		alg(f, s);
		read_path(f, s);
		fclose(f);
	}
	
	else if (type == 1) {
		decode(name);
		FILE* f = copy_file("decoded.txt");
		resetPointer(f);
		struct maze s = mazeData(f);
		alg(f, s);
		int steps = read_path(f, s);
		char dir = baseDirection(s);
		encode(name, dir, steps);
		fclose(f);
	}
	
}
