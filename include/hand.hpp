#ifndef __HAND__
#define __HAND__

#include "io.hpp"

class Hand()
{
public:
    Hand();
    bool isExistHand();
    int getSensor();

private:
    Io pyro;
};

#endif
