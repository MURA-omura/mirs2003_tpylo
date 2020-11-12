#include "arcohol.hpp"
#include "request.h"


Arcohol::Arcohol(){

}


int Arcohol::getSensor(){
    int pressure;
    request_get_arcohol(&pressure);
    return pressure;
}
