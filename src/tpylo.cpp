/**
 * @file tpylo.cpp
 * @brief 全体プログラム
 * @author 岡部
 * @date 2020/11/11
 */

#include <stdio.h>
#include <unistd.h>

#include "arduino.h"
#include "move.hpp"
#include "straw.hpp"


int main(){
	Move mover;
	Straw straw;

	if(arduino_open() != 0) return -1;
	printf("press enter to start\n");
	getchar();

	while(true){
		// 処理を記述
		mover.go();
		//straw.update();
		usleep(50000);
	}
	return 0;
}
