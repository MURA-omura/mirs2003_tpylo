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
#include "move.hpp"
#include "straw.hpp"
#include "sock.h"


int main(){
	Move mover;
	Straw straw;

	pthread_t thread;
	pthread_create(&thread, NULL,  (void *(*)(void *))&connectPython, &mover);
	pthread_detach(thread);

	if(arduino_open() != 0) return -1;
	puts("Tpylo Start!");
	sleep(1);

	while(true){
		mover.go();
		if(G_state == run_t::SPRAY){
			straw.update();
			printf("G_dist: %d", G_dist);
			if(G_dist < 60) mover.resume();
		}
		usleep(1000);
	}
	return 0;
}
