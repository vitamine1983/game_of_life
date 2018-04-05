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
    Life next = *l;  //  Cia tam, kad nustatyti dydi kaip ir 'l'
    next.Clr();

    unsigned int neighbors;

    for (unsigned int m = 0; m < l->array_w; m++)
    {
        for (unsigned int n = 0; n < l->array_h; n++)
        {
            neighbors = 0;
            //Begin counting number of neighbors:
            if (((int)m-1 >=0 ) && ((int)n-1 >= 0) && (l->Get_cell_life(m-1, n-1) == true))
            {
                neighbors += 1;
            }
            if (((int)m-1 >=0 ) 			  && (l->Get_cell_life(m-1, n) == true))
            {
                neighbors += 1;
            }
            if (((int)m-1 >=0 ) && (n+1 < l->array_h)  && (l->Get_cell_life(m-1, n+1) == true))
            {
                neighbors += 1;
            }
            if (              ((int)n-1 >= 0) && (l->Get_cell_life(m, n-1) == true))
            {
                neighbors += 1;
            }
            if (              (n+1 < l->array_h)  && (l->Get_cell_life(m, n+1) == true))
            {
                              neighbors += 1;
            }
            if ((m+1 < l->array_w ) && ((int)n-1 >= 0) && (l->Get_cell_life(m+1, n-1) == true))
            {neighbors += 1;}
            if ((m+1 < l->array_w )               && (l->Get_cell_life(m+1, n) == true))
            {neighbors += 1;}
            if ((m+1 < l->array_w ) && (n+1 < l->array_h)  && (l->Get_cell_life(m+1, n+1) == true))
            {neighbors += 1;}


            //Apply rules to the cell:
                 if (l->Get_cell_life(m, n) == true && neighbors < 2)
            {
               next.Set_cell_dead(m, n);
            }
            else if (l->Get_cell_life(m, n) == true && neighbors > 3)
            {
               next.Set_cell_dead(m, n);
            }
            else if (l->Get_cell_life(m, n) == true && (neighbors == 2 || neighbors == 3))	//	Keep alive
            {
               next.Set_cell_alive(m, n);
            }
            else if (l->Get_cell_life(m, n) == false && neighbors == 3)	//	Was dead, make alive
            {
               next.Set_cell_alive(m, n);
            }
        }
    }

    *l = next;
}

void generation::generate(Life_1D * l)
{
    Life_1D next = *l;  //  Cia tam, kad nustatyti dydi kaip ir 'l'
    next.Clr();

    unsigned int neighbors;

    for (unsigned int m = 0; m < l->array_w; m++)
    {
        for (unsigned int n = 0; n < l->array_h; n++)
        {
            neighbors = 0;
            //Begin counting number of neighbors:
            if (((int)m-1 >=0 ) && ((int)n-1 >= 0) && (l->Get_cell_life(m-1, n-1) == true))
            {
                neighbors += 1;
            }
            if (((int)m-1 >=0 ) 			  && (l->Get_cell_life(m-1, n) == true))
            {
                neighbors += 1;
            }
            if (((int)m-1 >=0 ) && (n+1 < l->array_h)  && (l->Get_cell_life(m-1, n+1) == true))
            {
                neighbors += 1;
            }
            if (              ((int)n-1 >= 0) && (l->Get_cell_life(m, n-1) == true))
            {
                neighbors += 1;
            }
            if (              (n+1 < l->array_h)  && (l->Get_cell_life(m, n+1) == true))
            {
                              neighbors += 1;
            }
            if ((m+1 < l->array_w ) && ((int)n-1 >= 0) && (l->Get_cell_life(m+1, n-1) == true))
            {neighbors += 1;}
            if ((m+1 < l->array_w )               && (l->Get_cell_life(m+1, n) == true))
            {neighbors += 1;}
            if ((m+1 < l->array_w ) && (n+1 < l->array_h)  && (l->Get_cell_life(m+1, n+1) == true))
            {neighbors += 1;}


            //Apply rules to the cell:
                 if (l->Get_cell_life(m, n) == true && neighbors < 2)
            {
               next.Set_cell_dead(m, n);
            }
            else if (l->Get_cell_life(m, n) == true && neighbors > 3)
            {
               next.Set_cell_dead(m, n);
            }
            else if (l->Get_cell_life(m, n) == true && (neighbors == 2 || neighbors == 3))	//	Keep alive
            {
               next.Set_cell_alive(m, n);
            }
            else if (l->Get_cell_life(m, n) == false && neighbors == 3)	//	Was dead, make alive
            {
               next.Set_cell_alive(m, n);
            }
        }
    }

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
