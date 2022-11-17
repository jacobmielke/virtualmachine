#pragma once
#include <iostream>
#include <string>
class baseStatement
{
private:
    std::string lowername; 
    std::string uppername; 
public:
    baseStatement(std::string, std::string);
    virtual ~baseStatement() = default;
    virtual void execute() = 0;
    std::string get_lowername();
    std::string get_uppername();
};
