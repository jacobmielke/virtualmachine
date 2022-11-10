#include "virtualMachine.hpp"
#include "opCodeBase.hpp"
#include <vector>
#include <iostream>

// Use smart pointers to manage memory

virtualMachine* virtualMachine::single = nullptr;

virtualMachine::virtualMachine(std::vector<std::pair<std::string, std::string>>  input_lines)
{
    input = input_lines; // Transfer the data from the parser to the virtual machine
}

virtualMachine& virtualMachine::get_instance(std::vector<std::pair<std::string, std::string>>  input_lines)
{
    if (single == nullptr)
    {
        single = new virtualMachine(input_lines);
    }
    return *single;
}

void virtualMachine::translate()
{

}