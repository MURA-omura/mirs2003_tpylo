#include <unistd.h>

#include "arduino.h"
#include "move.hpp"


int main(){
    Move mover;
    if(arduino_open() != 0) return -1;

    while(true){
        mover.go();
        usleep(50000);
    }
    return 0;
}
