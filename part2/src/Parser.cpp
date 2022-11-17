#include "Parser.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string>

Parser::Parser(const std::string filename_) : filename(filename_) {}

void Parser::parse_raw_file()
{
    std::ifstream file;
    std::string line;
    file.open(filename);
    if (!file.is_open())
    {
        std::cout << "File not found" << std::endl;
    }
    else
    while (std::getline(file, line))
    {
        std::pair<std::string, std::string> temp; // Temporary pair to store the opcode and its arguments
        temp.first = line.substr(0, line.find(" ")); // Get the opcode
        //Make sure there are arguments
        if (line.find(" ") != std::string::npos)
        {
            // Place the arguments as one string
            temp.second = line.substr(line.find(" ") + 1, line.length());
        }
        raw_codes.push_back(temp);
    }
    file.close();
}

void Parser::parse_instrcution_file()
{
    std::ifstream file;
    std::string line;
    file.open(filename);
    if (!file.is_open())
    {
        std::cout << "File not found" << std::endl;
    }
    else
    while (std::getline(file, line))
    {
        std::pair<std::string, std::string> temp; // Temporary pair to store the opcode and its arguments
        temp.first = line.substr(0, line.find(" ")); // Get the opcode
        //Make sure there are arguments
        if (line.find(" ") != std::string::npos)
        {
            // Place the arguments as one string
            temp.second = line.substr(line.find(" ") + 1, line.length());
        }
        instruction_codes.push_back(temp);
    }
    file.close();
}


std::ostream &operator<<(std::ostream &os, const Parser &parser)
{
    for (auto i : parser.raw_codes)
    {
        os << i.first << " " << i.second << std::endl;
    }
    return os;
}

