/**
 * @file io.hpp
 * @brief GPIOモジュール
 * @author 岡部
 * @date 2020/11/11
 */

#ifndef __IO__
#define __IO__

/**
 * @brief GPIOクラス
 * @details GPIOピンの値を読み取り、押されていたら1、押されていなかったら0を返す
 */
class Io{
public:
    /**
     * @brief ioクラスにピン番号を渡す
     */
    Io(int _pin, bool _logic);
    /**
     * @brief スイッチの状態を検出する関数
     * @return bool 正論理の時HIGHならtrue、負論理なら逆
     */
    bool getSw();


private:
    //! ピン番号
    const int pin;

    //! 正論理か不論理かを検出する関数　(true 正論理、fals 不論理)
    bool logic;
};

#endif
