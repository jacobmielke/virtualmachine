#pragma once
#include <iostream>
#include <vector>
#include <string>

class Parser
{
private:
    std::string filename;
public:
    /* Admin */
    Parser(const std::string filename_);
    friend std::ostream& operator<<(std::ostream& os, const Parser& parser);

    /* Part 1 */
    std::vector<std::pair<std::string, std::string>> raw_codes;
    void parse_raw_file();

    /* Part 2 */
    void parse_instrcution_file();
    std::vector<std::pair<std::string, std::string>> instruction_codes;
};