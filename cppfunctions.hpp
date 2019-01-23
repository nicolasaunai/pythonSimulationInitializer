#ifndef CPPFUNCTIONS_H
#define CPPFUNCTIONS_H

#include <array>
#include <functional>

namespace cppfunctions
{
template<typename ReturnType, std::size_t dim>
struct ScalarFunctionHelper
{
};

template<>
struct ScalarFunctionHelper<double, 1>
{
    using type = std::function<double(double)>;
};

template<>
struct ScalarFunctionHelper<double, 2>
{
    using type = std::function<double(double)>;
};

template<>
struct ScalarFunctionHelper<double, 3>
{
    using type = std::function<double(double, double, double)>;
};

template<typename ReturnType, std::size_t dim>
struct VectorFunctionHelper
{
};

template<>
struct VectorFunctionHelper<std::array<double, 3>, 1>
{
    using type = std::function<std::array<double, 3>(double)>;
};

template<>
struct VectorFunctionHelper<std::array<double, 3>, 2>
{
    using type = std::function<std::array<double, 3>(double, double)>;
};

template<>
struct VectorFunctionHelper<std::array<double, 3>, 3>
{
    using type = std::function<std::array<double, 3>(double, double, double)>;
};

template<std::size_t dim>
using ScalarFunction = typename ScalarFunctionHelper<double, dim>::type;

template<std::size_t dim>
using VectorFunction = typename VectorFunctionHelper<std::array<double, 3>, dim>::type;

} // namespace cppfunctions
#endif
