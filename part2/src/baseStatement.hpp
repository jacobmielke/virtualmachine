#pragma once
#include <iostream>
#include <string>
class baseStatement
{
private:
    std::string lowername; 
    std::string uppername; 
    std::pair<std::string, std::string> args;
public:
    baseStatement(std::string, std::string, std::pair<const std::string, const std::string> );
    std::pair<std::string, std::string> get_args();
    std::string get_lowername();
    std::string get_uppername();
};
