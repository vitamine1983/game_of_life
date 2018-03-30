#include "life.h"

life::life()
{
    array_w = 30;
    array_h = 30;

    this->array = new bool*[array_w];
    for(unsigned int i = 0; i < array_w; i++)
    {
        this->array[i] = new bool[array_h];
    }

}

life::~life()
{
    for(unsigned int i = 0; i < array_w; i++)
    {
        delete[] array[i];
    }
    delete[] array;
}
life::life(unsigned int height, unsigned int width)
{
    array_w = width;
    array_h = height;

    this->array = new bool*[array_w];
    for(unsigned int i = 0; i < array_w; i++)
        this->array[i] = new bool[array_h];
}

void life::clr() //Sets matrix to all dead
{
    for (unsigned int m = 0; m < this->array_h; m++)
    {
        for (unsigned int n = 0; n < this->array_h; n++)
        {
            this->array[m][n] = false;  //  there is dynamic array we unable to use memsed
        }
    }
}
char life::set_cell_alive(unsigned int x, unsigned int y)
{
    if(x < this->array_w && y < this->array_h)
    {
        this->array[x][y] = true;
        return 1;
    }
    return 0;
}

char life::set_cell_dead(unsigned int x, unsigned int y)
{
    if(x < this->array_w && y < this->array_h)
    {
        this->array[x][y] = 0;
        return 1;
    }
    return 0;
}

bool life::get_cell_life(unsigned int x, unsigned int y)
{
    if(x < this->array_w && y < this->array_h)
    {
        return this->array[x][y];
    }
    return 0;
}
void life::clclt(life * array)
{
     unsigned int neighbors;
     for (unsigned int m = 0; m < this->array_h; m++)
     {
         for (unsigned int n = 0; n < this->array_w; n++)
         {
             neighbors = 0;
             //Begin counting number of neighbors:
             if (((int)m-1 >=0 ) && ((int)n-1 >= 0) && (this->array[m-1][n-1] == true)) {neighbors += 1;}
             if (((int)m-1 >=0 ) 			  && (this->array[m-1][n  ] == true)) {neighbors += 1;}
             if (((int)m-1 >=0 ) && (n+1 < this->array_w)  && (this->array[m-1][n+1] == true)) {neighbors += 1;}
             if (              ((int)n-1 >= 0) && (this->array[m  ][n-1] == true)) {neighbors += 1;}
             if (              (n+1 < this->array_w)  && (this->array[m  ][n+1] == true)) {neighbors += 1;}
             if ((m+1 < this->array_h ) && ((int)n-1 >= 0) && (this->array[m+1][n-1] == true)) {neighbors += 1;}
             if ((m+1 < this->array_h )               && (this->array[m+1][n  ] == true)) {neighbors += 1;}
             if ((m+1 < this->array_h ) && (n+1 < this->array_w)  && (this->array[m+1][n+1] == true)) {neighbors += 1;}

             //Apply rules to the cell:
             if (this->array[m][n] == true && neighbors < 2)
             {
                array->array[m][n] = false;
             }
             else if (this->array[m][n] == true && neighbors > 3)
             {
                array->array[m][n] = false;
             }
             else if (this->array[m][n] == true && (neighbors == 2 || neighbors == 3))	//	Keep alive
             {
                array->array[m][n] = true;
             }
             else if (this->array[m][n] == false && neighbors == 3)	//	Was dead, make alive
             {
                array->array[m][n] = true;
             }

         }
     }
}
