/**
 * @file spray.hpp
 * @brief 噴射モジュール
 * @author 岡部
 * @date 2020/11/05
 */

#ifndef __SPRAY__
#define __SPRAY__

/**
 * @brief 噴射クラス
 * @details hand.cからの値を読み取り、モータを回す。
 */
class Spray{
public:
    Spray();
    /**
     * @brief モータを回す関数
     */
    void pushBottle();


private:
    //!モータを回す角度[dec]
    static const int spray_morter = 360;
    //! ギア比
    static const float gear_rate;
    

};

#endif
