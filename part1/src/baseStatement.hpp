#pragma once
#include <iostream>

class baseStatement
{
private:
    virtual void execute() = 0;
    std::string parsename; // Name of the opcode as it appears in the input file
    std::string name; // Name of the opcode as it appears in the output file
public:
    baseStatement();
    virtual ~baseStatement();
    virtual void do_action(); // Carry out the action during the execution of the program
    friend std::ostream& operator<<(std::ostream& os, const baseStatement& opCode);
    std::string get_name();
};
