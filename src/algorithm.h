#include "macro.h"
#include "fhandling.h"


/*
zwraca "typ pola" na jakim sie znajdujemy
0 - prosta droga, 1 - skrzyzowanie/zakret, 2 - zaulek jednokratkowy
*/
int passageType(FILE* in, struct maze m, struct movement mov);



/*
oblicza nastepny i poprzedni punkt ruchu
*/
struct movement points(struct movement mov);

/*
okresla poczatkowy kierunek 
*/
char baseDirection(struct maze m);


/*
definiuje kierunek w którym wychodzimy ze skrzyżowania
*/
char chooseExit(FILE* in, struct maze maz, struct movement mov);


/*

*/
void alg(FILE* in, struct maze maz);




