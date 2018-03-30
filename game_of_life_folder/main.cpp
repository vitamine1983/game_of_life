#include "vector"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "life.h"
#include <assert.h>

#define Y 5 //Define height
#define X 10//Define width
using namespace std;

void print_tst()
{
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    std::cout << "hello world\n";

    std::cout.rdbuf(p_cout_streambuf); // restore

    // test your oss content...
    assert(oss && oss.str() == "hello world\n");
    std::cout << oss.str();
}

void print(Life * array) //Prints matrix to screen
{
     cout << setw(3) << " ";
     for (unsigned int p = 0; 5*p < array->array_w; p++) cout << setw(5) << 5*p+1;
     cout << endl;
     for (unsigned int m = 0; m < array->array_h; m++)
     {
         cout << setw(3) << m + 1;
         for (unsigned int n = 0; n < array->array_w; n++)
         {
             if(! (n % 5))
             {
                 cout << "|";
             }
             if (array->array[n][m])
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

    Life * now = new Life(X, Y);
    Life * next = new Life(X, Y);
    print_tst();
    cout << "The Rules of Life:" << endl;
    cout << "1. Any live cell with fewer than two live neighbors dies, as if by loneliness." << endl;
    cout << "2. Any live cell with more than three live neighbors dies, as if by \novercrowding." << endl;
    cout << "3. Any live cell with two or three live neighbors lives, unchanged." << endl;
    cout << "4. Any dead cell with exactly three live neighbors comes to life." << endl << endl;
    cout << "To play: Press any key to begin. Enter the column and row of a cell to make \nalive, separated by a space. ";
    cout << "When you are ready, enter \"-1\" to begin the \nsimulation. Then enter any number to continue or \"-1\" to quit." << endl;
    cin.get();
    cout << "Continue" << endl;
    now->Clr();
    cout << "Cleared" << endl;
    print(now);

    do //Get initial state
    {
        cin >> x;
        if (x == -1)
        {
            break; //User is done inputting
        }
        cin >> y;
        now->Set_cell_alive(x-1, y-1); //Sets cell to alive
        print(now); //Updates screen
    }while(x != -1);

    do //Keep updating new generations
    {
        next->Clr();
        now->Clclt(next);
        //swap(now, next);
        *now = *next;
        print(now);
        cout << "Press '-1' to exit"<< endl;
        cin>>cont;
    }while(cont != -1);

    return 0;
}
