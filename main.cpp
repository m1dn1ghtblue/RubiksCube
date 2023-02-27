#include <iostream>
#include "Cube/Cube.h"
#include "CLI/CubeCLI.h"

int main() {
    CubeCLI cubeCli;

    cubeCli.print_cube();
    cubeCli.print_states();

    std::cout<< "--------------------------------------\n";
    cubeCli.perform_command("B");

    cubeCli.print_cube();
    cubeCli.print_states();
    return 0;
}