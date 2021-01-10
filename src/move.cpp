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


Move::Move():
sw_pw(7, false),
ts_l(4, false),
ts_r(8, false),
sw_ad(6, false),
uss_count(0)
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

	uss_count++;
	if(next_state == STRAIGHT && uss_count % 3 == 0){
		int nstate;
		ussMgr.searchUss(&run_state, &nstate, &run_param);
		next_state = (run_t)nstate;
	}
	if(G_dist > 80){
		run_state = STP;
		next_state = SPRAY;
		run_param = 0;
	}

	if(ts_l.getSw() || ts_r.getSw()){
		// 衝突していたら強制的に後ろに下げる
		run_state = STP;
		next_state = BACK;
		if(ts_l.getSw()) run_param = -135;
		else run_param = 135;
	}

	run_state_t run;
	int sp, ds;
	request_get_runmode(&run, &sp, &ds);
	//printf("%d,  %d,  %d\n", run, sp, ds);

	G_audio = (int)sw_ad.getSw();
	if(!sw_pw.getSw()) {
		run_state = STP;
		next_state = STOP;
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
		case SPRAY:
			spray();
			break;
		default:
			break;
		}
	}
}


void Move::resume(){
	next_state = STRAIGHT;
	G_state = 1;
}


void Move::straight(){
	G_state = 1;
	request_set_runmode(STR, 20, 150);
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
	request_set_runmode(CRV, 20, adjust);
}

void Move::stop(){
	G_state = 0;
	request_set_runmode(STP, 0, 0);
}

void Move::spray(){
	G_state = 5;
	request_set_runmode(STP, 0, 0);
}
