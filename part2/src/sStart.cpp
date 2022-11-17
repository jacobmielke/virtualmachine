#include "sStart.hpp"
#include "baseStatement.hpp"
#include "virtualMachine.hpp"
sStart::sStart(std::string _first, std::string _second) : baseStatement(_first, _second)
{
    // std::cout << "sStart constructor" << std::endl;
}

void sStart::execute()
{
    // std::cout << "sStart execute" << std::endl;

}
