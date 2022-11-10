#pragma once
#include <vector>
#include "opCodeBase.hpp"
class virtualMachine
{
// Singleton class of the virtual machine
private:
    std::vector<opCodeBase*> opCodes; // Vector of opcodes
    std::vector<std::pair<std::string, std::string>> input; // Vector of input lines
    static virtualMachine* single;
public:
    virtualMachine(std::vector<std::pair<std::string, std::string>>);
    virtualMachine(virtualMachine &other) = delete;
    void operator=(const virtualMachine &) = delete;
    static virtualMachine& get_instance(std::vector<std::pair<std::string, std::string>>);
    void translate();
};