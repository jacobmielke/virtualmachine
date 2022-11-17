#pragma once
#include "baseStatement.hpp"
#include "virtualMachine.hpp"

class sStart : public baseStatement
{
private:
    
public:
    sStart(std::string, std::string);    
    void execute();
};
