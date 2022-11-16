#pragma once
#include <vector>
#include "baseStatement.hpp"
#include "instructionBuffer.hpp"
#include <memory>

class virtualMachine
{
// Singleton class of the virtual machine
private:
    // Hold a reference to the instruction buffer
    std::unique_ptr<instructionBuffer> buffer;
    
    std::vector<std::pair<std::string, std::string>> input; // Vector of input lines
    static virtualMachine* single;
public:
    virtualMachine(std::vector<std::pair<std::string, std::string>>);
    virtualMachine(virtualMachine &other) = delete;
    void operator=(const virtualMachine &) = delete;
    static virtualMachine& get_instance(std::vector<std::pair<std::string, std::string>>); // Get the instance of the virtual machine
    void translate(); // Read the input lines and translate them into instructions
    void set_buffer(std::unique_ptr<instructionBuffer> &buffer_); // Set the instruction buffer
};