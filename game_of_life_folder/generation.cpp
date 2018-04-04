#include "generation.h"
#include "Life.h"
#include "life_1d.h"

void generation::initialize(Life * l)
{
    l->Randomize();
}

void generation::initialize(Life_1D * l)
{
    l->Randomize();
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
