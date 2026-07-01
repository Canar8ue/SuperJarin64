#include "surface_terrains.h"

const Collision totwc_seg7_collision_area_2[] = {
    COL_INIT(),
    COL_VERTEX_INIT(24),
    // Floor vertices
    COL_VERTEX(-1500, 0, 1500),   // 0
    COL_VERTEX(1500, 0, 1500),    // 1
    COL_VERTEX(1500, 0, -1500),   // 2
    COL_VERTEX(-1500, 0, -1500),  // 3

    COL_VERTEX(-400, 0, 3500),    // 4
    COL_VERTEX(400, 0, 3500),     // 5
    COL_VERTEX(400, 0, 1500),     // 6
    COL_VERTEX(-400, 0, 1500),    // 7

    COL_VERTEX(-2000, 0, 5500),   // 8
    COL_VERTEX(2000, 0, 5500),    // 9
    COL_VERTEX(2000, 0, 3500),    // 10
    COL_VERTEX(-2000, 0, 3500),   // 11

    COL_VERTEX(-1500, 600, 7500), // 12
    COL_VERTEX(1500, 600, 7500),  // 13
    COL_VERTEX(1500, 600, 5500),  // 14
    COL_VERTEX(-1500, 600, 5500), // 15

    COL_VERTEX(-300, 600, 5500),  // 16
    COL_VERTEX(300, 600, 5500),   // 17
    COL_VERTEX(300, 0, 5300),     // 18
    COL_VERTEX(-300, 0, 5300),    // 19

    // Wall vertices
    COL_VERTEX(-1500, 800, -1500), // 20
    COL_VERTEX(1500, 800, -1500),  // 21
    COL_VERTEX(-1500, 800, 1500),  // 22
    COL_VERTEX(1500, 800, 1500),   // 23

    COL_TRI_INIT(SURFACE_DEFAULT, 16),
    // Entry floor
    COL_TRI(0, 1, 2),
    COL_TRI(0, 2, 3),
    // Corridor floor
    COL_TRI(4, 5, 6),
    COL_TRI(4, 6, 7),
    // Puzzle floor
    COL_TRI(8, 9, 10),
    COL_TRI(8, 10, 11),
    // Vault floor
    COL_TRI(12, 13, 14),
    COL_TRI(12, 14, 15),
    // Ramp
    COL_TRI(16, 17, 18),
    COL_TRI(16, 18, 19),
    // Back wall
    COL_TRI(3, 2, 21),
    COL_TRI(3, 21, 20),
    // Left wall
    COL_TRI(0, 3, 20),
    COL_TRI(0, 20, 22),
    // Right wall
    COL_TRI(2, 1, 23),
    COL_TRI(2, 23, 21),
    COL_TRI_STOP(),
    COL_END()
};
