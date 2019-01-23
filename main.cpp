

#include "cppdict/include/dict.hpp"
#include "cppfunctions.hpp"


#include <pybind11/embed.h> // everything needed for embedding
#include <pybind11/functional.h>
namespace py = pybind11;


#include <cstddef>
#include <string>

template<std::size_t dim>
using MyDict = cppdict::Dict<int, double, std::string, cppfunctions::ScalarFunction<dim>,
                             cppfunctions::VectorFunction<dim>>;




int main()
{
    py::scoped_interpreter guard{}; // start the interpreter and keep it alive
    py::object scipy = py::module::import("scipy");
    py::print(scipy.attr("__version__"));
    py::print("Hello, World!"); // use the Python API

    auto init                               = py::module::import("init");
    py::object densityFunc                  = init.attr("density");
    cppfunctions::ScalarFunction<1> density = densityFunc.cast<cppfunctions::ScalarFunction<1>>();

    auto n = density(5);
    std::cout << n << "\n";

    MyDict<1> d;
    d["simulation"]["ions"]["protons"]["fluidInitializer"]["density"] = density;
}
