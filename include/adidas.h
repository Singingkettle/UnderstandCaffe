//
// Created by Citybuster on 2020/4/17.
//

#ifndef LEARNCPP_ADIDAS_H
#define LEARNCPP_ADIDAS_H

#include <iostream>
#include "product.h"
#include "product_factory.h"

// 阿迪鞋子
class AdidasShoes : public Shoes
{
public:
    explicit AdidasShoes(const ShoesParameter &param):Shoes(param) {}
    void Show() override;
};



#endif //LEARNCPP_ADIDAS_H
