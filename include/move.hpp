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

/**
 * @brief 走行クラス
 */
class Move{
public:
    /**
     * @brief Ioクラスにモータのピン番号を渡す
    */
    Move();

private:
    // 超音波の値を格納する配列
    std::array<Uss, uss_t::USS_NUM> uss_array;
};

#endif