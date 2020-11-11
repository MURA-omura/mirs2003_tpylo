/**
 * @file tpylo.cpp
 * @brief 全体プログラム
 * @author 岡部
 * @date 2020/11/11
 */

#include <stdio.h>
#include <unistd.h>
#include "arduino.h"
#include "request.h"

#include "arcohol.hpp"
#include "move.hpp"
#include "straw.hpp"

/*
int main(){
	double volt;
	
	if(io_open() != 0) return -1;
	if(arduino_open() != 0) return -1;
	if(uss_open_l() != 0) return -1;
	if(uss_open_r() != 0) return -1;
	
	printf("press enter to start\n");
	getchar();
	
	while(1){
		// 処理を記述
		request_set_runmode(STR, 25, 100);
		break;
	}
	
	arduino_close();
	return 0;
}
*/

int main(){
	while(true){
		// 処理を記述
	}
	return 0;
}