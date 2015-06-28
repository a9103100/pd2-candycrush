#ifndef WRAPPED_H
#define WRAPPED_H

#include "explode.h"
#include <QObject>


class wrapped
{
public:
    wrapped();
    ~wrapped();
    void explosion(int row, int col, candy *a[10][8]);
};

#endif // WRAPPED_H
