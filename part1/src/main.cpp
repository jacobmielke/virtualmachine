#include "virtualMachine.hpp"
#include "Parser.hpp"
#include "instructionBuffer.hpp"
#include <memory>

int main(int argc, char* argv[])
{
    /* Parse the file */
    Parser parser(argv[1]); 
    parser.parse_file();

    /* Create the instruction buffer */
    instructionBuffer buffer;

    /* Create the virtual machine */
    virtualMachine& vm = virtualMachine::get_instance(parser.raw_codes);
    std::cout << parser << std::endl;
    vm.translate();
    return 0;
}
