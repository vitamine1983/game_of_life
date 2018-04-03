#include "vector"
#include "life.h"
#include <stdlib.h>
#include <time.h>


Life::Life()
{
    array_w = 10;
    array_h = 10;

    array.resize(array_w, std::vector<bool>(array_h));
}

Life::~Life()
{
    //  Nenaudojam delete, nes nera malloc
}

Life::Life(unsigned int x, unsigned int y)
{
    array_w = x;
    array_h = y;

    array.resize(array_w, std::vector<bool>(array_h));
}

void Life::Clr() //Sets matrix to all dead
{
    for (unsigned int m = 0; m < this->array_w; m++)
    {
        for (unsigned int n = 0; n < this->array_h; n++)
        {
            this->array[m][n] = false;
        }
    }
}
char Life::Set_cell_alive(unsigned int x, unsigned int y)
{
    if(x < this->array_w && y < this->array_h)
    {
        this->array[x][y] = true;
        return 1;
    }

    return 0;
}

char Life::Set_cell_dead(unsigned int x, unsigned int y)
{
    if(x < this->array_w && y < this->array_h)
    {
        this->array[x][y] = false;
        return 1;
    }

    return 0;
}

bool Life::Get_cell_life(unsigned int x, unsigned int y)
{
    if(x < this->array_w && y < this->array_h)
    {
        return this->array[x][y];
    }

    return 0;
}
void Life::Clclt(Life * array)
{
     unsigned int neighbors;
     if(array == nullptr)
     {
         return;
     }
     for (unsigned int m = 0; m < this->array_w; m++)
     {
         for (unsigned int n = 0; n < this->array_h; n++)
         {
             neighbors = 0;
             //Begin counting number of neighbors:
             if (((int)m-1 >=0 ) && ((int)n-1 >= 0) && (this->array[m-1][n-1] == true)) {neighbors += 1;}
             if (((int)m-1 >=0 ) 			  && (this->array[m-1][n  ] == true)) {neighbors += 1;}
             if (((int)m-1 >=0 ) && (n+1 < this->array_h)  && (this->array[m-1][n+1] == true)) {neighbors += 1;}
             if (              ((int)n-1 >= 0) && (this->array[m  ][n-1] == true)) {neighbors += 1;}
             if (              (n+1 < this->array_h)  && (this->array[m  ][n+1] == true)) {neighbors += 1;}
             if ((m+1 < this->array_w ) && ((int)n-1 >= 0) && (this->array[m+1][n-1] == true)) {neighbors += 1;}
             if ((m+1 < this->array_w )               && (this->array[m+1][n  ] == true)) {neighbors += 1;}
             if ((m+1 < this->array_w ) && (n+1 < this->array_h)  && (this->array[m+1][n+1] == true)) {neighbors += 1;}

             //Apply rules to the cell:
             if (this->array[m][n] == true && neighbors < 2)
             {
                array->array[m][n] = 0;
             }
             else if (this->array[m][n] == true && neighbors > 3)
             {
                array->array[m][n] = 0;
             }
             else if (this->array[m][n] == true && (neighbors == 2 || neighbors == 3))	//	Keep alive
             {
                array->array[m][n] = 1;
             }
             else if (this->array[m][n] == false && neighbors == 3)	//	Was dead, make alive
             {
                array->array[m][n] = 1;
             }

         }
     }
}

void Life::Randomize()
{
    srand(time(NULL));
    for(unsigned int w = 0; w < array_w; w++)
    {
        for(unsigned int h = 0; h < array_h; h++)
        {
            unsigned int var = rand();
            if(var % 2)
            {
                this->Set_cell_alive(w, h);
            }
            else
            {
                this->Set_cell_dead(w, h);
            }
        }
    }

}

Life& Life::operator = (const Life &other_life)
{
  // Check for self-assignment!
    if(&other_life == nullptr)
    {
        return *this;
    }
  if (this == &other_life)  // Same object?
  {
    return *this;
  }
  this->array_h = other_life.array_h;
  this->array_w = other_life.array_w;
  this->array.resize(other_life.array_w, std::vector<bool>(other_life.array_h));

  for(unsigned int x = 0; x < this->array_w; x++)
  {
      for(unsigned int y = 0; y < this->array_h; y++)
      {
        this->array[x][y] = other_life.array[x][y];
      }
  }
  return *this;
}
