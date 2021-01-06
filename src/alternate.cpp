/**
 * @file alternate.hpp
 * @brief モメンタリ-オルタネイト変換モジュール
 * @author 村尾
 * @date 2021/1/6
 */


#include "alternate.hpp"


Alternate::Alternate(int pin, bool logic):
sw(pin, logic),
flag(false),
state(false),
before(false)
{}


bool Alternate::getSw(){
    before = state;
    state = sw.getSw();
    if(state && !before) flag = !flag;
    return flag;
}
