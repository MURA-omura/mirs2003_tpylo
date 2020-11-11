/**
 * @file move.cpp
 * @brief 走行モジュール
 * @author 岡部
 * @date 2020/11/11
 */


#include "move.hpp"


Move::Move():
uss_array{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
{

}


/*
#include <stdio.h>
#include <unistd.h>
#include "arduino.h"
#include "direction.h"
#include "io.h"
#include "request.h"
#include "uss.h"

int main(){
	double volt,dist_l,dist_r;

	if(io_open() != 0) return -1;
	if(arduino_open() != 0) return -1;
	if(direction_open() != 0) return -1;
	if(uss_open_l() != 0) return -1;
	if(uss_open_r() != 0) return -1;

	while(1){
		//巡回
		request_set_runmode(STR,25,100);
		//障害物を検知した後回転する
		dist_l = uss;
		dist_r = uss;

		if(dist_l < 30 ; dist_r < 30){
			request_set_runmode(STP, 0, 0);
			request_set_runmode(ROT, 45, 90);
			while(1){
				request_get_runmode(&state, &speed, &dist);
				if( state == STP ) break;
			}
		}

}
*/