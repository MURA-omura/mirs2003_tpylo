/**
 * @file move.hpp
 * @brief 走行モジュール
 * @author 岡部
 * @date 2020/11/05
 */

#ifndef __MOVE__
#define __MOVE__

#include <array>
//#include <vector>
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
    TURN,
    CURVE,
    STOP,
    SPRAY,
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
    //int getState() { return next_state; }


private:
    //! 超音波の値を格納する配列
    //std::vector<Uss> uss_array;
    std::array<Uss, USS_NUM> uss_array;
    //! タッチセンサ左
    Io ts_l;
    //! タッチセンサ右
    Io ts_r;
    //! 走行状態
    run_t next_state;
    run_state_t run_state;
    // 走行用パラメータ
    int run_param;

    /**
     * @brief 状態をセットする関数
     * @details 超音波の値を読み取り、その値によって状態を変化させる
     * @return 走行状態
     */
    void setState();
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
    void turning(int deg);

    /**
     * @brief 曲がる関数
     * @details 曲がる関数をmove.cppに渡す
     */
    void curve(int adjust);

    /**
     * @brief 止まる関数
     */
    void stop();

    /**
     * @brief 噴射するために一時停止する関数
     */
    void spray();

};

#endif