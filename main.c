#include "macro.h"
#include "fhandling.h"




int main(){
	
	char* name = "maze.txt";

	FILE* f = copy_file(name);

	resetPointer(f);
	struct maze s = mazeData(f);
	printf("x - %d, y - %d\n start - %d/%d\n koniec - %d/%d", s.size_x, s.size_y, s.start_x, s.start_y, s.end_x, s.end_y);
	
	
	replaceChr(f, 39, 40, 'V', s);
	printf("%c", getChr(f, 39, 40, s));

	









}