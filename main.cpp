#include <iostream>
#include "Cube/Cube.h"
#include "CLI/CubeCLI.h"

int main() {
    CubeCLI cubeCli;

    cubeCli.print_cube();
    cubeCli.print_indexes();
    cubeCli.print_states();

    std::cout<< "--------------------------------------\n";
    cubeCli.perform_command("F");

    cubeCli.print_cube();
    cubeCli.print_indexes();
    cubeCli.print_states();
    return 0;
}