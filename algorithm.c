#include "algorithm.h"



int passageType(FILE *in, struct maze m, struct movement mov) {

	if (getChr(in, mov.yn, mov.xn, m) == ' ') {
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





void alg(FILE *in, struct maze maz) {

	struct movement mov;
	mov.x = maz.start_x;
	mov.y = maz.start_y;
	






}