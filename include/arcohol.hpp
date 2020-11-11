/**
 * @file arcohol.hpp
 * @brief アルコール残量検出モジュール
 * @author 岡部
 * @date 2020/11/11
 */

#ifndef __ARCOHOL__
#define __ARCOHOL__

/**
 * @brief アルコール残量検出クラス
 * @details センサからの値を読み取り、0になったら
 */
class Arcohol{
public:
    /**
     * @brief クラスにセンサのピン番号を渡す
     */
    Arcohol();
    /**
     * @brief アルコールが残っているか検出する関数
     */
    int getSensor();

private:
};

#endif
