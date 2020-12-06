/**
 * @file socket.hpp
 * @brief socketモジュール
 * @author 村尾
 * @date 2020/12/6
 */

#ifndef __SOCK__
#define __SOCK__

#include "move.hpp"

/**
 * @brief bit-int変換関数
 * @details char型で受け取った値をint型に変換する
 */
void convertNum(char *buf, int *power, int *dist);
/**
 * @brief 通信関数
 * @details Pythonプログラムとソケット通信をする
 */
void connectPython(Move mover);

#endif
