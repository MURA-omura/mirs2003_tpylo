/**
 * @file ucc.cpp
 * @brief 距離検出プログラム
 * @author 岡部
 * @date 2020/11/11
 */

#include "uss.hpp"
#include <stdio.h>
#include <unistd.h>
#include <wiringPiI2C.h>


Uss::Uss(int address):
t_uss(50),
uss_min(16),
uss_max(600),
dist_center(10),
{
	fd = wiringPiI2CSetup(address);

	// ソフトウェアリビジョンの確認
	if(wiringPiI2CReadReg8(fd, 0x00) == 0x06){
		printf("%x opened\n",address);
		return 0;
	}else{
		printf("failed to open %x\n",address);
		return -1;
	}
}


long Uss::getUss(){
	unsigned char lowbyte, highbyte;
	long val;

	wiringPiI2CWriteReg8(fd, 0x00, 0x51);
	usleep(t_uss * 1000);

	lowbyte  = wiringPiI2CReadReg8(fd, 0x03);
	highbyte = wiringPiI2CReadReg8(fd, 0x02);
	val = lowbyte + highbyte * 256;

	if(val < uss_min || val > uss_max){
		return -1;
	}else{
		return val + dist_center;
	}
}

