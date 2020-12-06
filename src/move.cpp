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


//ts_r(8, true),
Move::Move():
ts_l(4, false),
uss_array{0x72, 0x71, 0x75, 0x76, 0x74, 0x70, 0x73, 0x77}
{
	run_state = STOP;
}

void Move::setCamera(int power, int dist){
	return;
}

void Move::go(){
	run_state_t state;
	int speed, dist;
	request_get_runmode(&state, &speed, &dist);
	if(state == STP) {
		switch(run_state){
		case STRAIGHT:
			run_state = TURNING;
			break;
		case BACK:
			run_state = TURNING;
			break;
		case TURNING:
			run_state = STRAIGHT;
			break;
		case CURVE:
			run_state = STRAIGHT;
			break;
		case STOP:
			run_state = STRAIGHT;
			break;
		default:
			break;
		}
	}

	if(run_state == STRAIGHT){
		for(Uss u : uss_array){
			long val = u.getUss();
			printf("%ld  ", val);
			if(val > 0 && val < 50){
				state = STP;
				run_state = TURNING;
			}
		}
		puts("");
	}

	if (state == STP){
		switch(run_state){
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
	puts("straight\n");
	request_set_runmode(STR, 40, 150);
}

void Move::back(){
	puts("back\n");
	request_set_runmode(STR, -10, -5);
}

void Move::turning(){
	puts("turning\n");
	request_set_runmode(ROT, 90, 180);
}

void Move::curve(){
	request_set_runmode(ROT, 0, 0);
}

void Move::stop(){
	request_set_runmode(STP, 0, 0);
}
