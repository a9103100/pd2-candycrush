#ifndef STRIPEDH_H
#define STRIPEDH_H

#include "explode.h"
#include <QObject>

class stripedh
{

public:
    stripedh();
    ~stripedh();
    void explosion(int row, int col, candy *a[10][8]);
};

#endif // STRIPEDH_H
