/**
 * @file straw.cpp
 * @brief ストロー機構
 * @author 岡部
 * @date 2020/11/11
 */

#include "straw.hpp"
#include <stdio.h>

Straw::Straw():
actuate_count(20),
count(0)
{}

void Straw::update(){
    count++;
    bool pylo = hand.isExistHand();
    printf("%d\n", (int)pylo);

    if(pylo && count > actuate_count){
        count = 0;
        spray.pushBottle();
    }
}