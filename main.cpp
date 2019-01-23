

#include "cppdict/include/dict.hpp"
#include "cppfunctions.hpp"
#include "pyphare.h"


#include <pybind11/embed.h> // everything needed for embedding
#include <pybind11/functional.h>
namespace py = pybind11;


#include <cstddef>
#include <string>




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

    phareDict["simulation"]["ions"]["protons"]["fluidInitializer"]["density"] = density;
    //
    cppdict::add("toto/tata/titi", 2.5, phareDict);
    std::cout << "at toto/tata/titi : " << phareDict["toto"]["tata"]["titi"].to<double>() << "\n";
}
