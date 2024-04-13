#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#pragma once
#include <string.h>
#define MAX_LINE_LENGTH 1024


struct maze {
	int size_x;
	int size_y;
	int start_x;
	int start_y;
	int end_x;
	int end_y;
	
};

struct movement {
	char dir;
	int x;
	int y;
	int xn;
	int yn; // x/y next
	int xp;
	int yp; // x/y previous
};
