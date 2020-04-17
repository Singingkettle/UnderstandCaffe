//
// Created by Citybuster on 2020/4/17.
//

#ifndef LEARNCPP_PRODUCT_H
#define LEARNCPP_PRODUCT_H

#include <iostream>
using namespace std;

struct ShoesParameter {
    string color;
    int size;
    string type;
};


class Shoes
{
public:
    explicit Shoes(const ShoesParameter &param): param_(param) {
        type_ = param.type;
    }

    virtual void ShoesSetUp() {}
    virtual ~Shoes() {}
    virtual void Show() {
        cout<<"Base Class"<<endl;
    };

protected:
    ShoesParameter param_;
private:
    string type_;

};
#endif //LEARNCPP_PRODUCT_H
