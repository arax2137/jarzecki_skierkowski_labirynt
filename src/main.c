#include "macro.h"
#include "fhandling.h"
#include "algorithm.h"
#include "binary.h"
#include "read_path.h"
#include<unistd.h>

int main(int argc, char *argv[]){



	int opt;
	
	int type = 0; // 0 - txt, 1 - bin
	char *name = malloc(50);
	
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
	
	/*
	FILE *f = copy_file(name);
	resetPointer(f);
	struct maze s = mazeData(f);
	printf("%c", getChr(f, 1,0,s));
	printf("\n%d %d %d %d %d %d", s.size_x, s.size_y, s.start_x, s.start_y, s.end_x, s.end_y);*/
	
	
	if (type == 0) {
		FILE* f = copy_file(name);
		if(f == NULL){
			printf("[!] Plik nie istnieje");
			return 1;
		}
			
		resetPointer(f);
		struct maze s = mazeData(f);
		alg(f, s);
		read_path(f, s);
		fclose(f);
	}
	
	else if (type == 1) {
		int t = decode(name);
		if(t == 1){
			printf("[!] Plik nie istnieje");
			return 1;
		}
		
		FILE* f = copy_file("decoded.txt");
		resetPointer(f);
		struct maze s = mazeData(f);
		alg(f, s);
		int steps;
		steps = read_path(f, s);
		char dir;
		//dir = baseDirection(s);
		//encode(name, dir, steps);
		fclose(f);
	}
	
	
}
