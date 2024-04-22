#include "fhandling.h"

struct maze mazeData(FILE *in){


	struct maze s;

	int c;
	int x = 0, y = 0;
	while ((c = fgetc(in)) != EOF) {

		if (c == 'P'){
			s.start_x = x;
			s.start_y = y;
		}
		if (c == 'K'){
			s.end_x = x;
			s.end_y = y;
		}

		if (c == '\n') {
			s.size_x = x;
			x = 0;
			y++;
		}
		else
			x++;
		
	}
	
	s.size_y = y;


	return s;

}


int replaceChr(FILE* in, int y, int x, char a, struct maze s) {
	int pos = y * (s.size_x + 1) + x;
	int l = fseek(in, (long)pos, SEEK_SET);
	

	fputc((int)a, in);


	return 0;
}


char getChr(FILE* in, int y, int x, struct maze s){
	int pos = y * (s.size_x + 1) + x;
	int l = fseek(in, (long)pos, SEEK_SET);
	int c = fgetc(in);

	return c;

}

void resetPointer(FILE* f) {
	fseek(f, 0, SEEK_SET);
}

FILE* copy_file(const char* file_name) {


	FILE* in;
	FILE* out;
	in = fopen(file_name, "r");
	
	if(in == NULL)
		return NULL;
	out = fopen("rozwiazanie.txt", "w+");

	int c;
	while ((c = fgetc(in)) != EOF) {
		fputc(c, out);
	}

	fclose(in);
	return out;
}
