#include "macro.h"

/*
Okresla ilosc kolumn i wierszy w pliku
*/
struct size mazeSize(FILE *in);

/*
Zamienia znak w pliku o wspolrzednych (x,y) na znak a
*/
int replaceChr(FILE* in, int y, int x, char a, struct size s);


/*
Zwraca znak na danej pozycji
*/
char getChr(FILE* in, int y, int x, struct size s);
