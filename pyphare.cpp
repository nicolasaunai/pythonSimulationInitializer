

#include "pyphare.h"

#include <sstream>
#include <string>
#include <variant>
#include <vector>

PHAREDict<1> phareDict;



template<typename T, typename = std::enable_if_t<cppdict::is_in<T, int, double, std::string,
                                                                cppfunctions::ScalarFunction<1>,
                                                                cppfunctions::VectorFunction<1>>>>
void add(std::string path, T&& value)
{
    cppdict::add(path, std::forward<T>(value), phareDict);
}


void f()
{
    add<double, void>("toto", 2.5);
}


PYBIND11_MODULE(pyphare, m)
{
    m.def("add", add<double, void>, "add");
}
