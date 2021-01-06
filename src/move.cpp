/**
 * @file move.cpp
 * @brief 走行モジュール
 * @author 岡部
 * @date 2020/11/11
 */


#include "move.hpp"
#include <stdio.h>
#include "request.h"
#inlcude "sock.h"


Move::Move():
ts_l(4, false),
ts_r(8, false),
uss_array{{{0x72, 60}, {0x71, 60}, {0x75, 60}, {0x76, 50}, {0x74, 40}, {0x70, 35}, {0x73, 40}, {0x77, 35}}}
{
	next_state = STOP;
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
		case SPRAY:
			break;
		default:
			break;
		}
	}

	if(next_state == STRAIGHT){
		setState();
	}

	run_state_t run;
	int sp, ds;
	request_get_runmode(&run, &sp, &ds);
	printf("%d,  %d,  %d\n", run, sp, ds);

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
		case SPRAY:
			spray();
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
	else if(G_power != 0){
		// 左にカーブ
		run_state = STP;
		next_state = CURVE;
		run_param = G_power;
		printf("human %d\n", run_param);
		G_power = 0;
	}

	if(G_dist > 10){
		run_state = STP;
		next_state = SPRAY;
		run_param = 0;
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
	G_state = 1;
	request_set_runmode(STR, 30, 150);
}

void Move::back(){
	G_state = 2;
	request_set_runmode(STR, -10, -5);
}

void Move::turning(int deg){
	G_state = 3;
	request_set_runmode(ROT, deg > 0 ? 90 : -90, deg);
}

void Move::curve(int adjust){
	G_state = 4;
	request_set_runmode(CRV, 30, adjust);
}

void Move::stop(){
	G_state = 0;
	request_set_runmode(STP, 0, 0);
}

void Move::spray(){
	G_state = 5;
	request_set_runmode(STP, 0, 0);
}
