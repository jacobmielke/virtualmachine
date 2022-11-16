#pragma once
#include "baseStatement.hpp"
#include <vector>
#include <memory>
#include <iostream>

class instructionBuffer 
{
private:
    std::vector<std::unique_ptr<baseStatement>> buffer;// Hold vector of unique pointers to baseStatement objects
public:
    void add_instruction(std::unique_ptr<baseStatement> instruction);
    int find_instruction(std::string name);
    friend std::ostream& operator<<(std::ostream& os, const instructionBuffer& buffer);
};