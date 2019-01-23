

#include "pyphare.h"

#include <sstream>
#include <string>
#include <variant>
#include <vector>

PHAREDict<1> phareDict;


std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}


auto& get(std::vector<std::string> keys, int iKey, PHAREDict<1>& currentNode)
{
    if (iKey == keys.size() - 1)
    {
        return currentNode[keys[iKey]];
    }
    else
    {
        return get(keys, iKey + 1, currentNode[keys[iKey]]);
    }
}



void add(std::string path, double v)
{
    auto keys   = split(path, '/');
    auto&& node = get(keys, 0, phareDict);
    node        = v;
}


void add(std::string path, int v) {}


void add(std::string path, std::string v) {}


void add(std::string path, cppfunctions::ScalarFunction<1> v) {}


void add(std::string path, cppfunctions::VectorFunction<1> v) {}
