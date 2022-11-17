#pragma once
#include <vector>
#include "baseStatement.hpp"
#include <memory>
#include <map>
#include <string>

class virtualMachine
{
private:
    /* Singleton */
    static virtualMachine* single;

    /* Parser Actions */
    std::vector<std::pair<std::string, std::string>> plain_input; // Input lines from a basic file
    std::vector<std::pair<std::string, std::string>> plain_instruction_buffer; // Input lines from a .out files

    /* Virtual Machine Runtime Actions */
    std::vector<std::unique_ptr<baseStatement>> instruction_buffer;
    int pc = 0; 
    std::vector<std::string> runtime_stack;
    std::vector<std::string> string_table;
    std::vector<std::string> data_table;
    
    /* Virtual Machine Functions */
    void execute(int); // Execute the instruction at the given index
    void start();
    void end();
    void pushi();

    /* Lookup Tables */
    std::map<std::string, int> uppercase_to_id;
    std::map<std::string, std::string> out_to_uppercase;

public:
    /* Singleton */
    static virtualMachine& get_instance(std::vector<std::pair<std::string, std::string>>); // Get the instance of the virtual machine
    virtualMachine(std::vector<std::pair<std::string, std::string>>);
    virtualMachine(virtualMachine &other) = delete;
    void operator=(const virtualMachine &) = delete;

    /* Parser Actions */
    void translate(); // Read the input lines and translate them into instructions
    void create_buffer_entry(const std::string, std::pair<const std::string, const std::string>); // Create a new entry in the instruction buffer
    void plain_to_instruction_buffer(); // Transfer the data from the parser to the virtual machine

    /* Virtual Machine Runtime Actions */
    void run(); // Run the virtual machine
    bool check_buffer();
    void print_buffer();
    void print_plain_instruction_buffer();
    void print_string_table();


};