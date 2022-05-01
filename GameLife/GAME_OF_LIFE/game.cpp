#include "game.h"
#include <iostream>
#include <time.h>
#include <random>

using namespace std;

void display(int g[MAX][MAX],char command, bool done)
{
    do
    {
        print_grid(g);
        cout<<":";
        cin>>command;
        switch (toupper(command))
        {
            case 'R':
            {
               random_array(g);
               break;
            }
            case 'G':
            {
               break;
            }
            case 'S':
            {
               step(g);
               break;
            }
            case 'C':
            {
               break;
            }
            case 'T':
            {
               break;
            }
            case 'V':
            {
               save_array("file1.txt",g);
               break;
            }
            case 'L':
            {
                load_array("file1.txt",g);
               break;
            }
            case '?':
            {
               break;
            }
            case 'X':
            {
               done = true;
               break;
            }
        default:
            cout<<"invaild command";
            break;
        }
    }while(!done);
}

void print_grid(int g[][MAX])
{
    cout<<" ";
    for (int i = 0;i < MAX;i++)
    {
        cout<<"-";
    }
    cout<<endl;

    for (int i = 0;i < MAX;i++)
    {
        cout<<"|";
        for (int j = 0;j < MAX;j++)
        {

            if((i > 0 && i < MAX-1) && (j > 0) && (j < MAX-1))
            {
                if(g[i][j] == ALIVE)
                {
                    cout<<"X";
                }
                else
                {
                    cout<<" ";
                }
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<"|"<<endl;
    }
    cout<<"-";

    for (int i = 0;i < MAX;i++)
    {
        cout<<"-";
    }
    cout<<endl;
}
void init_array(int g[][MAX], int val)
{
   // cout<<"initial count: \n";
    for (int i = 0;i < MAX;i++)
    {
        for (int j = 0;j < MAX;j++)
        {
                g[i][j]= DEAD;
            //cout<<g[i][j]<<"  ";
          //  cout<<count_neighbors(g,i,j)<<" ";

        }
    }
    load_array("inital_world.txt",g);
    // glider
//    g[3][4]=ALIVE;
//    g[3][5]=ALIVE;
//    g[3][6]=ALIVE;
//    g[10][4]=ALIVE;
//    g[11][5]=ALIVE;
//    g[11][6]=ALIVE;
//    g[12][4]=ALIVE;
//    g[12][5]=ALIVE;
}
//int count_corner_celing(int g[][MAX],int i, int j)
//{
//    int count = 0;

//    if(i == 0 && j == 0)
//    {
//        if(g[i+1][j] == ALIVE)
//        {
//            count++;
//        }
//        if(g[i+1][j+1] == ALIVE)
//        {
//            count++;
//        }
//        if(g[i][j+1] == ALIVE)
//        {
//            count++;
//        }
//    }
// //   cout<<"count 1: "<<count<<endl;
//    if(i == 0 && j == MAX-1)
//    {
//        if(g[i+1][j] == ALIVE)
//        {
//            count++;
//        }
//        if(g[i][j-1] == ALIVE)
//        {
//            count++;
//        }
//        if(g[i+1][j-1] == ALIVE)
//        {
//            count++;
//        }
//    }
//  //  cout<<"count 2: "<<count<<endl;

//    if(j > 0 && j < MAX-1)
//    {
//        for (int k = i; k < i+2; k++)
//         {
//             for (int s = j-1; s < j+2; s++)
//             {
//                 if((g[k][s] == ALIVE))
//                 {
//                    count++;
//                    if(k ==i && s==j)
//                    {
//                         count--;
//                    }
//                 }
//             }
//         }
//    }


//    return count;

//}
//int count_corner_floor(int g[][MAX], int i, int j)
//{
//    int count = 0;

//    if(i == MAX-1 && j == MAX-1)
//    {
//        if(g[i][j-1] == ALIVE)
//        {
//            count++;
//        }
//        if(g[i-1][j-1] == ALIVE)
//        {
//            count++;
//        }
//        if(g[i-1][j] == ALIVE)
//        {
//            count++;
//        }
//    }
//    if(i == MAX-1 && j == 0)
//    {
//        if(g[i-1][j] == ALIVE)
//        {
//            count++;
//        }
//        if(g[i-1][j+1] == ALIVE)
//        {
//            count++;
//        }
//        if(g[i][j+1] == ALIVE)
//        {
//            count++;
//        }
//    }
//    if(j > 0 && j < MAX-1)
//    {
//        for (int k = i-1; k <= i; k++)
//        {
//            for (int s = j-1; s <= j+1; s++)
//            {
//                if((g[k][s] == ALIVE))
//                {
//                   count++;
//                   if(k ==i && s==j)
//                   {
//                        count--;
//                   }
//                }
//            }
//        }
//    }
//    return count;

//}
//int count_left_side_neighbors(int g[][MAX], int i, int j)
//{
//    int count = 0;
//    if(i == 0 && j == 0)
//    {
//        if(g[i+1][j] == ALIVE)
//        {
//            count++;
//        }
//        if(g[i+1][j+1] == ALIVE)
//        {
//            count++;
//        }
//        if(g[i][j+1] == ALIVE)
//        {
//            count++;
//        }
//    }
//    if(i == MAX-1 && j == 0)
//    {
//        if(g[i-1][j] == ALIVE)
//        {
//            count++;
//        }
//        if(g[i-1][j+1] == ALIVE)
//        {
//            count++;
//        }
//        if(g[i][j+1] == ALIVE)
//        {
//            count++;
//        }
//    }
//    if(i > 0 && i < MAX-1)
//    {
//        for (int k = i-1;k < i+2;k++)
//        {
//            for (int s = j;s < j+2; s++)
//            {
//                if((g[k][s] == ALIVE))
//                {
//                   count++;
//                   if(k ==i && s==j)
//                   {
//                        count--;
//                   }
//                }
//            }
//        }
//    }
//    return count;

//}
//int count_right_side_neighbors(int g[][MAX], int i, int j)
//{
//    int count = 0;
//    if(i == 0 && j == MAX-1)
//    {
//        if(g[i+1][j] == ALIVE)
//        {
//            count++;
//        }
//        if(g[i][j-1] == ALIVE)
//        {
//            count++;
//        }
//        if(g[i+1][j-1] == ALIVE)
//        {
//            count++;
//        }
//    }
//    if(i == MAX-1 && j == MAX-1)
//    {
//        if(g[i][j-1] == ALIVE)
//        {
//            count++;
//        }
//        if(g[i-1][j-1] == ALIVE)
//        {
//            count++;
//        }
//        if(g[i-1][j] == ALIVE)
//        {
//            count++;
//        }
//    }
//    if( (i > 0) && (i< MAX-1) )
//    {
//        for (int k = i-1;k < i+2;k++)
//        {
//            for (int s = j-1; s < j+1;s++)
//            {
//                if((g[k][s] == ALIVE))
//                {
//                   count++;
//                   if(k ==i && s==j)
//                   {
//                        count--;
//                   }
//                }
//            }
//        }
//    }
//    return count;

//}


int count_neighbors(int g[][MAX], int i, int j)
{
    int count = 0;
//    if(i == 0)
//    {
//       // cout<<"222\n";
//        count= count_corner_celing(g,i,j);
//    }
//    else if (i == MAX-1)
//    {
//     //   cout<<"333\n";
//        count = count_corner_floor(g,i,j);
//    }
//    else if(j == 0)
//    {
//        count = count_left_side_neighbors(g,i,j);
//    }
//    else if (j == MAX-1)
//    {
//        count = count_right_side_neighbors(g,i,j);
//    }

//    else if(i > 0 && j > 0)
//    {
        for (int k = i-1; k <= i+1; k++)
        {
            for (int s = j-1; s <= j+1; s++)
            {
                if((g[k][s] == ALIVE))
                {
                   count++;
                   if(k ==i && s==j)
                   {
                        count--;
                   }
                }
            }
        }
  //  }
 //   cout<<i<<","<<j<<" "<<count<<endl;
    return count;

}

int random(int lo, int hi)
{
    return rand()%(hi-lo+1)+lo;
}

void random_array(int g[][MAX])
{
    srand(time(0));
    for (int i = 1;i < MAX-1;i++)
    {
        for (int j = 1;j < MAX-1;j++)
        {
            if(g[i][j] != ALIVE)
            {
                g[i][j] = random(0,MAX-1);
            }
        }
    }
}

void copy_array(int dest[][MAX], int src[][MAX])
{
    int temp = 0;
   // cout<<"AAA:"<<endl;
    for (int i = 1;i < MAX-1;i++)
    {
        for (int j = 1;j < MAX-1;j++)
        {
            temp = src[i][j];
            dest[i][j] =  temp;
        }

    }
}
void step(int g[][MAX])
{
    int count;
    int a[MAX][MAX];
    for (int i = 0;i < MAX;i++)
    {
        for (int j = 0;j < MAX;j++)
        {
            a[i][j] = 0;
        }

    }

    circular_array(g);


    for (int i = 1;i < MAX-1;i++)
    {
        for (int j = 1;j < MAX-1;j++)
        {
            count = count_neighbors(g,i,j);

            if(count == 2)
            {
                a[i][j] = g[i][j];
            }
            else if(count == 3)
            {
                a[i][j] = ALIVE;
            }
            else if (count < 2)
            {
                a[i][j] = DEAD;
            }
            else if (count > 3)
            {
                a[i][j] = DEAD;
            }
            else {
                a[i][j] = DEAD;
            }

        }
    }
    copy_array(g,a);
}
void circular_array(int g[][MAX])
{

    for (int i = 1;i < MAX-1;i++)
    {
        // top and bottom change
        g[MAX-1][i] = g[1][i];
        g[0][i] = g[MAX-2][i];
        //left and right change
        g[i][0] = g[i][MAX-2];
        g[i][MAX-1] = g[i][1] ;
    }

    //four corner
    g[0][0]= g[MAX-2][MAX-2];
    g[MAX-1][MAX-1] = g[1][1];
    g[0][MAX-1] = g[MAX-2][1];
    g[MAX-1][0] = g[1][MAX-2];


}

bool save_array(char file_name[], int g[][MAX])
{
    ofstream oFile;
    oFile.open(file_name);
    if(oFile.fail())
    {
        cout<<endl<<"couldn't open file for input"<<endl;
        exit(0);
    }
    for (int i = 0;i < MAX;i++)
    {
        for (int j = 0;j < MAX;j++)
        {
           oFile<<g[i][j]<<" ";
        }
        oFile<<endl;
    }
    oFile.close();
}
bool load_array(char file_name[], int g[][MAX])
{
    ifstream inFile;
    inFile.open(file_name);
    if (inFile.fail())
    {
        cout<<endl<<"***** could not open file for input. ****"<<endl;
        exit(0);
    }
        //write the size of the array first...
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0;j < MAX;j++)
        {
            inFile>>g[i][j];
        }
    }

    inFile.close();
}
bool save_pa(char file_name[], int g[][MAX], int row_1, int col_1, int row_2, int col_2)
{
    ofstream File;
    File.open(file_name);
    row_width = col_2 - col_1;
    col_height = row_2 - row_2;
    if(File.fail())
    {
        cout<<endl<<"couldn't open file for input"<<endl;
        exit(0);
    }
    for (int i = 0;i < row_width;i++)
    {
        for (int j = 0;j < col_height;j++)
        {
           File<<g[i][j]<<" ";
        }
        File<<endl;
    }
    File.close();

}

bool load_pa(char file_name[], int g[][MAX], int row, int col)
{
    ifstream inFile;
    inFile.open(file_name);
    if (inFile.fail())
    {
        cout<<endl<<"***** could not open file for input. ****"<<endl;
        exit(0);
    }
        //write the size of the array first...
    for (int i = row; i < row_width; i++)
    {
        for (int j = col;j < col_height;j++)
        {
            inFile>>g[i][j];
        }
    }

    inFile.close();
}
