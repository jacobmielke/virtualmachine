#include "virtualMachine.hpp"
#include "Parser.hpp"
int main(int argc, char* argv[])
{
    Parser parser(argv[1]);
    parser.parse_file();
    virtualMachine& vm = virtualMachine::get_instance(parser.raw_codes);
    std::cout << parser << std::endl;
    vm.translate();
    return 0;
}
