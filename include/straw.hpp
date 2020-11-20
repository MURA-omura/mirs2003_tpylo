/**
 * @file straw.hpp
 * @brief ストロー部分のモジュール
 * @author 岡部
 * @date 2020/11/11
 */

#ifndef __STRAW__
#define __STRAW__

#include "hand.hpp"
#include "spray.hpp"

/**
 * @brief モータ動作クラス
 * @details hand.cppの値を読み取り、trueが返ってきたときにモータを動作する
 */
class Straw{
public:
    /**
     * @brief Ioクラスにモータのピン番号を渡す
     */
    Straw();

    /**
     * @brief ストロー機構を動作させる
     */
    void update();

private:
    // モータを作動させる最小カウント数
    const int actuate_count;
    int count;
    Hand hand;
    Spray spray;
};

#endif
