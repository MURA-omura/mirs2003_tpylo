/**
 * @file spray.cpp
 * @brief スプレー噴射モジュール
 * @author 岡部
 * @date 2020/11/11
 */

#include "spray.hpp"
#include "hand.hpp"
#include <stdio.h>
#include "request.h"

Spray::Spray():
spray_morter(360),
gear_rate(1.0f)
{
    return;
}

void Spray::pushBottle(){
    request_set_spray();
}