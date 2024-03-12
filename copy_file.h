#include macro.h

void copy_file(){
FILE* in;
FILE* out;
in = fopen("dane.txt", "r");
out = fopen("wynik.txt", "w");
char linia[MAX_LINE_LENGTH];

while (fgets(linia, sizeof(linia), in) != NULL) {
	fputs(linia, out);
}

fclose(in);
fclose(out);
}


