#ifndef LIFE_H
#define LIFE_H

#include "vector"

class Life
{
public:
    std::vector<std::vector<bool>> array;
    unsigned int array_h;
    unsigned int array_w;
public:
    Life();
    ~Life();
    Life(unsigned int x, unsigned int y);
    char Set_cell_alive(unsigned int x, unsigned int y);
    char Set_cell_dead(unsigned int x, unsigned int y);
    bool Get_cell_life(unsigned int x, unsigned int y);

    void Clr();
    void Clclt(Life * array);
};

#endif // LIFE_H
