#include "vector"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "life.h"
#include "life_1d.h"
#include <assert.h>

using namespace std;

char rules[] = "The Rules of Life:\r\n ; \
1. Any live cell with fewer than two live neighbors dies, as if by loneliness.\r\n \
2. Any live cell with more than three live neighbors dies, as if by \novercrowding.\r\n \
3. Any live cell with two or three live neighbors lives, unchanged.\r\n \
4. Any dead cell with exactly three live neighbors comes to life.\r\n \
To play: Choise life type enter 1 - for 1D array type, 2 - for 2D array type";

char iteration[] = "Enter any number to continue or \"-1\" to quit.\r\n";

char reminder[] = "Manual - enter X and Y\r\n \
        Automatic - uses rand function '-2' option\r\n \
        When you are ready, enter \"-1\"\r\n";


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

int main()
{
    int cont; //Used for user input

    Life_1D now, next;

    cout << rules;
    cout << now.ToString();

    do //Get initial state or randomize
    {
        cin >> cont;
        if (cont == -1)
        {
            break; //User is done inputting
        }

        now.Randomize();

        cout << now.ToString();
        cout << reminder;
    }while(cont != -1);

    do //Keep updating new generations
    {
        next.Clr();
        now.Clclt(&next);
        now = next;
        cout << now.ToString();
        cout << iteration;
        cin >> cont;
    }while(cont != -1);

    return 0;
}
