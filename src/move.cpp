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


Move::Move():
ts_l(4, false),
ts_r(8, false),
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
			//next_state = STRAIGHT;
			break;
		case BACK:
			next_state = TURN;
			break;
		case TURN:
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
		setState();
	}

	if (run_state == STP){
		switch(next_state){
		case STRAIGHT:
			straight();
			break;
		case BACK:
			back();
			break;
		case TURN:
			turning(run_param);
			break;
		case CURVE:
			curve(run_param);
			break;
		case STOP:
			stop();
			break;
		default:
			break;
		}
	}
}


void Move::setState(){
	bool uss_flag[USS_NUM];
	for(int i = 0; i < USS_NUM; i++){
		uss_flag[i] = uss_array[i].isObstacle();
		printf("%d  ", (int)uss_flag[i]);
	}
	puts("");

	if((uss_flag[FRONT_L] && uss_flag[FRONT_R]) || uss_flag[FRONT_U] || uss_flag[FRONT_D]){
		// 135度旋回
		run_state = STP;
		next_state = TURN;
		if(uss_flag[FRONT_L] < uss_flag[FRONT_R]) run_param = 135;
		else run_param = -135;
	}
	else if(uss_flag[FRONT_L]){
		// 右に45度旋回
		run_state = STP;
		next_state = TURN;
		run_param = 45;
	}
	else if(uss_flag[FRONT_R]){
		// 左に45度旋回
		run_state = STP;
		next_state = TURN;
		run_param = -45;
	}
	else if(uss_flag[LEFT_U] || uss_flag[LEFT_D]){
		// 右にカーブ
		run_state = STP;
		next_state = CURVE;
		run_param = -5;
	}
	else if(uss_flag[RIGHT_U] || uss_flag[RIGHT_D]){
		// 左にカーブ
		run_state = STP;
		next_state = CURVE;
		run_param = 5;
	}

	if(ts_l.getSw() || ts_r.getSw()){
		// 衝突していたら強制的に後ろに下げる
		run_state = STP;
		next_state = BACK;
		if(ts_l.getSw()) run_param = 135;
		else run_param = -135;
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

void Move::turning(int deg){
	state = 3;
	request_set_runmode(ROT, deg > 0 ? 90 : -90, deg);
}

void Move::curve(int adjust){
	state = 4;
	request_set_runmode(CRV, 40, adjust);
}

void Move::stop(){
	state = 0;
	request_set_runmode(STP, 0, 0);
}
