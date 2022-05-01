#ifndef GAME_H
#define GAME_H
#include <iostream>
//#include "constants.h"
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

static const int MAX = 80;
static const int DEAD = 0;
static const int ALIVE = 1;
int row_width , col_height;

void print_grid(int g[][MAX]);
void init_array(int g[][MAX], int val=DEAD);
void step(int g[][MAX]);
void copy_array(int dest[][MAX], int src[][MAX]);
void circular_array(int g[][MAX]);

//count neighbors
int count_corner_celing(int g[][MAX],int i, int j);
int count_corner_floor(int g[][MAX], int i, int j);
int count_left_side_neighbors(int g[][MAX], int i, int j);
int count_right_side_neighbors(int g[][MAX], int i, int j);
int count_neighbors(int g[][MAX], int i, int j);

int random(int lo, int hi);
void random_array(int g[][MAX]);

bool save_array(char file_name[], int g[][MAX]);
bool load_array(char file_name[], int g[][MAX]);


//bool save_pa(char file_name[], int g[][MAX], int row_1, int col_1, int row_2, int col_2);
//bool load_pa(char file_name[], int g[][MAX], int row, int col);




#endif // GAME_H
