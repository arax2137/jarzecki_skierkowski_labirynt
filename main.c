#include "macro.h"
#include "fhandling.h"
#include "copy_file.h"




int main(){
	
	char* name = "maze.txt";

	FILE* f = copy_file(name);

	resetPointer(f);
	struct size s = mazeSize(f);
	printf("x - %d, y - %d\n", s.x, s.y);
	
	
	//replaceChr(f, 39, 40, 'V', s);
	printf("%c", getChr(f, 39, 40, s));

	









}