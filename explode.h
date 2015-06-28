#ifndef EXPLODE_H
#define EXPLODE_H

#include "game.h"

class explode
{
public:
    explode();
    virtual~explode();
    virtual void explosion(int row, int col, candy *a[10][8])=0;
};

#endif // EXPLODE_H
