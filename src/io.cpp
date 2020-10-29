#include <stdio.h>
#include <wiringPi.h>
#include "io.hpp"

// ピン配置
// pin_sw_f 04
// pin_sw_l 05;
// pin_sw_r 06;

Io::Io(int pin){
	this.pin = pin;
	if(wiringPiSetupGpio() != 0){
		printf("failed to open GPIO\n");
	}
	else{
		pinMode(pin, INPUT);
		pullUpDnControl(pin, PUD_UP);
		printf("GPIO %d opened\n", pin);
	}
}

int Io::getSw(){
	return digitalRead(pin);
}
