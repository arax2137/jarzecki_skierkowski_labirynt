#include "macro.h"
#include "fhandling.h"
#include "algorithm.h"




int main(){
	
	char* name = "maze1.txt";

	FILE* f = copy_file(name);

	resetPointer(f);
	struct maze s = mazeData(f);
	printf("x - %d, y - %d\nstart - %d/%d\nkoniec - %d/%d\n", s.size_x, s.size_y, s.start_x, s.start_y, s.end_x, s.end_y);


	alg(f, s);

	
	//replaceChr(f, 39, 40, 'V', s);
	//printf("%c", getChr(f, 39, 40, s));

	









}