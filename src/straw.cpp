/**
 * @file straw.cpp
 * @brief ストロー機構
 * @author 岡部
 * @date 2020/11/11
 */

#include "straw.hpp"
#include <stdio.h>

Straw::Straw(){

}

void Straw::update(){
    count++;
    bool pylo = hand.isExistHand();
    if(pylo && count > actuate_count){
        count = 0;
        spray.pushBottle();
    }
}