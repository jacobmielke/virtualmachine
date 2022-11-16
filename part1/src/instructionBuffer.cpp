#include "instructionBuffer.hpp"
#include "baseStatement.hpp"
#include <iostream>

void instructionBuffer::add_instruction(std::unique_ptr<baseStatement> instruction)
{
    buffer.push_back(std::move(instruction));
}

int instructionBuffer::find_instruction(std::string name)
{
    for (int i = 0; i < buffer.size(); i++)
    {
        if (buffer[i]->get_name() == name)
        {
            return i;
        }
    }
    return -1;
}