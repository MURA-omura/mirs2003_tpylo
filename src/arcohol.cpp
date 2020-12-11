#include "arcohol.hpp"
#include "request.h"


Arcohol::Arcohol(){
    return;
}


int Arcohol::getSensor(){
    int pressure;
    request_get_arcohol(&pressure);
    return pressure;
}
