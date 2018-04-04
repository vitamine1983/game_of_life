#ifndef GENERATION_H
#define GENERATION_H

#include "life.h"
#include "life_1d.h"

class generation
{
public:
    static void initialize(Life * l);
    static void initialize(Life_1D * l);
    static void generate(Life * l);
    static void generate(Life_1D * l);
};

#endif // GENERATION_H
