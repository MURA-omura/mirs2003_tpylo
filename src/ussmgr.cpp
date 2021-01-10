/**
 * @file ussmgr.cpp
 * @brief 超音波センサ管理モジュール
 * @author 村尾
 * @date 2021/1/6
 */

#include "ussmgr.hpp"
#include <stdio.h>
#include "sock.h"

UssMgr::UssMgr():
uss_array{{{0x72, 60}, {0x71, 60}, {0x75, 60}, {0x76, 50}, {0x74, 40}, {0x70, 35}, {0x73, 40}, {0x77, 35}}}
{}

void UssMgr::searchUss(run_state_t *run_state, int *next_state, int *run_param){
    bool uss_flag[USS_NUM];
	for(int i = 0; i < USS_NUM; i++){
		uss_flag[i] = uss_array[i].isObstacle();
		//printf("%d  ", (int)uss_flag[i]);
	}
	//puts("");

	if((uss_flag[LEFT_U] || uss_flag[LEFT_D]) && (uss_flag[RIGHT_U] || uss_flag[RIGHT_D])){
		*run_state = STP;
		*next_state = TURN;
		*run_param = 180;
	}
	else if((uss_flag[FRONT_L] && uss_flag[FRONT_R]) || uss_flag[FRONT_U] || uss_flag[FRONT_D]){
		// 135度旋回
		*run_state = STP;
		*next_state = TURN;
		if(uss_flag[FRONT_L] < uss_flag[FRONT_R]) *run_param = -135;
		else *run_param = 135;
	}
	else if(uss_flag[FRONT_L]){
		// 右に45度旋回
		*run_state = STP;
		*next_state = TURN;
		*run_param = -45;
	}
	else if(uss_flag[FRONT_R]){
		// 左に45度旋回
		*run_state = STP;
		*next_state = TURN;
		*run_param = 45;
	}
	else if(uss_flag[LEFT_U] || uss_flag[LEFT_D]){
		// 右にカーブsudo reboot
		*run_state = STP;
		*next_state = CURVE;
		*run_param = -5;
	}
	else if(uss_flag[RIGHT_U] || uss_flag[RIGHT_D]){
		// 左にカーブ
		*run_state = STP;
		*next_state = CURVE;
		*run_param = 5;
	}
	else if((G_power > 5 || G_power < -5) && G_dist > 60){
		// 左にカーブ
		*run_state = STP;
		*next_state = CURVE;
		*run_param = G_power;
		//printf("human %d\n", *run_param);
		G_power = 0;
	}
}