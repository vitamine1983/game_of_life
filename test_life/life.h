#ifndef LIFE_H
#define LIFE_H


class life
{
public:
    bool ** array;
    unsigned int array_h;
    unsigned int array_w;
public:
    life();
    ~life();
    life(unsigned int height, unsigned int width);
    char set_cell_alive(unsigned int x, unsigned int y);
    char set_cell_dead(unsigned int x, unsigned int y);
    bool get_cell_life(unsigned int x, unsigned int y);

    void clr();
    void clclt(life * array);
};

#endif // LIFE_H
