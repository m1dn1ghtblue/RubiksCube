#include "CubeCLI.h"
#include <iostream>
#include <sstream>
#include <array>

CubeCLI::CubeCLI() {
    cube = Cube();

    surfaceColormap = {'U', 'L', 'F', 'R', 'B', 'D'};

    cornerColormap = {
            {ULB, {surfaceColormap[U], surfaceColormap[L], surfaceColormap[B]}},
            {UFL, {surfaceColormap[U], surfaceColormap[F], surfaceColormap[L]}},
            {UBR, {surfaceColormap[U], surfaceColormap[B], surfaceColormap[R]}},
            {URF, {surfaceColormap[U], surfaceColormap[R], surfaceColormap[F]}},
            {DBL, {surfaceColormap[D], surfaceColormap[B], surfaceColormap[L]}},
            {DLF, {surfaceColormap[D], surfaceColormap[L], surfaceColormap[F]}},
            {DRB, {surfaceColormap[D], surfaceColormap[R], surfaceColormap[B]}},
            {DFR, {surfaceColormap[D], surfaceColormap[F], surfaceColormap[R]}},
    };

    edgeColormap = {
            {UL, {surfaceColormap[U], surfaceColormap[L]}},
            {UR, {surfaceColormap[U], surfaceColormap[R]}},
            {UF, {surfaceColormap[U], surfaceColormap[F]}},
            {UB, {surfaceColormap[U], surfaceColormap[B]}},
            {DL, {surfaceColormap[D], surfaceColormap[L]}},
            {DR, {surfaceColormap[D], surfaceColormap[R]}},
            {DF, {surfaceColormap[D], surfaceColormap[F]}},
            {DB, {surfaceColormap[D], surfaceColormap[B]}},
            {FL, {surfaceColormap[F], surfaceColormap[L]}},
            {FR, {surfaceColormap[F], surfaceColormap[R]}},
            {BL, {surfaceColormap[B], surfaceColormap[L]}},
            {BR, {surfaceColormap[B], surfaceColormap[R]}},
    };

    commands = {
            {"U", U_CW},
            {"U'", U_CCW},
            {"U2", U_2},
            {"D", D_CW},
            {"D'", D_CCW},
            {"D2", D_2},
            {"L", L_CW},
            {"L'", L_CCW},
            {"L2", L_2},
            {"R", R_CW},
            {"R'", R_CCW},
            {"R2", R_2},
            {"B", B_CW},
            {"B'", B_CCW},
            {"B2", B_2},
            {"F", F_CW},
            {"F'", F_CCW},
            {"F2", F_2},
    };
}

void CubeCLI::print_cube() {
    typedef std::array<std::array<char, 3>, 3> surface_matrix;
    surface_matrix up;
    surface_matrix down;
    surface_matrix left;
    surface_matrix right;
    surface_matrix front;
    surface_matrix back;

    // paint centers
    up[1][1] = surfaceColormap[U];
    down[1][1] = surfaceColormap[D];
    left[1][1] = surfaceColormap[L];
    right[1][1] = surfaceColormap[R];
    front[1][1] = surfaceColormap[F];
    back[1][1] = surfaceColormap[B];

    // paint edges
    std::tie(up[0][1], back[0][1]) = get_edge_colors(UB);
    std::tie(up[1][0], left[0][1]) = get_edge_colors(UL);
    std::tie(up[1][2], right[0][1]) = get_edge_colors(UR);
    std::tie(up[2][1], front[0][1]) = get_edge_colors(UF);
    std::tie(down[0][1], front[2][1]) = get_edge_colors(DF);
    std::tie(down[1][0], left[2][1]) = get_edge_colors(DL);
    std::tie(down[1][2], right[2][1]) = get_edge_colors(DR);
    std::tie(down[2][1], back[2][1]) = get_edge_colors(DB);
    std::tie(back[1][2], left[1][0]) = get_edge_colors(BL);
    std::tie(front[1][0], left[1][2]) = get_edge_colors(FL);
    std::tie(front[1][2], right[1][0]) = get_edge_colors(FR);
    std::tie(back[1][0], right[1][2]) = get_edge_colors(BR);

    // paint corners
    std::tie(up[0][0], left[0][0], back[0][2]) = get_corner_colors(ULB);
    std::tie(up[0][2], back[0][0], right[0][2]) = get_corner_colors(UBR);
    std::tie(up[2][0], front[0][0], left[0][2]) = get_corner_colors(UFL);
    std::tie(up[2][2], right[0][0], front[0][2]) = get_corner_colors(URF);
    std::tie(down[0][0], left[2][2], front[2][0]) = get_corner_colors(DLF);
    std::tie(down[0][2], front[2][2], right[2][0]) = get_corner_colors(DFR);
    std::tie(down[2][0], back[2][2], left[2][0]) = get_corner_colors(DBL);
    std::tie(down[2][2], right[2][2], back[2][0]) = get_corner_colors(DRB);

    printf("\n"
           "        %c %c %c\n"
           "        %c %c %c\n"
           "        %c %c %c\n"
           "\n"
           "%c %c %c   %c %c %c   %c %c %c   %c %c %c\n"
           "%c %c %c   %c %c %c   %c %c %c   %c %c %c\n"
           "%c %c %c   %c %c %c   %c %c %c   %c %c %c\n"
           "\n"
           "        %c %c %c\n"
           "        %c %c %c\n"
           "        %c %c %c\n",
           up[0][0], up[0][1], up[0][2],
           up[1][0], up[1][1], up[1][2],
           up[2][0], up[2][1], up[2][2],

           left[0][0], left[0][1], left[0][2],
           front[0][0], front[0][1], front[0][2],
           right[0][0], right[0][1], right[0][2],
           back[0][0], back[0][1], back[0][2],

           left[1][0], left[1][1], left[1][2],
           front[1][0], front[1][1], front[1][2],
           right[1][0], right[1][1], right[1][2],
           back[1][0], back[1][1], back[1][2],

           left[2][0], left[2][1], left[2][2],
           front[2][0], front[2][1], front[2][2],
           right[2][0], right[2][1], right[2][2],
           back[2][0], back[2][1], back[2][2],

           down[0][0], down[0][1], down[0][2],
           down[1][0], down[1][1], down[1][2],
           down[2][0], down[2][1], down[2][2]
           );
}

std::tuple<char, char> CubeCLI::get_edge_colors(E_POS position) {
    EdgeCubie edge = cube.getEdge(position);
    std::array<char, 2> colors = edgeColormap[static_cast<E_POS>(edge.get_original_id())];

    return std::make_tuple(
            colors[edge.get_twist_state()],
            colors[(edge.get_twist_state() + 1) % 2]
            );
}

std::tuple<char, char, char> CubeCLI::get_corner_colors(C_POS position) {
    CornerCubie corner = cube.getCorner(position);
    std::array<char, 3> colors = cornerColormap[static_cast<C_POS>(corner.get_original_id())];

    std::array<char, 3> placed_colors {};

    placed_colors[corner.get_twist_state()] = colors[0];
    placed_colors[(corner.get_twist_state() + 1) % 3] = colors[1];
    placed_colors[(corner.get_twist_state() + 2) % 3] = colors[2];

    return std::make_tuple(
            colors[(3 - corner.get_twist_state()) % 3],
            colors[(4 - corner.get_twist_state()) % 3],
            colors[(5 - corner.get_twist_state()) % 3]
    );
}


void CubeCLI::perform_sequence(const std::string& sequence) {
    std::istringstream sequenceStream(sequence);
    std::string command;
    while (std::getline(sequenceStream, command, ' ')) {
        perform_command(command);
    }
}

void CubeCLI::perform_command(const std::string& command) {
    switch (commands[command]) {
        case U_CW:
            cube.turn_U();
            break;
        case U_CCW:
            cube.turn_U(true);
            break;
        case U_2:
            cube.turn_U2();
            break;
        case D_CW:
            cube.turn_D();
            break;
        case D_CCW:
            cube.turn_D(true);
            break;
        case D_2:
            cube.turn_D2();
            break;
        case L_CW:
            cube.turn_L();
            break;
        case L_CCW:
            cube.turn_L(true);
            break;
        case L_2:
            cube.turn_L2();
            break;
        case R_CW:
            cube.turn_R();
            break;
        case R_CCW:
            cube.turn_R(true);
            break;
        case R_2:
            cube.turn_R2();
            break;
        case F_CW:
            cube.turn_F();
            break;
        case F_CCW:
            cube.turn_F(true);
            break;
        case F_2:
            cube.turn_F2();
            break;
        case B_CW:
            cube.turn_B();
            break;
        case B_CCW:
            cube.turn_B(true);
            break;
        case B_2:
            cube.turn_B2();
            break;
        default:
            break;
    }
}

void CubeCLI::loop() {
    std::string input;
    print_cube();
    while (std::cin >> input) {
        perform_sequence(input);
        print_cube();
    }
}
