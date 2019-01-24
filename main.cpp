

#include "cppdict/include/dict.hpp"
#include "cppfunctions.hpp"
#include "pyphare.h"


#include <pybind11/embed.h> // everything needed for embedding
#include <pybind11/functional.h>
namespace py = pybind11;


#include <cstddef>
#include <string>

void prepare()
{
    py::object scope = py::module::import("__main__").attr("__dict__");
    py::eval_file("setpythonpath.py", scope);
}

py::scoped_interpreter guard{}; // start the interpreter and keep it alive


int main(int argc, char** argv)
{
    std::string module = "job.py";
    if (argc == 2)
    {
        module = argv[1];
    }

    module.erase(module.find("."), module.size() - 1);

    prepare();

    auto init = py::module::import(module.c_str());

    py::object densityFunc                  = init.attr("density");
    cppfunctions::ScalarFunction<1> density = densityFunc.cast<cppfunctions::ScalarFunction<1>>();

    auto n = density(5);
    std::cout << n << "\n";

    phareDict["simulation"]["ions"]["protons"]["fluidInitializer"]["density"] = density;
    //
    cppdict::add("toto/tata/titi", 2.5, phareDict);
    std::cout << "at toto/tata/titi : " << phareDict["toto"]["tata"]["titi"].to<double>() << "\n";
}
