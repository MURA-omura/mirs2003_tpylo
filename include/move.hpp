/**
 * @file move.hpp
 * @brief 走行モジュール
 * @author 岡部
 * @date 2020/11/05
 */

#ifndef __MOVE__
#define __MOVE__

#include <array>
#include "uss.hpp"

/**
 * @brief 超音波の場所の列挙
 */
typedef enum{
	FRONT_L,
	FRONT_R,
    FRONT_U,
    FRONT_D,
    LEFT_U,
    LEFT_D,
    RIGHT_U,
    RIGHT_D,
	USS_NUM
} uss_t;

typedef enum{
    STRAIGHT,
    TURNING,
    CURVE,
    STOP,
    RUN_NUM
} run_t;

/**
 * @brief 走行クラス
 */
class Move{
public:
    Move();
    void go();

private:
    // 超音波の値を格納する配列
    std::array<Uss, uss_t::USS_NUM> uss_array;

    /**
     * @brief 直進状態の関数(通常状態)
     * @details 直進する関数をmove.cppに渡す
     */
     void Straight();

    /**
     * @brief 障害物回避の関数
     * @details 90度回転する関数をmove.cppに渡す
     */
    void Turning();

    /**
     * @brief 曲がる関数
     * @details 曲がる関数をmove.cppに渡す
     */
    void Curve();

    /**
     * @brief 止まる関数
     */
    void Stop();

};

#endif