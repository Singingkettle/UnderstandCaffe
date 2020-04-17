//
// Created by Citybuster on 2020/4/17.
//

#include "../include/adidas.h"

void AdidasShoes::Show() {
    std::cout << "阿迪球鞋, 大小："<<this->param_.size<<", 颜色："<<this->param_.color<<std::endl;
};

REGISTER_TYPE_CLASS(Adidas);