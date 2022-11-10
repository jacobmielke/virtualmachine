#pragma once
#include <iostream>

class opCodeBase
{
private:
    virtual void execute() = 0;
    std::string parsename; // Name of the opcode as it appears in the input file
    std::string name; // Name of the opcode as it appears in the output file
public:
    opCodeBase();
    virtual ~opCodeBase();
    virtual void do_action(); // Carry out the action during the execution of the program
    friend std::ostream& operator<<(std::ostream& os, const opCodeBase& opCode);
};
