#include "generation.h"
#include "Life.h"
#include "life_1d.h"
#include <sstream>
#include <iostream>
#include <iomanip>

char rules_str[] = "The Rules of Life:\r\n ; \
1. Any live cell with fewer than two live neighbors dies, as if by loneliness.\r\n \
2. Any live cell with more than three live neighbors dies, as if by \novercrowding.\r\n \
3. Any live cell with two or three live neighbors lives, unchanged.\r\n \
4. Any dead cell with exactly three live neighbors comes to life.\r\n \
To play: Choise life type enter 1 - for 1D array type, 2 - for 2D array type\r\n";

char reminder_str[] = "Manual - enter X and Y\r\n \
        Automatic - uses rand function '-2' option\r\n \
        When you are ready, enter \"-1\"\r\n";

char iteration_str[] = "Enter any number to continue or \"-1\" to quit.\r\n";

void generation::initialize(Life * l)
{
    std::cout << rules_str;
    l->Randomize();
    std::cout << l->ToString();
    std::cout << reminder_str;
}

void generation::initialize(Life_1D * l)
{
    std::cout << rules_str;
    l->Randomize();
    std::cout << l->ToString();
    std::cout << reminder_str;
}

void generation::generate(Life * l)
{
    Life next = *l;
    next.Clr();
    l->Clclt(&next);
    *l = next;
}

void generation::generate(Life_1D * l)
{
    Life_1D next = *l;
    next.Clr();
    l->Clclt(&next);
    *l = next;
}

void generation::run(Life * now)
{
    int cont = -1;
    std::cin >> cont;
    do //Keep updating new generations
    {
        generate(now);
        std::cout << now->ToString();
        std::cout << iteration_str;
 //       std::cin.putback('1');
        std::cin >> cont;
    }while(cont != -1);
}
void generation::run(Life_1D * now)
{
    int cont = 0;
    do //Keep updating new generations
    {
        generate(now);
        std::cout << now->ToString();
        std::cout << iteration_str;
 //       cin.putback('1');
        std::cin >> cont;
    }while(cont != -1);
}
