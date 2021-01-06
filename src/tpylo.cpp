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
	Move mover;
	Straw straw;

	G_state = 0;
	G_power = 0;
	G_audio = 0;
	G_dist = 0;

	pthread_t thread;
	pthread_create(&thread, NULL,  (void *(*)(void *))&connectPython, &mover);
	pthread_detach(thread);

	if(arduino_open() != 0) return -1;
	puts("Tpylo Start!");

	while(true){
		mover.go();
		if(G_state == run_t::SPRAY){
			straw.update();
			if(G_dist < 10) mover.resume();
		}
		usleep(50000);
	}
	return 0;
}
