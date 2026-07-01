#include "surface_terrains.h"

const Collision hazy_castle_collision_area_2[] = {
    COL_INIT(),
    COL_VERTEX_INIT(16),
    // Great Hall Floor (0-3)
    COL_VERTEX(-1500, 0,  1500),
    COL_VERTEX( 1500, 0,  1500),
    COL_VERTEX( 1500, 0, -1500),
    COL_VERTEX(-1500, 0, -1500),

    // Library Floor (4-7)
    COL_VERTEX(-1500, 0,  4500),
    COL_VERTEX( 1500, 0,  4500),
    COL_VERTEX( 1500, 0,  1500),
    COL_VERTEX(-1500, 0,  1500),

    // Bookshelf Platform (8-11)
    COL_VERTEX(-1500, 300,  3500),
    COL_VERTEX(-1000, 300,  3500),
    COL_VERTEX(-1000, 300,  2500),
    COL_VERTEX(-1500, 300,  2500),

    // Basement Room Floor (12-15)
    COL_VERTEX(-1500, -500, -1500),
    COL_VERTEX( 1500, -500, -1500),
    COL_VERTEX( 1500, -500, -4500),
    COL_VERTEX(-1500, -500, -4500),

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
