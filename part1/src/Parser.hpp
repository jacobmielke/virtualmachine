#pragma once
#include <iostream>
#include <vector>
#include <string>

class Parser
{
private:
    std::string filename;
public:
    std::vector<std::pair<std::string, std::string>> raw_codes;
    Parser(const std::string filename_);
    void parse_file();
    friend std::ostream& operator<<(std::ostream& os, const Parser& parser);
};