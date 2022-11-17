#include "virtualMachine.hpp"
#include "baseStatement.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include "sStart.hpp"
// Use smart pointers to manage memory
virtualMachine* virtualMachine::single = nullptr;

virtualMachine::virtualMachine(std::vector<std::pair<std::string, std::string>>  input_lines)
{
    plain_instruction_buffer = input_lines; // Transfer the data from the parser to the virtual machine

    /* Create the lookup table */
    uppercase_to_id["OP_START_PROGRAM"] = 0;
    uppercase_to_id["OP_EXIT"] = 1;
    uppercase_to_id["OP_ENTER_SUBROUTINE"] = 2;
    uppercase_to_id["OP_JUMP"] = 3;
    uppercase_to_id["OP_JUMPZERO"] = 4;
    uppercase_to_id["OP_JUMPNZERO"] = 5;
    uppercase_to_id["OP_GOSUB"] = 6;
    uppercase_to_id["OP_RETURN"] = 7;
    uppercase_to_id["OP_PUSHSCALAR"] = 8;
    uppercase_to_id["OP_PUSHARRAY"] = 9;
    uppercase_to_id["OP_PUSHI"] = 10;
    uppercase_to_id["OP_POP"] = 11;
    uppercase_to_id["OP_POP_SCALAR"] = 12;
    uppercase_to_id["OP_POP_ARRAY"] = 13;
    uppercase_to_id["OP_DUP"] = 14;
    uppercase_to_id["OP_SWAP"] = 15;
    uppercase_to_id["OP_ADD"] = 16;
    uppercase_to_id["OP_NEGATE"] = 17;
    uppercase_to_id["OP_MUL"] = 18;
    uppercase_to_id["OP_DIV"] = 19;
    uppercase_to_id["OP_PRINTS"] = 20;
    uppercase_to_id["OP_PRINTTOS"] = 21;

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
    std::cout << "Part 1" << std::endl;
}

void virtualMachine::print_plain_instruction_buffer()
{
    std::cout << "PRINTING PLAIN INSTRUCTION BUFFER FROM A POUT FILE" << std::endl;
    for (int i = 0; i < plain_instruction_buffer.size(); i++)
    {
        std::cout << plain_instruction_buffer[i].first << " " << plain_instruction_buffer[i].second << std::endl;
    }
}

void virtualMachine::print_buffer()
{
    std::cout << "PRINTING INSTRUCTION BUFFER" << std::endl;
    for(int i = 0; i < instruction_buffer.size(); i++)
    {
        std::cout << instruction_buffer[i]->get_uppername() << std::endl;
    }
}
bool virtualMachine::check_buffer()
{
    if (instruction_buffer.size() == 0)
    {
        return false;
    }
    return true;
}

void virtualMachine::plain_to_instruction_buffer()
{
    for (int i = 0; i < plain_instruction_buffer.size(); i++)
    {
        std::string first = plain_instruction_buffer[i].first;
        std::string second = plain_instruction_buffer[i].second;
        std::pair<std::string, std::string> split = std::make_pair("empty", "empty");
        if (second != "")
        {
            split.first = second.substr(0, second.find(" "));
            split.second = second.substr(second.find(" ") + 1, second.length()); 
        }
        create_buffer_entry(first, split);
        std::cout << first << " " << second << std::endl;
    }
}

void virtualMachine::create_buffer_entry(const std::string name, std::pair<const std::string, const std::string> args)
{
    if (name == "Start")
    {
        // Create a new start statement
        std::unique_ptr<baseStatement> t = std::make_unique<sStart>(name, "OP_START_PROGRAM");
        instruction_buffer.push_back(std::move(t));
    }
    else if (name == "Exit")
    {

    }
    else if (name == "PushI")
    {
        
    }
    else if (name == "PrintTOS")
    {

    }
    else if (name == "Add")
    {
        
    }
    else if (name == "Prints")
    {

    }
    else if (name == "Div")
    {

    }
    else if (name == "Dup")
    {

    }
    else if (name == "Mul")
    {

    }
    else if (name == "Swap")
    {

    }
    else if (name == "Jump")
    {

    }
    else if (name == "GoSub")
    {

    }
    else if (name == "GoSubLabel")
    {

    }
    else if (name == "PopScalar")
    {

    }
    else if (name == "PushScalar")
    {

    }
    else if (name == "PopArray")
    {

    }
    else if (name == "PushArray")
    {

    }
    else if (name == "Negate")
    {

    }
    else if (name == "JumpNZero")
    {

    }
    else if (name == "Return")
    {

    }
    else 
    {
        string_table.push_back(name);
    }
}