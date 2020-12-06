/**
 * @file move.hpp
 * @brief 走行モジュール
 * @author 岡部
 * @date 2020/11/05
 */

#ifndef __MOVE__
#define __MOVE__

#include <array>
#include "io.hpp"
#include "uss.hpp"
#include "request.h"

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
 * @brief 走行状態
 */
typedef enum{
    STRAIGHT,
    BACK,
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

    /**
     * @brief 走行関数
     * @details 走行状態をもとにプライベートな走行関数を呼ぶ
     */
    void go();

    /**
     * @brief 走行状態取得関数
     */
    //int getState() { return state; }

    /**
     * @brief Pythonパラメータセット関数
     * @details
     */
    void setCamera(int power, int dist);

private:
    //! 超音波の値を格納する配列
    std::array<Uss, uss_t::USS_NUM> uss_array;
    //! タッチセンサ左
    Io ts_l;
    //! タッチセンサ右
    //Io ts_r;
    //! 走行状態
    run_t next_state;
    run_state_t run_state;
    //int state;

    /**
     * @brief 状態をセットする関数
     * @details 超音波の値を読み取り、その値によって状態を変化させる
     * @return 走行状態
     */
    run_t setState();
    /**
     * @brief 直進状態の関数(通常状態)
     * @details 直進する関数をmove.cppに渡す
     */
    void straight();

    /**
     * @brief 後退状態の関数
     * @details 後退する関数をmove.cppに渡す
     */
    void back();

    /**
     * @brief 障害物回避の関数
     * @details 90度回転する関数をmove.cppに渡す
     */
    void turning();

    /**
     * @brief 曲がる関数
     * @details 曲がる関数をmove.cppに渡す
     */
    void curve();

    /**
     * @brief 止まる関数
     */
    void stop();

};

#endif