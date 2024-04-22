#include "read_path.h"

char direction(FILE* in, int x, int y, struct maze m) {
	if (getChr(in, y, x + 1, m) == '1')
		return 'r';
	else if (getChr(in, y, x - 1, m) == '1')
		return 'l';
	else if (getChr(in, y + 1, x, m) == '1')
		return 'd';
	else if (getChr(in, y - 1, x, m) == '1')
		return 'u';
	return 'c';
}

int last_step(FILE* in, int x, int y, struct maze m) {
	if (getChr(in, y + 1, x, m) == 'K' || getChr(in, y - 1, x, m) == 'K' || getChr(in, y, x - 1, m) == 'K' || getChr(in, y, x + 1, m) == 'K')
		return 1;
	else
		return 0;
}

int read_path(FILE* in,struct maze m)
{

	FILE* out;
	out = fopen("kroki.txt", "w");
	char kierunek = baseDirection(m);
	char kierunek_nastepny;

	int x = m.start_x;
	int y = m.start_y;
	fprintf(out, "START\n");
	int count_steps = 0;

	int steps = 0;
	
	while (!last_step(in,x,y,m))
	{
		switch (kierunek) {
		case 'r':
			count_steps = 0;
			while (getChr(in, y, x, m) != 'X' && getChr(in, y, x, m) != '2' && getChr(in, y, x, m) != 'K') {
				replaceChr(in, y, x, '.', m);
				count_steps++;
				if (getChr(in, y + 1, x, m) == 'K' || getChr(in, y - 1, x, m) == 'K' || getChr(in, y, x - 1, m) == 'K' || getChr(in, y, x + 1, m) == 'K')
					count_steps++;
				if (direction(in, x, y, m) != 'r' && direction(in, x, y, m) != 'c')
					break;
				else if (getChr(in, y, x + 1, m) != 'X' && getChr(in, y, x + 1, m) != '2')
					x++;
				else
					break;
			}
			kierunek_nastepny = direction(in, x, y, m);
			fprintf(out, "FORWARD %i\n", count_steps-1);
			switch (kierunek_nastepny) {
			case 'u':
				fprintf(out, "TURN LEFT\n");
				break;
			case 'd':
				fprintf(out, "TURN RIGHT\n");
				break;
			}
			kierunek = direction(in, x, y, m);
			break;
		case 'l':
			count_steps = 0;
			while (getChr(in, y, x, m) != 'X' && getChr(in, y, x, m) != '2' && getChr(in, y, x, m) != 'K') {
				replaceChr(in, y, x, '.', m);
				count_steps++;
				if (getChr(in, y + 1, x, m) == 'K' || getChr(in, y - 1, x, m) == 'K' || getChr(in, y, x - 1, m) == 'K' || getChr(in, y, x + 1, m) == 'K')
					count_steps++;
				if (direction(in, x, y, m) != 'l' && direction(in, x, y, m) != 'c')
					break;
				else if (getChr(in, y, x -1, m) != 'X' && getChr(in, y, x - 1, m) != '2')
					x--;
				else
					break;
			}
			kierunek_nastepny = direction(in, x, y, m);
			fprintf(out, "FORWARD %i\n", count_steps-1);
			switch (kierunek_nastepny) {
			case 'u':
				fprintf(out, "TURN RIGHT\n");
				break;
			case 'd':
				fprintf(out, "TURN LEFT\n");
				break;
			}
			kierunek = direction(in, x, y, m);
			break;
		case 'u':
			count_steps = 0;
			while (getChr(in, y, x, m) != 'X' && getChr(in, y, x, m) != '2' && getChr(in, y, x, m) != 'K') {
				replaceChr(in, y, x, '.', m);
				count_steps++;
				if (getChr(in, y + 1, x, m) == 'K' || getChr(in, y - 1, x, m) == 'K' || getChr(in, y, x - 1, m) == 'K' || getChr(in, y, x + 1, m) == 'K')
					count_steps++;
				if (getChr(in, y + 1, x, m) == 'K' || getChr(in, y - 1, x, m) == 'K' || getChr(in, y, x - 1, m) == 'K' || getChr(in, y, x + 1, m) == 'K')
					count_steps++;
				if (direction(in, x, y, m) != 'u' && direction(in, x, y, m) != 'c')
					break;
				else if (getChr(in, y - 1, x, m) != 'X' && getChr(in, y - 1, x, m) != '2')
					y--;
				else
					break;
			}
			kierunek_nastepny = direction(in, x, y, m);
			fprintf(out, "FORWARD %i\n", count_steps -1);
			switch (kierunek_nastepny) {
			case 'r':
				fprintf(out, "TURN RIGHT\n");
				break;
			case 'l':
				fprintf(out, "TURN LEFT\n");
				break;
			}
			kierunek = direction(in, x, y, m);
			break;
		case 'd':
			count_steps = 0;
			while (getChr(in, y, x, m) != 'X' && getChr(in, y, x, m) != '2' && getChr(in, y, x, m) != 'K') {
				replaceChr(in, y, x, '.', m);
				count_steps++;
				if (getChr(in, y + 1, x, m) == 'K' || getChr(in, y - 1, x, m) == 'K' || getChr(in, y, x - 1, m) == 'K' || getChr(in, y, x + 1, m) == 'K')
					count_steps++;
			if (direction(in, x, y, m) != 'd' && direction(in, x, y, m) != 'c')
					break;
			else if (getChr(in, y+1, x, m) != 'X' && getChr(in, y+1, x , m) != '2')
				y++;
			else
				break;
			}
			kierunek_nastepny = direction(in, x, y, m);
			fprintf(out, "FORWARD %i\n", count_steps -1);
			switch (kierunek_nastepny) {
			case 'r':
				fprintf(out, "TURN LEFT\n");
				break;
			case 'l':
				fprintf(out, "TURN RIGHT\n");
				break;
			}
			kierunek = direction(in, x, y, m);
			break;
		}
		steps++;
		if (getChr(in, y, x, m) == 'K')
			break;
	} 
	fprintf(out, "STOP");
	fclose(out);
	return steps;
}
