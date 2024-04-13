#include "macro.h"
#include "fhandling.h"


/*
zwraca "typ pola" na jakim sie znajdujemy
0 - prosta droga, 1 - skrzyzowanie/zakret
*/
int passageType(FILE* in, struct maze m, struct movement mov);



/*
oblicza nastepny i poprzedni punkt ruchu
*/
struct movement points(struct movement mov);


/*

*/
void alg(FILE* in, struct maze maz);



