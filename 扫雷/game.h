#pragma once

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//≥ı ºªØ∆Â≈Ã
void initboard(char board[ROWS][COLS], int rows, int cols, char set);
//¥Ú”°∆Â≈Ã
void displayboard(char board[ROWS][COLS], int row, int col);
//≤º÷√¿◊
void setmine(char board[ROWS][COLS], int row, int col);
//≈≈≤È¿◊
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
