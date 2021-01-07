#include <cstdio>
#include <unistd.h>
#include "alternate.hpp"
#include "io.hpp"

int main(){
    Alternate sw_pw(7, false);
    Io ts_l(4, false);
    Io ts_r(8, false);
	Io sw_ad(6, false);

	while(1){
		printf("pw:%d,  ", (int)sw_pw.getSw());
		printf("tl:%d,  ", (int)ts_l.getSw());
		printf("tr:%d,  ", (int)ts_r.getSw());
		printf("ad:%d\n", (int)sw_ad.getSw());
		usleep(50000);
	}
	return 0;
}
