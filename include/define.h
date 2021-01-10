/**
 * @file define.h
 * @brief 定義ヘッダ
 * @author 村尾
 * @date 2021/1/8
 */

#ifndef __MOVE__
#define __MOVE__

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

#endif
