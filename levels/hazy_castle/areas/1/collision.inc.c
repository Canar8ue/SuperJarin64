#include "surface_terrains.h"

const Collision hazy_castle_collision_area_1[] = {
    COL_INIT(),
    COL_VERTEX_INIT(16),
    // Spawn Clearing Floor (0-3)
    COL_VERTEX(-3000, 0,  1000),
    COL_VERTEX(-1000, 0,  1000),
    COL_VERTEX(-1000, 0, -1000),
    COL_VERTEX(-3000, 0, -1000),

    // Graveyard Floor (4-7)
    COL_VERTEX(-1000, -400, -1000),
    COL_VERTEX( 1000, -400, -1000),
    COL_VERTEX( 1000, -400, -3000),
    COL_VERTEX(-1000, -400, -3000),

    // Castle Gates Yard Floor (8-11)
    COL_VERTEX(1000, 200,  1000),
    COL_VERTEX(3000, 200,  1000),
    COL_VERTEX(3000, 200, -1000),
    COL_VERTEX(1000, 200, -1000),

    // Ramp connecting Spawn to Gates (12-15)
    COL_VERTEX(-1000,   0,  500),
    COL_VERTEX( 1000, 200,  500),
    COL_VERTEX( 1000, 200, -500),
    COL_VERTEX(-1000,   0, -500),

    COL_TRI_INIT(SURFACE_DEFAULT, 8),
    COL_TRI(0, 1, 2),
    COL_TRI(0, 2, 3),

    COL_TRI(4, 5, 6),
    COL_TRI(4, 6, 7),

    COL_TRI(8, 9, 10),
    COL_TRI(8, 10, 11),

    COL_TRI(12, 13, 14),
    COL_TRI(12, 14, 15),

    COL_TRI_STOP(),
    COL_END()
};
