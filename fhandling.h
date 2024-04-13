#include "macro.h"

/*
Okresla ilosc kolumn i wierszy w pliku
*/
struct maze mazeData(FILE *in);

/*
Zamienia znak w pliku o wspolrzednych (x,y) na znak a
*/
int replaceChr(FILE* in, int y, int x, char a, struct maze s);


/*
Zwraca znak na danej pozycji
*/
char getChr(FILE* in, int y, int x, struct maze s);

/*
Resetuje wskaznik do pozycji poczatkowej pliku 
*/
void resetPointer(FILE* f);

/*
Funkcja zajmujaca się kopiowaniem pliku macierzystego do pliku, który będzie zawierał rozwiązanie
*/
FILE* copy_file(const char* file_name);
