#include "add_char.h"

struct size mazeSize(FILE *in){

	struct size s;


	s.y = 0;
	s.x = 0;

	int c;
	int w = 0;
	while ((c = fgetc(in)) != EOF) {

		if (c == '\n') {
			w = 1;
			s.y++;
		}
		if (w == 0)
			s.x++;
	}

	return s;

}


int replaceChr(FILE* in, int y, int x, char a, struct size s) {
	int pos = y * (s.x + 1) + x;
	int l = fseek(in, (long)pos, SEEK_SET);
	

	fputc((int)a, in);


	return 0;
}


char getChr(FILE* in, int y, int x, struct size s){
	int pos = y * (s.x+1) + x;
	int l = fseek(in, (long)pos, SEEK_SET);
	int c = fgetc(in);

	return c;

}
