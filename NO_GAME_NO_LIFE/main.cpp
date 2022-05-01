#include <iostream>
//#include "../../INCLUDE/GAME_OF_LIFE/array_game.h"
#include "final_game.h"

using namespace std;
void display_result(final_game a);
void test_game();

int main()
{ 
    test_game();
    return 0;
}
void test_game()
{
    final_game a;
    display_result(a);
}

void display_result(final_game a)
{
    bool done = false;
    char command;

//    int g[MAX][MAX];
//    a.initial(g);

    do
    {
        a.Show();
        cout<<": ";
        cin>>command;
        switch (toupper(command))
        {
            case 'S':
            {
                a.next_grid();
                break;
            }
            case 'R':
            {
                a.PopulateRamdom();
                break;
            }
            case 'X':
            {
                done = true;
                break;
            }
            case 'L':
            {
                a.LOAD("file2.txt");
                break;
            }
            case 'V':
            {
                a.SAVE("file2.txt");
                break;
            }
        }
    }while(!done);

}
