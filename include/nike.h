//
// Created by Citybuster on 2020/4/17.
//

#ifndef LEARNCPP_NIKE_H
#define LEARNCPP_NIKE_H

#include <iostream>
#include "product.h"
#include "product_factory.h"

// 耐克鞋子
class NikeShoes : public Shoes
{
public:
    explicit NikeShoes(const ShoesParameter &param):Shoes(param) {}
    void Show() override;

};


#endif //LEARNCPP_NIKE_H
