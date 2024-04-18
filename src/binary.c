#include "binary.h"

int decode(char* name) {

	FILE* in = fopen(name, "rb");
	
	if(in == NULL){
		return 1;
	}
	
	FILE* out = fopen("decoded.txt", "w+");

	int fileid = 0, escape = 0, columns = 0, lines = 0, entry_x = 0, entry_y = 0, exit_x = 0, exit_y = 0, counter = 0, solution_offset = 0, separator = 0, wall = 0, path = 0;
	int reserved;
	

	//ZCZYTYWANIE NAGŁÓWKA
	fread(&fileid, 4, 1, in);
	fread(&escape, 1, 1, in);
	fread(&columns, 2, 1, in);
	fread(&lines, 2, 1, in);
	fread(&entry_x, 2, 1, in);
	fread(&entry_y, 2, 1, in);
	fread(&exit_x, 2, 1, in);
	fread(&exit_y, 2, 1, in);
	fread(&reserved, 4, 1, in);
	fread(&reserved, 4, 1, in);
	fread(&reserved, 4, 1, in);
	fread(&counter, 4, 1, in);
	fread(&solution_offset, 4, 1, in);
	fread(&separator, 1, 1, in);
	fread(&wall, 1, 1, in);
	fread(&path, 1, 1, in);
	
	//columns--;
	//lines--;
	entry_x--;
	entry_y--;
	exit_x--;
	exit_y--;
	//KONIEC NAGŁÓWKA

	/*
	printf("fileid %x, escape %x, columns %d, lines %d\n, entryx %d, entryy %d, exitx %d, exity %d\n, counter %d, solutionoffset %d\n, separator %c, wall %c, path %c", fileid, escape, columns,
		lines, entry_x, entry_y, exit_x, exit_y, counter, solution_offset, separator, wall, path);
	*/



	//WPISYWANIE LABIRYNTU DO PLIKU
	int sep = 0, val = 0, count = 0;


	int c = 0;
	int cil = 0; //char in line

	while (c <= counter) {
		sep = 0;
		val = 0;
		count = 0;

		fread(&sep, 1, 1, in);
		fread(&val, 1, 1, in);
		fread(&count, 1, 1, in);

		if (val != ' ' && val != 'X')
			break;

		for (int i = 0; i <= count; i++) {

			if (cil == columns) {
				cil = 0;
				fputc('\n', out);
			}

			fputc(val, out);
			cil++;

		}

		c++;
	}

	struct maze s;

	s.size_x = columns;
	s.size_y = lines;
	s.start_x = entry_x;
	s.start_y = entry_y;
	s.end_x = exit_x;
	s.end_y = exit_y;

	replaceChr(out, entry_y, entry_x, 'P', s);
	replaceChr(out, exit_y, exit_x, 'K', s);

	fclose(out);
	fclose(in);
	return 0;
}

void encode(char* name, char dir, int steps) {

	FILE* f = fopen(name, "a+b");

	FILE* in = fopen("kroki.txt", "r");

	fseek(f, 0, SEEK_END);

	fwrite(&steps, 16, 1, f);


	char d;

	switch (dir) {
	case 'r':
		d = 'E';
		break;
	case 'l':
		d = 'W';
		break;
	case 'u':
		d = 'N';
		break;
	case 'd':
		d = 'S';
		break;
	}

	int count;
	char tdir[10] = "";
	char buff[10] = "";

	fscanf(in, "%s", buff);

	for (int i = 0; i < steps; i++) {
		fscanf(in, "%s %d", buff, &count);
		fscanf(in, "%s %s", buff, &tdir);

		switch (tdir[0]) {
		case 'R':
			switch (d) {
			case 'E':
				d = 'S';
				break;
			case 'W':
				d = 'N';
				break;
			case 'N':
				d = 'E';
				break;
			case 'S':
				d = 'W';
				break;
			}
			break;
		case 'L':
			switch (d) {
			case 'E':
				d = 'N';
				break;
			case 'W':
				d = 'S';
				break;
			case 'N':
				d = 'W';
				break;
			case 'S':
				d = 'E';
				break;
			}
			break;
		}

		count--;

		fwrite(&d, 1, 1, f);
		fwrite(&count, 1, 1, f);

	}
	

	fclose(f);
	fclose(in);
}
