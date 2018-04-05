#include "life.h"
#include "life_1d.h"
#include "generation.h"

int main()
{
    Life_1D now;

    generation::initialize(&now);
    generation::run(&now);

    return 0;
}
