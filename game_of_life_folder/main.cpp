#include <iostream>
#include <iomanip>
#include "life.h"
#define H 30 //Define height
#define W 30 //Define width
using namespace std;

void swap(life * mata, life * matb) //Replaces first matrix with second
{
     for (int m = 0; m < H; m++)
     {
         for (int n = 0; n < W; n++)
         {
             if(matb->get_cell_life(m, n))
             {
                 mata->set_cell_alive(m, n);
             }
             else
             {
                 mata->set_cell_dead(m, n);
             }
         }
     }
}

void print(life * array) //Prints matrix to screen
{
     cout << setw(3) << " ";
     for (unsigned int p = 0; 5*p < array->array_w; p++) cout << setw(5) << 5*p+1;
     cout << endl;
     for (unsigned int m = 0; m < array->array_h; m++)
     {
         cout << setw(3) << m+1;
         for (unsigned int n = 0; n < array->array_w; n++)
         {
             if (array->array[m][n])
             {
                 cout << "\xDB";
             }
             else
             {
                 cout << /*"\xB1"*/"-";
             }
         }
         cout << endl;
     }
}

int main()
{
    int x, y, cont; //Used for user input

    life * now = new life(H, W);
    life * next = new life(H, W);

    cout << "The Rules of Life:" << endl;
    cout << "1. Any live cell with fewer than two live neighbors dies, as if by loneliness." << endl;
    cout << "2. Any live cell with more than three live neighbors dies, as if by \novercrowding." << endl;
    cout << "3. Any live cell with two or three live neighbors lives, unchanged." << endl;
    cout << "4. Any dead cell with exactly three live neighbors comes to life." << endl << endl;
    cout << "To play: Press any key to begin. Enter the column and row of a cell to make \nalive, separated by a space. ";
    cout << "When you are ready, enter \"-1\" to begin the \nsimulation. Then enter any number to continue or \"-1\" to quit." << endl;
//    cin.get();

    now->clr();
    //print(now);

    do //Get initial state
    {
        cin >> x;
        if (x == -1)
        {
            break; //User is done inputting
        }
        cin >> y;
        now->set_cell_alive(y-1, x-1); //Sets cell to alive
        //print(now); //Updates screen
    }while(x != -1);

    do //Keep updating new generations
    {
        next->clr();
        now->clclt(next);
        swap(now, next);
        print(now);
        cout << "Press '-1' to exit"<< endl;
        cin>>cont;
    }while(cont != -1);

    return 0;
}
