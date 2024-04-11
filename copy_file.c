#include "copy_file.h"

FILE* copy_file(const char *file_name) {
	

	FILE* in;
	FILE* out;
	in = fopen(file_name, "r");
	out = fopen("rozwiazanie.txt", "w+");
	
	int c;
	while ((c = fgetc(in)) != EOF) {
		fputc(c, out);
	}

	
	


	fclose(in);
	return out;
}
