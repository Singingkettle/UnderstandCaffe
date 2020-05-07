# cmake_minimum_required(VERSION <specify CMake version here>)
project(UnderstandCaffe)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost)
include_directories(${Boost_INLUDE_DIRS})

add_executable(UnderstandCaffe main.cpp include/product_factory.h include/product.h include/nike.h include/adidas.h src/adidas.cpp src/nike.cpp src/understandLayerFactory.cpp include/parts.h)

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARYS})