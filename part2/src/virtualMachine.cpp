#include "virtualMachine.hpp"
#include "baseStatement.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <memory>
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

    out_to_uppercase["Start"] = "OP_START_PROGRAM";
    out_to_uppercase["Exit"] = "OP_EXIT";
    out_to_uppercase["PushI"] = "OP_PUSHI";
    out_to_uppercase["Jump"] = "OP_JUMP";
    out_to_uppercase["JumpZero"] = "OP_JUMPZERO";
    out_to_uppercase["JumpNZero"] = "OP_JUMPNZERO";
    out_to_uppercase["GoSub"] = "OP_GOSUB";
    out_to_uppercase["PrintTOS"] = "OP_PRINTTOS";
    out_to_uppercase["Add"] = "OP_ADD";
    out_to_uppercase["Negate"] = "OP_NEGATE";
    out_to_uppercase["Mul"] = "OP_MUL";
    out_to_uppercase["Div"] = "OP_DIV";
    out_to_uppercase["Prints"] = "OP_PRINTS";
    out_to_uppercase["Dup"] = "OP_DUP";
    out_to_uppercase["Swap"] = "OP_SWAP";
    out_to_uppercase["GoSub"] = "OP_GOSUB";
    out_to_uppercase["GoSubLabel"] = "OP_ENTER_SUBROUTINE";
    out_to_uppercase["PopScalar"] = "OP_POP_SCALAR";
    out_to_uppercase["PopArray"] = "OP_POP_ARRAY";
    out_to_uppercase["PushScalar"] = "OP_PUSHSCALAR";
    out_to_uppercase["PushArray"] = "OP_PUSHARRAY";
    out_to_uppercase["Return"] = "OP_RETURN";
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
        //std::cout << first << " " << second << std::endl;
    }
}

void virtualMachine::create_buffer_entry(const std::string name, std::pair<const std::string, const std::string> args)
{
    // Check if name is in the lookup table
    if (out_to_uppercase.find(name) != out_to_uppercase.end())
    {
        std::string uppername = out_to_uppercase[name];
        std::unique_ptr<baseStatement> t = std::make_unique<baseStatement>(name, uppername, args);
        instruction_buffer.push_back(std::move(t));
    }
    else
    {
        string_table.push_back(name);
    }

}

void virtualMachine::print_string_table()
{
    std::cout << "PRINTING STRING TABLE" << std::endl;
    for (int i = 0; i < string_table.size(); i++)
    {
        std::cout << string_table[i] << std::endl;
    }
}

void virtualMachine::run()
{
    int function_id = 0;
    while(pc < instruction_buffer.size())
    {
        function_id = uppercase_to_id[instruction_buffer[pc]->get_uppername()];
        execute(function_id);
        pc++;
    }
}

void virtualMachine::execute(int id)
{
    switch (id)
    {
    case 0:
        std::cout << "OP_START_PROGRAM" << std::endl;
        break;
    case 1:
        std::cout << "" << std::endl;
        break;
    case 2:
        
    case 3:
        pc = stoi(instruction_buffer[pc]->get_args().second);
        break;
    default:
        std::cout << "STUMP" << std::endl;
        break;
    }
}