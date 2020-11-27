/**
 * @file move.cpp
 * @brief 走行モジュール
 * @author 岡部
 * @date 2020/11/11
 */


#include "move.hpp"
#include <stdio.h>
#include "request.h"


//ts_r(8, true),
Move::Move():
ts_l(4, false),
uss_array{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
{
	run_state = STRAIGHT;
}

void Move::go(){
	switch(run_state){
	case STRAIGHT:
		straight();
		break;
	case TURNING:
		turning();
		break;
	case CURVE:
		curve();
		break;
	case STOP:
		stop();
		break;
	default:
		break;
	}

	while(1){
		bool flag = ts_l.getSw();
		printf("%d\n", (int)flag);
		if(flag){
			stop();
		}

		run_state_t state;
		int speed, dist;
		request_get_runmode(&state, &speed, &dist);
		if( state == STP ) break;
	}

	turning();
	while(1){
		run_state_t state;
		int speed, dist;
		request_get_runmode(&state, &speed, &dist);
		if( state == STP ) break;
	}
}

void Move::straight(){
	request_set_runmode(STR, 30, 150);
}

void Move::turning(){
	request_set_runmode(ROT, 60, 180);
}

void Move::curve(){
	request_set_runmode(ROT, 0, 0);
}

void Move::stop(){
	request_set_runmode(STP, 0, 0);
	exit(0);
}
