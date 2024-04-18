#include<stdio.h>
#include<stdlib.h>
#pragma once
#include <string.h>
#define MAX_LINE_LENGTH 1024

#define SWAP_2(x) ( (((x) & 0xff) << 8) | ((unsigned short)(x) >> 8) )
#define SWAP_4(x) ( ((x) << 24) | \
         (((x) << 8) & 0x00ff0000) | \
         (((x) >> 8) & 0x0000ff00) | \
         ((x) >> 24) )
#define FIX_SHORT(x) (*(unsigned short *)&(x) = SWAP_2(*(unsigned short *)&(x)))
#define FIX_INT(x)   (*(unsigned int *)&(x)   = SWAP_4(*(unsigned int *)&(x)))


struct maze {
	int size_x;
	int size_y;
	int start_x;
	int start_y;
	int end_x;
	int end_y;
	
};

struct movement {
	char dir; // movement direction
	int x;
	int y;  // x/y current
	int xn;
	int yn; // x/y next
	int xp;
	int yp; // x/y previous
};
