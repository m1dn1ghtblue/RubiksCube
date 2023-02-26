#include "CubeCLI.h"
#include <iostream>

CubeCLI::CubeCLI() {
    cube = Cube();

    surfaceColormap = {'U', 'L', 'F', 'R', 'B', 'D'};

    cornerColormap = {
            {ULB, {surfaceColormap[U], surfaceColormap[L], surfaceColormap[B]}},
            {ULF, {surfaceColormap[U], surfaceColormap[L], surfaceColormap[F]}},
            {URB, {surfaceColormap[U], surfaceColormap[R], surfaceColormap[B]}},
            {URF, {surfaceColormap[U], surfaceColormap[R], surfaceColormap[F]}},
            {DLB, {surfaceColormap[D], surfaceColormap[L], surfaceColormap[B]}},
            {DLF, {surfaceColormap[D], surfaceColormap[L], surfaceColormap[F]}},
            {DRB, {surfaceColormap[D], surfaceColormap[R], surfaceColormap[B]}},
            {DRF, {surfaceColormap[D], surfaceColormap[R], surfaceColormap[F]}},
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
            {LF, {surfaceColormap[L], surfaceColormap[F]}},
            {RF, {surfaceColormap[R], surfaceColormap[F]}},
            {LB, {surfaceColormap[L], surfaceColormap[B]}},
            {RB, {surfaceColormap[R], surfaceColormap[B]}},
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
    std::tie(left[1][0], back[1][2]) = get_edge_colors(LB);
    std::tie(left[1][2], front[1][0]) = get_edge_colors(LF);
    std::tie(right[1][0], front[1][2]) = get_edge_colors(RF);
    std::tie(right[1][2], back[1][0]) = get_edge_colors(RB);

    // paint corners
    std::tie(up[0][0], left[0][0], back[0][2]) = get_corner_colors(ULB);
    std::tie(up[0][2], right[0][2], back[0][0]) = get_corner_colors(URB);
    std::tie(up[2][0], left[0][2], front[0][0]) = get_corner_colors(ULF);
    std::tie(up[2][2], right[0][0], front[0][2]) = get_corner_colors(URF);
    std::tie(down[0][0], left[2][2], front[2][0]) = get_corner_colors(DLF);
    std::tie(down[0][2], right[2][0], front[2][2]) = get_corner_colors(DRF);
    std::tie(down[2][0], left[2][0], back[2][2]) = get_corner_colors(DLB);
    std::tie(down[2][2], right[2][2], back[2][0]) = get_corner_colors(DRB);

    printf("        %c %c %c\n"
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

    return std::make_tuple(
        colors[corner.get_twist_state()],
        colors[(corner.get_twist_state() + 1) % 3],
        colors[(corner.get_twist_state() + 2) % 3]
    );
}

