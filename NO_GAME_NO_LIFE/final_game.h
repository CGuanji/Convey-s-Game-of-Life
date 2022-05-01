#ifndef FINAL_GAME_H
#define FINAL_GAME_H
#include <istream>
#include <fstream>
#include "../../../INCLUDE/GAME_OF_LIFE/game.h"
//#include "../../INCLUDE/GAME_OF_LIFE/game.h"
#include "../../INCLUDE/GAME_OF_LIFE/constants.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <constants1.h>
#include <vector>
using namespace std;

//const int SCREEN_WIDTH = 800;
//const int SCREEN_HEIGHT = 600;

class final_game
{
public:
    final_game();
    int Set_Alive_OR_DEAD(int i, int j);
    int Kill(int i, int j);
    int CountNeighbors(int i, int j);
    void cp(int a[][MAX]);
    void next_grid();
    int Set_Alive(int i, int j);

    int PopulateRamdom();          //r's random cell
    void clear();               //set all to dead
    void Show();                //print live or dead

    bool SAVE(char File[]);         //save file
    bool LOAD(char File[]);         //load file

    bool SAVE_PATTERN(char filename[], int row1, int col1, int row2, int col2);
    bool LOAD_PATTERN(char filename[], int row, int col);

    //graph grid
    void ShowShapes(sf::RenderWindow& window);
    void ShowGrid(sf::RenderWindow& window);

    void pixel_to_grid(int x, int y, int &i, int &j);           //convert pixel to griad
    void grid_to_pixel(int x,int y, int i, int j);
    void begin( );      //begin show on the sfml cell's liveness

    void RANDOM(int lo, int hi);




private:
    int _g[MAX][MAX];
    int _i;
    int _j;
    bool IsAlive(int _i, int _j);
    int _row1;
    int _row2;
    int _col1;
    int _col2;
    sf::RectangleShape shape[MAX][MAX];

};

#endif // FINAL_GAME_H

