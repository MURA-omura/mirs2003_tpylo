/**
 * @file hand.cpp
 * @brief 手検出モジュール
 * @author 岡部
 * @date 2020/11/11
 */

#include "hand.hpp"


Hand::Hand(): pyro(pyro_pin){

}


bool Hand::isExistHand(){
    int sensor = pyro.getSw();
    return sensor == 1;

}
