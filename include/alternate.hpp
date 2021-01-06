/**
 * @file alternate.hpp
 * @brief モメンタリ-オルタネイト変換モジュール
 * @author 村尾
 * @date 2021/1/6
 */

#ifndef __Alternate__
#define __Alternate__

#include "io.hpp"

/**
 * @brief モメンタリ-オルタネイトクラス
 * @details GPIOピンの値を読み取り、押されていたら状態を反転する
 */
class Alternate{
public:
    /**
     * @brief ioクラスにピン番号を渡す
     */
    Alternate(int pin, bool logic);
    /**
     * @brief スイッチの状態を検出する関数
     * @return bool 正論理の時HIGHならtrue、負論理なら逆
     */
    bool getSw();


private:
    // GPIO
    Io sw;
    // オルタネイト変換したときの状態
    bool flag;
    // 現在のGPIOピンの状態
    bool state;
    // 1つ前のGPIOピンの状態
    bool before;
};

#endif
