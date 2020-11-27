/**
 * @file tpylo.cpp
 * @brief 全体プログラム
 * @author 岡部
 * @date 2020/11/11
 */

#include <stdio.h>
#include "arduino.h"

#include "move.hpp"
#include "straw.hpp"


int main(){
	Move mover;

	if(arduino_open() != 0) return -1;
	printf("press enter to start\n");
	getchar();

	while(true){
		// 処理を記述
		mover.go();
		//break;
	}
	return 0;
}
