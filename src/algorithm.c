#include "algorithm.h"



int passageType(FILE *in, struct maze m, struct movement mov) {

	if (getChr(in, mov.yn, mov.xn, m) != 'X') {
		if (mov.dir == 'u' || mov.dir == 'd') {
			if (getChr(in, mov.y, mov.x + 1, m) == 'X' && getChr(in, mov.y, mov.x - 1, m) == 'X')
				return 0;
			else
				return 1;

		}
		else if (mov.dir == 'r' || mov.dir == 'l') {
			if (getChr(in, mov.y + 1, mov.x, m) == 'X' && getChr(in, mov.y - 1, mov.x, m) == 'X')
				return 0;
			else
				return 1;
		}
	}
	else
		return 1;
}

struct movement points(struct movement mov) {

	switch (mov.dir) {

	case 'l':
		mov.xp = mov.x + 1;
		mov.yp = mov.y;
		mov.xn = mov.x - 1;
		mov.yn = mov.y;
		break;

	case 'r':
		mov.xp = mov.x - 1;
		mov.yp = mov.y;
		mov.xn = mov.x + 1;
		mov.yn = mov.y;
		break;

	case 'u':
		mov.xp = mov.x;
		mov.yp = mov.y + 1;
		mov.xn = mov.x;
		mov.yn = mov.y - 1;
		break;

	case 'd':
		mov.xp = mov.x;
		mov.yp = mov.y - 1;
		mov.xn = mov.x;
		mov.yn = mov.y + 1;
		break;

	}

	return mov;
	
}

char baseDirection(struct maze m) {

	char d;

	if (m.start_x == 0)
		d = 'r';
	else if (m.start_y == 0)
		d = 'd';
	else if (m.start_x == m.size_x - 1)
		d = 'l';
	else if (m.start_y == m.size_y - 1)
		d = 'u';

	return d;
		
}

int isFinished(FILE* in, struct maze maz, struct movement mov) {

	if (getChr(in, mov.y + 1, mov.x, maz) == 'K' || getChr(in, mov.y - 1, mov.x, maz) == 'K' || getChr(in, mov.y, mov.x - 1, maz) == 'K' || getChr(in, mov.y, mov.x + 1, maz) == 'K')
		return 1;
	else
		return 0;
}

char chooseExit(FILE* in, struct maze maz, struct movement mov) {

	// 1 tylko tam skad przyszlismy jest mark, gdziekolwiek gdzie nie ma marka

	// 2 cos innego tez jest zmarkowane, wracamy

	// 3 tam skad przyszlismy jest mark x2, gdziekolwiek gdzie najmniej markow


	int rule = 1;
	char d = 'a';
	int i;
	switch (mov.dir) {
	case 'l':
		d = 'r';
		//opcja 1
		if (getChr(in, mov.y - 1, mov.x, maz) != 'X') {
			if (getChr(in, mov.y - 1, mov.x, maz) != ' ')
				rule = 2;
			else
				d = 'u';
		}

		if (rule == 1 && getChr(in, mov.y + 1, mov.x, maz) != 'X') {
			if (getChr(in, mov.y + 1, mov.x, maz) != ' ')
				rule = 2;
			else
				d = 'd';
		}

		if (rule == 1 && getChr(in, mov.y, mov.x - 1, maz) != 'X'){
			if (getChr(in, mov.y, mov.x - 1, maz) != ' ')
				rule = 2;
			else
				d = 'l';
		}
		if (rule == 1)
			return d;
	
		//opcja 2
		if (getChr(in, mov.yp, mov.xp, maz) != '2')
				return 'r';


		//opcja 3
		
		for (i = 0; i < 2; i++) {

			if (getChr(in, mov.y - 1, mov.x, maz) != 'X')
				if (getChr(in, mov.y - 1, mov.x, maz) - '0' == i || getChr(in, mov.y - 1, mov.x, maz) == ' ')
					return 'u';

			if (getChr(in, mov.y + 1, mov.x, maz) != 'X')
				if (getChr(in, mov.y + 1, mov.x, maz) - '0' == i || getChr(in, mov.y + 1, mov.x, maz) == ' ')
					return 'd';
			
			if (getChr(in, mov.y, mov.x - 1, maz) != 'X')
				if (getChr(in, mov.y, mov.x - 1, maz) - '0' == i || getChr(in, mov.y, mov.x - 1, maz) == ' ')
					return 'l';
		}

		break;

	case 'r':
	
		d = 'l';
		//opcja 1
		if (getChr(in, mov.y - 1, mov.x, maz) != 'X') {
			if (getChr(in, mov.y - 1, mov.x, maz) != ' ')
				rule = 2;
			else
				d = 'u';
		}

		if (rule == 1 && getChr(in, mov.y + 1, mov.x, maz) != 'X') {
			if (getChr(in, mov.y + 1, mov.x, maz) != ' ')
				rule = 2;
			else
				d = 'd';
		}

		if (rule == 1 && getChr(in, mov.y, mov.x + 1, maz) != 'X') {
			if (getChr(in, mov.y, mov.x + 1, maz) != ' ')
				rule = 2;
			else
				d = 'r';
		}
		if (rule == 1)
			return d;

		//opcja 2
		if (getChr(in, mov.yp, mov.xp, maz) != '2')
			return 'l';


		//opcja 3

		for (i = 0; i < 2; i++) {

			if (getChr(in, mov.y - 1, mov.x, maz) != 'X')
				if (getChr(in, mov.y - 1, mov.x, maz) - '0' == i || getChr(in, mov.y - 1, mov.x, maz) == ' ')
					return 'u';

			if (getChr(in, mov.y + 1, mov.x, maz) != 'X')
				if (getChr(in, mov.y + 1, mov.x, maz) - '0' == i || getChr(in, mov.y + 1, mov.x, maz) == ' ')
					return 'd';

			if (getChr(in, mov.y, mov.x + 1, maz) != 'X')
				if (getChr(in, mov.y, mov.x + 1, maz) - '0' == i || getChr(in, mov.y, mov.x + 1, maz) == ' ')
					return 'r';
		}
		break;

	case 'u':
		
		d = 'd';
		//opcja 1
		if (getChr(in, mov.y, mov.x + 1, maz) != 'X') {
			if (getChr(in, mov.y, mov.x + 1, maz) != ' ')
				rule = 2;
			else
				d = 'r';
		}

		if (rule == 1 && getChr(in, mov.y - 1, mov.x, maz) != 'X') {
			if (getChr(in, mov.y - 1, mov.x, maz) != ' ')
				rule = 2;
			else
				d = 'u';
		}

		if (rule == 1 && getChr(in, mov.y, mov.x - 1, maz) != 'X') {
			if (getChr(in, mov.y, mov.x - 1, maz) != ' ')
				rule = 2;
			else
				d = 'l';
		}
		if (rule == 1)
			return d;

		//opcja 2
		if (getChr(in, mov.yp, mov.xp, maz) != '2')
			return 'd';


		//opcja 3

		for (i = 0; i < 2; i++) {

			if (getChr(in, mov.y - 1, mov.x, maz) != 'X')
				if (getChr(in, mov.y - 1, mov.x, maz) - '0' == i || getChr(in, mov.y - 1, mov.x, maz) == ' ')
					return 'u';

			if (getChr(in, mov.y, mov.x + 1, maz) != 'X')
				if (getChr(in, mov.y, mov.x + 1, maz) - '0' == i || getChr(in, mov.y, mov.x + 1, maz) == ' ')
					return 'r';

			if (getChr(in, mov.y, mov.x - 1, maz) != 'X')
				if (getChr(in, mov.y, mov.x - 1, maz) - '0' == i || getChr(in, mov.y, mov.x - 1, maz) == ' ')
					return 'l';
		}

		break;

	case 'd':
		d = 'u';
		//opcja 1
		if (getChr(in, mov.y, mov.x + 1, maz) != 'X') {
			if (getChr(in, mov.y, mov.x + 1, maz) != ' ')
				rule = 2;
			else
				d = 'r';
		}

		if (rule == 1 && getChr(in, mov.y + 1, mov.x, maz) != 'X') {
			if (getChr(in, mov.y + 1, mov.x, maz) != ' ')
				rule = 2;
			else
				d = 'd';
		}

		if (rule == 1 && getChr(in, mov.y, mov.x - 1, maz) != 'X') {
			if (getChr(in, mov.y, mov.x - 1, maz) != ' ')
				rule = 2;
			else
				d = 'l';
		}
		if (rule == 1)
			return d;

		//opcja 2
		if (getChr(in, mov.yp, mov.xp, maz) != '2')
			return 'u';


		//opcja 3

		for (i = 0; i < 2; i++) {

			if (getChr(in, mov.y, mov.x + 1, maz) != 'X')
				if (getChr(in, mov.y, mov.x + 1, maz) - '0' == i || getChr(in, mov.y, mov.x + 1, maz) == ' ')
					return 'r';

			if (getChr(in, mov.y + 1, mov.x, maz) != 'X')
				if (getChr(in, mov.y + 1, mov.x, maz) - '0' == i || getChr(in, mov.y + 1, mov.x, maz) == ' ')
					return 'd';

			if (getChr(in, mov.y, mov.x - 1, maz) != 'X')
				if (getChr(in, mov.y, mov.x - 1, maz) - '0' == i || getChr(in, mov.y, mov.x - 1, maz) == ' ')
					return 'l';
		}

		break;
	}
}

void alg(FILE *in, struct maze maz) {

	struct movement mov;
	mov.x = maz.start_x;
	mov.y = maz.start_y;
	mov.dir = baseDirection(maz);

	mov = points(mov);

	int tsj = 0; // time since juncture

	while (!isFinished(in, maz, mov)) {

		//Sleep(2000);

		// jest prosta droga
		if (!passageType(in, maz, mov)) {
			mov.x = mov.xn;
			mov.y = mov.yn;

			mov = points(mov);

			tsj++;
		}
		//jest jakas zmiana
		else {

			if (tsj >= 2) {
				//zaznaczanie wejscia przez ktore weszlismy na skrzyzowanie jezeli nie ma skrzyzowania po skrzyzowaniu
				if (getChr(in, mov.yp, mov.xp, maz) == ' ')
					replaceChr(in, mov.yp, mov.xp, '1', maz);
				else if (getChr(in, mov.yp, mov.xp, maz) == '1')
					replaceChr(in, mov.yp, mov.xp, '2', maz);
			}

			mov.dir = chooseExit(in, maz, mov);
			mov = points(mov);

			mov.x = mov.xn;
			mov.y = mov.yn;
			mov = points(mov);

			//zaznaczenie punktu wyjscia
			if (getChr(in, mov.y, mov.x, maz) == ' ')
				replaceChr(in, mov.y, mov.x, '1', maz);
			else if (getChr(in, mov.y, mov.x, maz) == '1')
				replaceChr(in, mov.y, mov.x, '2', maz);

			tsj = 0;
		}
		//printf("Pos: %d/%d, tsj: %d, dir: %c\n", mov.x, mov.y, tsj, mov.dir);
		//getc(stdin);


	}
	



}
