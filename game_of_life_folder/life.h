#ifndef LIFE_H
#define LIFE_H

#include "vector"
#include "string"

class Life
{
private:
    std::vector<std::vector<bool>> array;
    std::string str;
public:
    unsigned int array_h;
    unsigned int array_w;
    Life();     //!< A life constructor.
    ~Life();    //!< A life destructor
    Life(unsigned int x, unsigned int y);   //!< A life destructor. Initializes live matrix with spetial size.
    char Set_cell_alive(unsigned int x, unsigned int y);    //!< Sets cell alive
    char Set_cell_dead(unsigned int x, unsigned int y);     //!< Sets cell dead
    bool Get_cell_life(unsigned int x, unsigned int y);     //!< Returns cell alive status
    void Clr();
    void Clclt(Life * array);
    void Randomize();

    std::string ToString();
    Life& operator = (const Life &other_life);  //!< Equation opeerator override
};

#endif // LIFE_H
