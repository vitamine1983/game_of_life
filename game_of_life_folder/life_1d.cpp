#include "life_1d.h"
#include "vector"


Life_1D::Life_1D()
{
    array_w = 10;
    array_h = 10;
    array.resize(array_w * array_h);
    for(unsigned int x = 0; x < array_w; x++)
    {
        for(unsigned int y = 0; y < array_h; y++)
        {
            array[x * array_w + y] = false;
        }
    }
}

Life_1D::Life_1D(unsigned int x, unsigned int y)
{
    array_w = x;
    array_h = y;

    array.resize(array_w * array_h);

    for(unsigned int x = 0; x < array_w; x++)
    {
        for(unsigned int y = 0; y < array_h; y++)
        {
            array[x * array_w + y] = false;
        }
    }
}

void Life_1D::Clr() //Sets matrix to all dead
{
    for(unsigned int x = 0; x < array_w; x++)
    {
        for(unsigned int y = 0; y < array_h; y++)
        {
            array[x * array_w + y] = false;
        }
    }
}
char Life_1D::Set_cell_alive(unsigned int x, unsigned int y)
{
    if(x < this->array_w && y < this->array_h)
    {
        this->array[x * array_w + y] = true;
        return 1;
    }

    return 0;
}

char Life_1D::Set_cell_dead(unsigned int x, unsigned int y)
{
    if(x < this->array_w && y < this->array_h)
    {
        this->array[x * array_w + y] = false;
        return 1;
    }

    return 0;
}

bool Life_1D::Get_cell_life(unsigned int x, unsigned int y)
{
    if(x < this->array_w && y < this->array_h)
    {
        return array[x * array_w + y];
    }

    return 0;
}
void Life_1D::Clclt(Life_1D * array)
{
     unsigned int neighbors;
     if(array == nullptr)
     {
         return;
     }
     for (unsigned int m = 0; m < array_w; m++)
     {
         for (unsigned int n = 0; n < array_h; n++)
         {
             neighbors = 0;
             //Begin counting number of neighbors:
             if (((int)m-1 >=0 ) && ((int)n-1 >= 0) && (this->array[(m-1) * array_w + n-1] == true))
             {
                 neighbors += 1;
             }
             if (((int)m-1 >=0 ) 			  && (this->array[(m-1) * array_w + (n) ] == true))
             {
                 neighbors += 1;
             }
             if (((int)m-1 >=0 ) && (n+1 < this->array_h)  && (this->array[(m-1) * array_w + n+1] == true))
             {
                 neighbors += 1;
             }
             if (              ((int)n-1 >= 0) && (this->array[m * array_w + (n-1)] == true))
             {
                 neighbors += 1;
             }
             if (              (n+1 < array_h)  && (this->array[m *array_w + n+1] == true))
             {
                               neighbors += 1;
             }
             if ((m+1 < array_w ) && ((int)n-1 >= 0) && (this->array[(m+1) * array_w + n-1] == true))
             {neighbors += 1;}
             if ((m+1 < array_w )               && (this->array[(m+1) * array_w + n  ] == true))
             {neighbors += 1;}
             if ((m+1 < array_w ) && (n+1 < array_h)  && (this->array[(m+1) * array_w + n+1] == true))
             {neighbors += 1;}

             //Apply rules to the cell:
             if (this->array[m * array_w + n] == true && neighbors < 2)
             {
                array->array[m * array_w + n] = 0;
             }
             else if (this->array[m * array_w + n] == true && neighbors > 3)
             {
                array->array[m * array_w + n] = 0;
             }
             else if (this->array[m * array_w + n] == true && (neighbors == 2 || neighbors == 3))	//	Keep alive
             {
                array->array[m * array_w + n] = 1;
             }
             else if (this->array[m * array_w + n] == false && neighbors == 3)	//	Was dead, make alive
             {
                array->array[m * array_w + n] = 1;
             }
         }
     }
}

Life_1D& Life_1D::operator = (const Life_1D &other_life)
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
  array.resize(array_w * array_h);

  for(unsigned int x = 0; x < this->array_w; x++)
  {
      for(unsigned int y = 0; y < this->array_h; y++)
      {
        this->array[x * array_w + y] = other_life.array[x * array_w + y];
      }
  }
  return *this;
}
