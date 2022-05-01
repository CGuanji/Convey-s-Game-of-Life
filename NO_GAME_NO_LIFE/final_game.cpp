#include "final_game.h"

final_game::final_game()
{

    init_array(_g,DEAD);

    for (int row=0; row<MAX; row++)
    {
        for (int col=0; col<MAX; col++){
            int vectorY=row*(10);
            int vectorX=col*(14);
            shape[row][col].setSize(sf::Vector2f(13,9));
            shape[row][col].setPosition(sf::Vector2f(vectorX,vectorY));

        }
    }
}
int final_game::Set_Alive_OR_DEAD(int i, int j)
{
   if(_g[i][j] == ALIVE)
   {
       return _g[i][j]= DEAD;
   }
   else
   {
       return _g[i][j] = ALIVE;
   }
}
int final_game::Set_Alive(int i, int j)
{
    return _g[i][j] = ALIVE;
}
int final_game::Kill(int i, int j)
{
   return _g[i][j] = DEAD;
}
int final_game::CountNeighbors(int i, int j)
{
    return count_neighbors(_g,i,j);
}
void final_game::cp(int a[][MAX])
{

    for (int i = 0;i < MAX;i++)
    {
        for (int j =0;j< MAX;j++)
        {
            a[i][j] = _g[i][j];
        }
    }
}
bool final_game::IsAlive(int _i, int _j)
{
    if(_g[_i][_j] == ALIVE)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void final_game::next_grid()
{

    step(_g);
}

int final_game::PopulateRamdom()           //r's random cell
{
    random_array(_g);
}
void final_game::clear()
{
    for (int i = 0;i < MAX;i++)
    {
        for (int j = 0;j < MAX;j++)
        {
            _g[i][j] = DEAD;
        }
    }
}
void final_game::Show()
{
    print_grid(_g);
}


void final_game::RANDOM(int lo, int hi)
{
    random(lo,hi);
}

void final_game::ShowShapes(sf::RenderWindow& window)
{
    for (int row=0; row<MAX; row++)
    {
        for (int col=0; col<MAX; col++)
        {
            window.draw(shape[row][col]);
        }
    }

}
//void final_game::ShowGrid(sf::RenderWindow& window)
//{
//    for (int row= 0; row<3; row++)
//    {
//        for (int col=0; col<3; col++)
//        {
//            window.draw(shape[row][col]);
//            shape[row][col].setFillColor(sf::Color::Red);

//        }
//    }
//}

void final_game::begin(/*sf::RenderWindow& window*/)
{

    for (int row=0; row < MAX; row++)
    {
        for (int col=0; col < MAX; col++){
            int vectorY=row*(10);
            int vectorX=col*(14);
            shape[row][col].setSize(sf::Vector2f(13,9));
            shape[row][col].setPosition(sf::Vector2f(vectorX,vectorY));
            if(_g[row][col] == ALIVE)
            {
                shape[row][col].setFillColor(sf::Color(114,137,218));
            }
            else
            {
                shape[row][col].setFillColor(sf::Color(143,241,212));
            }

        }
    }
}

void final_game::pixel_to_grid(int x,int y, int& i, int& j)
{
    int row_space = WORK_PANEL / MAX;
    int col_space = SCREEN_HEIGHT / MAX;

    j = x / row_space;
    i = y / col_space;


}

void final_game::grid_to_pixel(int x,int y, int i, int j)
{
    int x_length = SCREEN_WIDTH / MAX;
    int y_length = SCREEN_HEIGHT / MAX;
    x = x_length*i;
    y = y_length*j;
}

bool final_game::LOAD(char file[])
{
    load_array(file,_g);
}

bool final_game::SAVE(char file[])
{
    save_array(file,_g);
}

bool final_game::SAVE_PATTERN(char filename[], int row1, int col1, int row2, int col2)
{
    _col2 = col2;
    _col1 = col1;
    _row2 = row2;
    _row1 = row1;
    ofstream File;
    File.open(filename);
//    int row_width = _col2 - _col1;
//    int col_height = _row2 - _row1;
    int row_width = _row2-_row1;
    int col_height =_col2 -_col1;
    if(File.fail())
    {
        cout<<endl<<"couldn't open file for input"<<endl;
        exit(0);
    }
    File<<row_width<<" "<<col_height<<endl;
//    for (int i = row1;i < row_width+row1;i++)
//    {
//        for (int j = col1;j < col_height+col1;j++)
//        {
//           File<<_g[i][j]<<" ";
//           cout<<_g[i][j]<<" ";
//        }
//        cout<<endl;
//        File<<endl;
//    }
    for (int i = row1;i < row2;i++)
    {
        for (int j = col1;j < col2;j++)
        {
           File<<_g[i][j]<<" ";
           cout<<_g[i][j]<<" ";
        }
        cout<<endl;
        File<<endl;
    }
    File.close();
}

bool final_game::LOAD_PATTERN(char filename[], int row, int col)
{
    ifstream inFile;
    inFile.open(filename);
    if (inFile.fail())
    {
        cout<<endl<<"***** could not open file for input. ****"<<endl;
        exit(0);
    }
        //write the size of the array first...
//    int row_width = _col2 - _col1;
//    int col_height = _row2 - _row1;
    int row_width = _row2 - _row1;
    int col_height = _col2 - _col1;

    inFile>>row_width;
    inFile>>col_height;
//    for (int i = row; i < row_width+row; i++)
//    {
//        for (int j = col;j < col_height+col;j++)
//        {
//            inFile>>_g[i][j];
//            cout<<_g[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    for (int i = row; i < row_width+row; i++)
    {
        for (int j = col;j < col_height+col;j++)
        {
            inFile>>_g[i][j];
            cout<<_g[i][j]<<" ";
        }
        cout<<endl;
    }

    inFile.close();
}

