cmake_minimum_required(VERSION 2.8.7)
project(UnderstandCaffe)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-std=c++11)

add_executable(UnderstandCaffe main.cpp include/product_factory.h include/product.h include/nike.h include/adidas.h src/adidas.cpp src/nike.cpp src/understandLayerFactory.cpp include/parts.h)
