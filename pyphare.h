#ifndef PYPHARE_H
#define PYPHARE_H

#include "cppdict/include/dict.hpp"
#include "cppfunctions.hpp"

#include <pybind11/pybind11.h>

#include <string>


template<std::size_t dim>
using PHAREDict = cppdict::Dict<int, double, std::string, cppfunctions::ScalarFunction<dim>,
                                cppfunctions::VectorFunction<dim>>;

extern PHAREDict<1> phareDict;


#endif
