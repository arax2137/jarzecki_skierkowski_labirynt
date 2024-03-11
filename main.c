#include "macro.h"
#include "add_char.h"




int main(){
	
	FILE *in = fopen("maze.txt", "r+");
	
	struct size s = mazeSize(in);
	//printf("x - %d, y - %d", s.x, s.y);
	
	replaceChr(in, 39, 40, 'K', s);
	//printf("%c", getChr(in, 21, 25, s));

	









}