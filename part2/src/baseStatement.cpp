#include "baseStatement.hpp"
#include <string>
#include "virtualMachine.hpp"
baseStatement::baseStatement(std::string _lowername, std::string _uppername, std::pair<const std::string, const std::string>_args) 
: lowername(_lowername), uppername(_uppername), args(_args) {}




std::string baseStatement::get_lowername()
{
    return lowername;
}

std::string baseStatement::get_uppername()
{
    return uppername;
}

std::pair<std::string, std::string> baseStatement::get_args()
{
    return args;
}