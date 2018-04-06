#ifndef LIFE_1D_H
#define LIFE_1D_H

#include "vector"
#include "string"

class Life_1D
{
private:
    std::vector<bool> array;
public:
    unsigned int array_h;
    unsigned int array_w;
    Life_1D();     //!< A life constructor.
    Life_1D(unsigned int x, unsigned int y);
    char Set_cell_alive(unsigned int x, unsigned int y);    //!< Sets cell alive
    char Set_cell_dead(unsigned int x, unsigned int y);     //!< Sets cell dead
    bool Get_cell_life(unsigned int x, unsigned int y);     //!< Returns cell alive status
    void Clr();
    void Clclt(Life_1D * array);
    void Randomize();
    std::string ToString();
    Life_1D& operator = (const Life_1D &other_life);  //!< Equation opeerator override
};

#endif // LIFE_H
