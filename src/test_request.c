#include <stdio.h>
#include "number.h"
#include "arduino.h"
#include "request.h"
int main(){
	
	int i;
	int ans[NUM_LEN];
	char buf[256];
	int num1,num2,num3,num4;
	
	int dista=90;
	
	int mode, speed, dist;
	double volt;
	//char buf[256];
	run_state_t state;
	
	if(arduino_open() != 0) return -1;


	while(1){
		dista=90;
		printf("0:stop  1:number50  2:number100  3:get_volt  4:quit \n");
		scanf("%d",&mode);
		
		switch(mode){
		case 0:
			request_set_runmode(STP, 0, 0);
			break;
		case 1:
			number_detect(50);
			number_get(ans);

			for(i = 0; i < NUM_LEN; i++){
					printf("number[%d] = %d\n", i, ans[i]);
			}
			num1=ans[0];
			printf("num1=%d\n",num1);
	
			request_set_runmode(ROT, 30, 90);
			while(1){
				request_get_runmode(&state, &speed, &dist);
				if( state == STP ) break;
			}

	
			number_detect(100);
			number_get(ans);

			for(i = 0; i < NUM_LEN; i++){
				printf("number[%d] = %d\n", i, ans[i]);
			}
			num2=ans[0];
			if (num1<num2) {
				dista=180;
				num1=num2;
			}
			
			
			request_set_runmode(ROT, 30, 90);
			while(1){
				request_get_runmode(&state, &speed, &dist);
				if( state == STP ) break;
			}
	
			number_detect(50);
			number_get(ans);

			for(i = 0; i < NUM_LEN; i++){
				printf("number[%d] = %d\n", i, ans[i]);
					}
			num2=ans[0];
			if (num1<num2) {
				dista=270;
				num1=num2;
			}
			

			request_set_runmode(ROT, 30, 90);
			while(1){
				request_get_runmode(&state, &speed, &dist);
				if( state == STP ) break;
			}
			number_detect(100);
			number_get(ans);

			for(i = 0; i < NUM_LEN; i++){
				printf("number[%d] = %d\n", i, ans[i]);
			}
			num2=ans[0];
			if (num1<num2) {
				dista=0;
			}

			request_set_runmode(ROT, 30, dista);
			while(1){
				request_get_runmode(&state, &speed, &dist);
				if( state == STP ) break;
			}
			break;
		case 2:
			number_detect(100);
			number_get(ans);

			for(i = 0; i < NUM_LEN; i++){
					printf("number[%d] = %d\n", i, ans[i]);
			}
			num1=ans[0];
			printf("num1=%d\n",num1);
	
			request_set_runmode(ROT, 30, 90);
			while(1){
				request_get_runmode(&state, &speed, &dist);
				if( state == STP ) break;
			}

	
			number_detect(50);
			number_get(ans);

			for(i = 0; i < NUM_LEN; i++){
				printf("number[%d] = %d\n", i, ans[i]);
			}
			num2=ans[0];
			if (num1<num2) {
				dista=180;
				num1=num2;
			}
			
			
			request_set_runmode(ROT, 30, 90);
			while(1){
				request_get_runmode(&state, &speed, &dist);
				if( state == STP ) break;
			}
	
			number_detect(100);
			number_get(ans);

			for(i = 0; i < NUM_LEN; i++){
				printf("number[%d] = %d\n", i, ans[i]);
					}
			num2=ans[0];
			if (num1<num2) {
				dista=270;
				num1=num2;
			}
			

			request_set_runmode(ROT, 30, 90);
			while(1){
				request_get_runmode(&state, &speed, &dist);
				if( state == STP ) break;
			}
			number_detect(50);
			number_get(ans);

			for(i = 0; i < NUM_LEN; i++){
				printf("number[%d] = %d\n", i, ans[i]);
			}
			num2=ans[0];
			if (num1<num2) {
				dista=0;
			}

			request_set_runmode(ROT, 30, dista);
			while(1){
				request_get_runmode(&state, &speed, &dist);
				if( state == STP ) break;
			}
			break;
		case 3:
			request_get_batt(&volt);
			printf("batt = %4.2lf\n", volt);
			break;
		case 4:
			return 0;
		
		default:
			break;
		}
	}
	
	arduino_close();
	return 0;
}
