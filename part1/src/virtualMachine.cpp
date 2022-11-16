#include "virtualMachine.hpp"
#include "baseStatement.hpp"
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

void virtualMachine::set_buffer(std::unique_ptr<instructionBuffer> &buffer_)
{
    buffer = std::move(buffer_);
}

void virtualMachine::translate()
{
    std::vector <std::string> tokens; // Hold the individual items from the second string
    for (int i = 0; i < input.size(); i++)
    {
        /* Split the raw input into two different values */
        std::string first = input[i].first;
        std::string second = input[i].second;
        if(second != "")
        {
            // Grab the label from the argument string
            tokens.push_back(second.substr(0, second.find(" ")));
            tokens.push_back(second.substr(second.find(" ") + 1, second.size()));
            std::cout << tokens[0] << " " << tokens[1] << std::endl;
        }
        std::cout << first << " " << second << std::endl;
        
    }
}
