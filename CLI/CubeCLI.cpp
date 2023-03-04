#include "CubeCLI.h"
#include <iostream>
#include <sstream>
#include <array>

CubeCLI::CubeCLI() {
    cube = Cube();

    surfaceColormap = {'W', 'O', 'G', 'R', 'B', 'Y'};

    cornerColormap = {
            {ULB, {surfaceColormap[U_SURFACE], surfaceColormap[L_SURFACE], surfaceColormap[B_SURFACE]}},
            {UFL, {surfaceColormap[U_SURFACE], surfaceColormap[F_SURFACE], surfaceColormap[L_SURFACE]}},
            {UBR, {surfaceColormap[U_SURFACE], surfaceColormap[B_SURFACE], surfaceColormap[R_SURFACE]}},
            {URF, {surfaceColormap[U_SURFACE], surfaceColormap[R_SURFACE], surfaceColormap[F_SURFACE]}},
            {DBL, {surfaceColormap[D_SURFACE], surfaceColormap[B_SURFACE], surfaceColormap[L_SURFACE]}},
            {DLF, {surfaceColormap[D_SURFACE], surfaceColormap[L_SURFACE], surfaceColormap[F_SURFACE]}},
            {DRB, {surfaceColormap[D_SURFACE], surfaceColormap[R_SURFACE], surfaceColormap[B_SURFACE]}},
            {DFR, {surfaceColormap[D_SURFACE], surfaceColormap[F_SURFACE], surfaceColormap[R_SURFACE]}},
    };

    edgeColormap = {
            {UL, {surfaceColormap[U_SURFACE], surfaceColormap[L_SURFACE]}},
            {UR, {surfaceColormap[U_SURFACE], surfaceColormap[R_SURFACE]}},
            {UF, {surfaceColormap[U_SURFACE], surfaceColormap[F_SURFACE]}},
            {UB, {surfaceColormap[U_SURFACE], surfaceColormap[B_SURFACE]}},
            {DL, {surfaceColormap[D_SURFACE], surfaceColormap[L_SURFACE]}},
            {DR, {surfaceColormap[D_SURFACE], surfaceColormap[R_SURFACE]}},
            {DF, {surfaceColormap[D_SURFACE], surfaceColormap[F_SURFACE]}},
            {DB, {surfaceColormap[D_SURFACE], surfaceColormap[B_SURFACE]}},
            {FL, {surfaceColormap[F_SURFACE], surfaceColormap[L_SURFACE]}},
            {FR, {surfaceColormap[F_SURFACE], surfaceColormap[R_SURFACE]}},
            {BL, {surfaceColormap[B_SURFACE], surfaceColormap[L_SURFACE]}},
            {BR, {surfaceColormap[B_SURFACE], surfaceColormap[R_SURFACE]}},
    };
}

void CubeCLI::print_cube(const Cube& cube) {
    typedef std::array<std::array<char, 3>, 3> surface_matrix;
    surface_matrix up;
    surface_matrix down;
    surface_matrix left;
    surface_matrix right;
    surface_matrix front;
    surface_matrix back;

    // paint centers
    up[1][1] = surfaceColormap[U_SURFACE];
    down[1][1] = surfaceColormap[D_SURFACE];
    left[1][1] = surfaceColormap[L_SURFACE];
    right[1][1] = surfaceColormap[R_SURFACE];
    front[1][1] = surfaceColormap[F_SURFACE];
    back[1][1] = surfaceColormap[B_SURFACE];

    // paint edges
    std::tie(up[0][1], back[0][1]) = get_edge_colors(UB, cube);
    std::tie(up[1][0], left[0][1]) = get_edge_colors(UL, cube);
    std::tie(up[1][2], right[0][1]) = get_edge_colors(UR, cube);
    std::tie(up[2][1], front[0][1]) = get_edge_colors(UF, cube);
    std::tie(down[0][1], front[2][1]) = get_edge_colors(DF, cube);
    std::tie(down[1][0], left[2][1]) = get_edge_colors(DL, cube);
    std::tie(down[1][2], right[2][1]) = get_edge_colors(DR, cube);
    std::tie(down[2][1], back[2][1]) = get_edge_colors(DB, cube);
    std::tie(back[1][2], left[1][0]) = get_edge_colors(BL, cube);
    std::tie(front[1][0], left[1][2]) = get_edge_colors(FL, cube);
    std::tie(front[1][2], right[1][0]) = get_edge_colors(FR, cube);
    std::tie(back[1][0], right[1][2]) = get_edge_colors(BR, cube);

    // paint corners
    std::tie(up[0][0], left[0][0], back[0][2]) = get_corner_colors(ULB, cube);
    std::tie(up[0][2], back[0][0], right[0][2]) = get_corner_colors(UBR, cube);
    std::tie(up[2][0], front[0][0], left[0][2]) = get_corner_colors(UFL, cube);
    std::tie(up[2][2], right[0][0], front[0][2]) = get_corner_colors(URF, cube);
    std::tie(down[0][0], left[2][2], front[2][0]) = get_corner_colors(DLF, cube);
    std::tie(down[0][2], front[2][2], right[2][0]) = get_corner_colors(DFR, cube);
    std::tie(down[2][0], back[2][2], left[2][0]) = get_corner_colors(DBL, cube);
    std::tie(down[2][2], right[2][2], back[2][0]) = get_corner_colors(DRB, cube);

    printf("\n-------------------------------------------------------\n"
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
           "        %c %c %c\n"
           "-------------------------------------------------------\n",
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

std::tuple<char, char> CubeCLI::get_edge_colors(E_POS position, const Cube& cube) {
    EdgeCubie edge = cube.getEdge(position);
    std::array<char, 2> colors = edgeColormap[static_cast<E_POS>(edge.get_original_id())];

    return std::make_tuple(
            colors[edge.get_twist_state()],
            colors[(edge.get_twist_state() + 1) % 2]
            );
}

std::tuple<char, char, char> CubeCLI::get_corner_colors(C_POS position, const Cube& cube) {
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

void CubeCLI::loop() {
    std::string input;
    print_cube();
    while (std::cin >> input) {
        SequenceParser::perform_sequence(cube, input);
        print_cube();
    }
}

void CubeCLI::print_cube() {
    print_cube(cube);
}

