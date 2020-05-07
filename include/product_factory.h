//
// Created by Citybuster on 2020/4/17.
//

#ifndef LEARNCPP_PRODUCT_FACTORY_H
#define LEARNCPP_PRODUCT_FACTORY_H

#include <iostream>
#include <map>
#include <vector>
// #include <boost/shared_ptr.hpp>
#include <memory> //  用C++11代替boost的智能指针
#include "product.h"

using namespace std;

class Shoes;

class ProductRegistry {
public:
    typedef shared_ptr<Shoes> (*Creator)(const ShoesParameter&);

    // CreatorRegistry是字符串与对应的Creator的映射
    typedef map<string, Creator> CreatorRegistry;

    static CreatorRegistry &Registry() {
        static auto *g_registry_ = new CreatorRegistry();
        return *g_registry_;
    }

    static void AddCreator(const string &type, Creator creator) {
        CreatorRegistry &registry = Registry();
        if (registry.count(type) == 1) {
            cout << "Shoes type " << type << " already registered."<<endl;
        }
        registry[type] = creator;
    }

    static shared_ptr<Shoes> CreateLayer(const ShoesParameter& p) {
        string type = p.type;
        CreatorRegistry &registry = Registry();
        if (registry.count(type) == 0) {
            cout << "Unknown shoes type: " << type << " (known shoes types: " << TypeListString() << ")"<<endl;
            exit(100);
        }
        return registry[type](p);
    }

    static vector<string> TypeList() {
        CreatorRegistry &registry = Registry();
        vector<string> types;
        for (typename CreatorRegistry::iterator iter = registry.begin();
             iter != registry.end(); ++iter) {
            types.push_back(iter->first);
        }
        return types;
    }

private:

    ProductRegistry() {}

    static string TypeListString() {
        vector<string> types = TypeList();
        string types_str;
        for (auto iter = types.begin();
             iter != types.end(); ++iter) {
            if (iter != types.begin()) {
                types_str += ", ";
            }
            types_str += *iter;
        }
        return types_str;
    }
};

class ProductRegister {
public:
    ProductRegister(const string &type, shared_ptr<Shoes> (*creator)(const ShoesParameter &)) {
        ProductRegistry::AddCreator(type, creator);
    }
};

#define REGISTER_PRODUCT_CREATOR(type, creator)                                   \
  static ProductRegister g_creator_##type(#type, creator)                         \

#define REGISTER_TYPE_CLASS(type)                                                 \
  shared_ptr<Shoes> Creator_##type##Shoes(const ShoesParameter& param)            \
  {                                                                               \
    return shared_ptr<Shoes>(new type##Shoes(param));                             \
  }                                                                               \
  REGISTER_PRODUCT_CREATOR(type, Creator_##type##Shoes)

#endif //LEARNCPP_PRODUCT_FACTORY_H
