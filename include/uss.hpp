/**
 * @file uss.hpp
 * @brief 超音波センサモジュール
 * @author 岡部
 * @date 2020/11/11
 */

#ifndef __USS__
#define __USS__

/**
 * @brief 距離検出クラス
 * @details 超音波センサからの値を読み取り、距離を計算する
 */
class Uss(){
public:
    /**
     * @brief Ioクラスに超音波センサのピン番号を渡す
     */
    Uss(int address);
    /**
     * @brief 距離が近づいているかを検出する関数
     * @return long 4byteまで読み取れる
     */
    long getUss();


private:
    //! 測定の時間間隔[ms]
    const int t_uss = 50;

    //! 測定範囲の下限・上限[cm]
    const int uss_min =  16;
    const int uss_max = 600;

    //! センサからMIRS中心までの距離[cm]
    const int dist_center = 10;

    int fd;

};


#endif
