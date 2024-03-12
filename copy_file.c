#include copy_file.h

FILE* copy_file(const char *file_name) {
	FILE* in;
	FILE* out;
	in = fopen(file_name, "r+");
	out = fopen("rozwiazanie.txt", "w");
	char linia[MAX_LINE_LENGTH];

	while (fgets(linia, sizeof(linia), in) != NULL) {
		fputs(linia, out);
	}

	fclose(in);
	return out;
}
