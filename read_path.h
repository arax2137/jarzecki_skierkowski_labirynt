#include "macro.h"
#include "fhandling.h"

char direction(FILE* in,int x,int y, struct maze m);

void read_path(FILE* in, struct maze m);

int last_step(FILE* in, int x, int y, struct maze m);
