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
		//„‰ñ
		request_set_runmode(STR,25,100);
		//áŠQ•¨‚ğŒŸ’m‚µ‚½Œã‰ñ“]‚·‚é
		dist_l = uss_l;
		dist_r = uss_r;

		if(dist_l < 30 ; dist_r < 30){
			request_set_runmode(STP, 0, 0);
			request_set_runmode(ROT, 45, 90);
			while(1){
				request_get_runmode(&state, &speed, &dist);
				if( state == STP ) break;
			}
		}

}