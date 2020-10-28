#ifndef __USS__
#define __USS__

class Uss(){
public:
    Uss(int address);
    long getUss();


private:
    // 測定の時間間隔[ms]
    const int t_uss = 50;

    // 測定範囲の下限・上限[cm]
    const int uss_min =  16;
    const int uss_max = 600;

    // センサからMIRS中心までの距離[cm]
    const int dist_center = 10;

    int fd;

};


#endif
