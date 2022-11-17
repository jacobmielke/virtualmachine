#include <string>
#include <iostream>
#include <vector>
#include "Parser.hpp"
#include "virtualMachine.hpp"

int main(int argc, char *argv[]) {
    std::string instruction_file = argv[1];

    /* Parse the file */
    Parser parser(instruction_file); // Assuming the input is given correctly at the command line
    parser.parse_instrcution_file();

    /* Create the virtual machine */
    virtualMachine& vm = virtualMachine::get_instance(parser.instruction_codes);
    vm.plain_to_instruction_buffer(); // Convert the plain instruction buffer to the instruction buffer

    /* Execute the instructions */
    vm.run();
    
    return 0;
}