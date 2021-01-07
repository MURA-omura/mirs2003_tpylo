/**
 * @file ussmgr.hpp
 * @brief 超音波センサ管理モジュール
 * @author 村尾
 * @date 2021/1/6
 */

#ifndef __USSMGR__
#define __USSMGR__

#include <array>
#include "uss.hpp"
#include "move.hpp"
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
 * @brief 超音波センサ管理クラス
 */
class UssMgr{
public:
    UssMgr();
    void searchUss(run_state_t *run_state, run_t *next_state, int *run_param);

private:
    //! 超音波の値を格納する配列
    std::array<Uss, USS_NUM> uss_array;
};

#endif