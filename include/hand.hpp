/**
 * @file hand.hpp
 * @brief 手検出モジュール
 * @author 村尾
 * @date 2020/11/28
 */

#ifndef __HAND__
#define __HAND__

#include "io.hpp"

/**
 * @brief 手検出クラス
 * @details 焦電センサからの値をIOクラスから読み取り、LOW(負論理)が出力されたときにtrueを返す
 */
class Hand()
{
public:
    /**
     * @brief Ioクラスに焦電センサのピン番号を渡す
     */
    Hand();
    /**
     * @brief 手がかざされているかを検出する関数
     * @return bool 手がかざされていたらtrue
     */
    bool isExistHand();

private:
    //! 焦電センサのピン番号
    static const int pyro_pin = -1;
    //! 焦電センサから値を読み取るインスタンス
    Io pyro;
};

#endif
