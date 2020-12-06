/**
 * @file move.cpp
 * @brief 走行モジュール
 * @author 岡部
 * @date 2020/11/11
 */


#include "move.hpp"
#include <stdio.h>
#include "request.h"
#include "sock.h"


extern int state;


//ts_r(8, true),
Move::Move():
ts_l(4, false),
uss_array{0x72, 0x71, 0x75, 0x76, 0x74, 0x70, 0x73, 0x77}
{
	next_state = STOP;
	state = 0;
}


void Move::setCamera(int power, int dist){
	return;
}


void Move::go(){
	int speed, dist;
	request_get_runmode(&run_state, &speed, &dist);
	if(run_state == STP) {
		switch(next_state){
		case STRAIGHT:
			next_state = TURNING;
			break;
		case BACK:
			next_state = TURNING;
			break;
		case TURNING:
			next_state = STRAIGHT;
			break;
		case CURVE:
			next_state = STRAIGHT;
			break;
		case STOP:
			next_state = STRAIGHT;
			break;
		default:
			break;
		}
	}

	if(next_state == STRAIGHT){
		for(Uss u : uss_array){
			long val = u.getUss();
			printf("%ld  ", val);
			if(val > 0 && val < 50){
				run_state = STP;
				next_state = TURNING;
			}
		}
		puts("");
	}

	if (run_state == STP){
		switch(next_state){
		case STRAIGHT:
			straight();
			break;
		case BACK:
			back();
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
	}
}

void Move::straight(){
	state = 1;
	request_set_runmode(STR, 40, 150);
}

void Move::back(){
	state = 2;
	request_set_runmode(STR, -10, -5);
}

void Move::turning(){
	state = 3;
	request_set_runmode(ROT, 90, 180);
}

void Move::curve(){
	state = 4;
	request_set_runmode(ROT, 0, 0);
}

void Move::stop(){
	state = 0;
	request_set_runmode(STP, 0, 0);
}
