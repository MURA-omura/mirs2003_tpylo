/**
 * @file io.cpp
 * @brief ピン番号のプログラム
 * @author 岡部
 * @date 2020/11/11
 */

#include <stdio.h>
#include <wiringPi.h>
#include "io.hpp"

// ピン配置
// pin_sw_f 04
// pin_sw_l 05;
// pin_sw_r 06;

Io::Io(int _pin, bool _logic):
pin(_pin),
logic(_logic)
{
	if(wiringPiSetupGpio() != 0){
		printf("failed to open GPIO\n");
	}
	else{
		pinMode(pin, INPUT);
		pullUpDnControl(pin, PUD_UP);
		printf("GPIO %d opened\n", pin);
	}
}

bool Io::getSw(){
	int value = digitalRead(pin);
	return (bool)value == logic;
}
