#include "hand.hpp"


Hand::Hand(): pyro(pyro_pin){

}


bool Hand::isExistHand(){
    int sensor = pyro.getSw();
    return sensor == 1;

}
