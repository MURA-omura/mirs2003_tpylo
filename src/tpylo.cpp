/**
 * @file tpylo.cpp
 * @brief 全体プログラム
 * @author 岡部
 * @date 2020/11/11
 */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#include "arduino.h"
#include "io.hpp"
#include "move.hpp"
#include "straw.hpp"
#include "sock.h"


int main(){
	bool sw_state = false, sw_before = false, sw_flag = false;
	Io sw_pw(7, false);
	Io sw_ad(6, false);
	Move mover;
	Straw straw;

	G_state = 0;
	G_power = 0;
	G_audio = 0;

	pthread_t thread;
	pthread_create(&thread, NULL,  (void *(*)(void *))&connectPython, &mover);
	pthread_detach(thread);

	if(arduino_open() != 0) return -1;
	puts("Tpylo Start!");

	while(true){
		sw_before = sw_state;
		bool sw_state = sw_pw.getSw();
		G_audio = (int)sw_ad.getSw();
		if(sw_state && !sw_before) sw_flag = !sw_flag;

		if(sw_flag){
			if(G_state < run_t::SPRAY){
				mover.go();
			}
			else{
				straw.update();
			}
		}
		usleep(50000);
	}
	return 0;
}
