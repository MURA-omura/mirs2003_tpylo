/**
 * @file hand.cpp
 * @brief 手検出モジュール
 * @author 岡部
 * @date 2020/11/11
 */

#include "hand.hpp"


Hand::Hand():
pyro_pin(15),
pyro(pyro_pin, false)
{
    std::fill(pyro_array.begin(), pyro_array.end(), false);
}


bool Hand::isExistHand(){
    // 配列の値を1つずつずらす
    for(size_t i = 1; i < pyro_array.size(); i++){
        pyro_array[i] = pyro_array[i-1];
    }
    pyro_array[0] = pyro.getSw() == 1;

    // 配列のtrueの数を数える
    int flag_counter = 0;
    for(bool pr : pyro_array){
        if(pr) flag_counter++;
    }

    return flag_counter == array_size;
}
