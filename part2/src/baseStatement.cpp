#include "baseStatement.hpp"
#include <string>
#include "virtualMachine.hpp"
baseStatement::baseStatement(std::string _lowername, std::string _uppername) : lowername(_lowername), uppername(_uppername)
{
    // std::cout << "baseStatement constructor" << std::endl;
}


std::string baseStatement::get_lowername()
{
    return lowername;
}

std::string baseStatement::get_uppername()
{
    return uppername;
}