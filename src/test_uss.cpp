#include <array>
#include <cstdio>
#include <unistd.h>
#include "uss.hpp"

int main(){
	const int USS_NUM = 8;
	std::array<Uss, USS_NUM> uss_array{{{0x72, 60}, {0x71, 60}, {0x75, 60}, {0x76, 50}, {0x74, 40}, {0x70, 35}, {0x73, 40}, {0x77, 35}}};
	while(true){
		for(Uss uss : uss_array) printf("%d  ", (int)uss.isObstacle());
		puts("");
		usleep(50000);
	}
	return 0;
}
