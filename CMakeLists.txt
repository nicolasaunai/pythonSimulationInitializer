cmake_minimum_required(VERSION 3.5)

project(python_simu_initializer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(pybind11)

if (NOT pybind11_FOUND)

    message("downloading subproject pybind11")
    set(PYBIND11_SRCDIR ${CMAKE_CURRENT_SOURCE_DIR}/pybind11)

    if (NOT EXISTS ${PYBIND11_SRCDIR})
      execute_process(
        COMMAND ${Git} clone https://github.com/pybind/pybind11 ${PYBIND11_SRCDIR}
        )
    endif()


        add_subdirectory(${PYBIND11_SRCDIR})

endif()

set(PYBIND11_CPP_STANDARD -std=c++17)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/setpythonpath.py.in ${CMAKE_CURRENT_BINARY_DIR}/setpythonpath.py @ONLY)

pybind11_add_module(pyphare pyphare.cpp pyphare.h cppfunctions.hpp)

add_executable(initializer main.cpp cppfunctions.hpp pyphare.cpp pyphare.h)
target_link_libraries(initializer PUBLIC pybind11::embed)
