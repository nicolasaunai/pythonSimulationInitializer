#ifndef PYPHARE_H
#define PYPHARE_H

#include "cppdict/include/dict.hpp"
#include "cppfunctions.hpp"


#include <string>


template<std::size_t dim>
using PHAREDict = cppdict::Dict<int, double, std::string, cppfunctions::ScalarFunction<dim>,
                                cppfunctions::VectorFunction<dim>>;

extern PHAREDict<1> phareDict;


void add(std::string key, double v);
void add(std::string key, int v);
void add(std::string key, std::string v);
void add(std::string key, cppfunctions::ScalarFunction<1> v);
void add(std::string key, cppfunctions::VectorFunction<1> v);


#endif
