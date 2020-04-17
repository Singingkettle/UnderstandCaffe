//
// Created by Citybuster on 2020/4/17.
//

#include "../include/nike.h"

void NikeShoes::Show() {
    std::cout << "耐克球鞋, 大小："<<this->param_.size<<", 颜色："<<this->param_.color<<std::endl;
};

REGISTER_TYPE_CLASS(Nike);
