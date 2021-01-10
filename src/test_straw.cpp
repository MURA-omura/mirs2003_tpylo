#include <cstdio>
#include <unistd.h>
#include "arduino.h"
#include "hand.hpp"
#include "spray.hpp"

int main(){
    Hand hand;
    Spray spray;
    const int actuate_count = 20;
    int count = 0;
    if(arduino_open() != 0) return -1;

    while(true){
        count++;
        bool pylo = hand.isExistHand();
        printf("%d\n", (int)pylo);

        if(pylo && count > actuate_count){
            count = 0;
            spray.pushBottle();
        }
        usleep(50000);
    }
    return 0;
}
