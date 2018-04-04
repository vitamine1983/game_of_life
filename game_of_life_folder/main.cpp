#include "vector"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "life.h"
#include "life_1d.h"
#include <assert.h>
#include "generation.h"

using namespace std;

char rules_str[] = "The Rules of Life:\r\n ; \
1. Any live cell with fewer than two live neighbors dies, as if by loneliness.\r\n \
2. Any live cell with more than three live neighbors dies, as if by \novercrowding.\r\n \
3. Any live cell with two or three live neighbors lives, unchanged.\r\n \
4. Any dead cell with exactly three live neighbors comes to life.\r\n \
To play: Choise life type enter 1 - for 1D array type, 2 - for 2D array type";

char iteration_str[] = "Enter any number to continue or \"-1\" to quit.\r\n";

char reminder_str[] = "Manual - enter X and Y\r\n \
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

    Life_1D now;

    cout << rules_str;
    cout << now.ToString();
    generation::initialize(&now);
    cout << now.ToString();
    cout << reminder_str;

    cin >> cont;
    do //Keep updating new generations
    {
        generation::generate(&now);
        cout << now.ToString();
        cout << iteration_str;
        cin >> cont;
    }while(cont != -1);
    return 0;
}
