#include <stdio.h>
#include <unistd.h>
#include "io.hpp"

int main(){
	Io gpios[] = {
		Io(4, false),
		Io(8, false)
	};

	while(1){
		for(int i = 0; i < (int)gpios.size(); i++){
			printf("switch%d: %d,  ", (int)i, (int)gpios[i].getSw());
		}
		printf("\n");
		usleep(100 * 1000);
	}

	return 0;
}
