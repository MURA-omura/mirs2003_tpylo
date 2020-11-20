/**
 * @file io.hpp
 * @brief タッチセンサ検出モジュール
 * @author 岡部
 * @date 2020/11/11
 */

#ifndef __IO__
#define __IO__

/**
 * @brief タッチセンサ検出クラス
 * @details タッチセンサからの値を読み取り、押されていたら1、押されていなかったら0を返す
 */
class Io{
public:
    /**
     * @brief ioクラスにタッチセンサのピン番号を渡す
     */
    Io(int pin);
    /**
     * @brief スイッチの状態を検出する関数
     * @return bool スイッチが押されていたらtrue
     */
    bool getSw();


private:
    //! タッチセンサのピン番号
    int pin;

    //! 正論理か不論理かを検出する関数　(true 正論理、fals 不論理)
    bool logic;
};

#endif
