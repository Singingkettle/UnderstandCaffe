//
// Created by Citybuster on 2020/4/17.
//

#include <iostream>
#include "../include/product_factory.h"
#include <vector>
#include "../include/product.h"
#include <boost/shared_ptr.hpp>
#include "../include/parts.h"
using namespace std;


void understandLayerFactory()
{
    // 构造
    ShoesParameter p1 = {"red", 42, "Nike"};
    ShoesParameter p2 = {"yellow", 42, "Nike"};
    ShoesParameter p3 = {"red", 42, "Adidas"};
    ShoesParameter p4 = {"red", 42, "Tmp"};

    vector<shared_ptr<Shoes>> types_;

    types_.push_back(ProductRegistry::CreateLayer(p1));
    cout<<"==========================="<<endl;
    types_[0]->Show();
    cout<<"==========================="<<endl;
    types_.push_back(ProductRegistry::CreateLayer(p2));
    cout<<"==========================="<<endl;
    types_[1]->Show();
    cout<<"==========================="<<endl;
    types_.push_back(ProductRegistry::CreateLayer(p3));
    cout<<"==========================="<<endl;
    types_[2]->Show();
    cout<<"==========================="<<endl;
    types_.push_back(ProductRegistry::CreateLayer(p4));

}