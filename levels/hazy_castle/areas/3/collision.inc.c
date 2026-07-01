#include "surface_terrains.h"

const Collision hazy_castle_collision_area_3[] = {
    COL_INIT(),
    COL_VERTEX_INIT(24),
    // Attic Landing (0-3)
    COL_VERTEX(-500, 1000,  500),
    COL_VERTEX( 500, 1000,  500),
    COL_VERTEX( 500, 1000, -500),
    COL_VERTEX(-500, 1000, -500),

    // Walkway (4-7)
    COL_VERTEX(-100, 1000,  2500),
    COL_VERTEX( 100, 1000,  2500),
    COL_VERTEX( 100, 1000,   500),
    COL_VERTEX(-100, 1000,   500),

    // Tower Base (8-11)
    COL_VERTEX(-500, 1000,  3500),
    COL_VERTEX( 500, 1000,  3500),
    COL_VERTEX( 500, 1000,  2500),
    COL_VERTEX(-500, 1000,  2500),

    // Tower Step 1 (12-15)
    COL_VERTEX(-300, 1400,  3300),
    COL_VERTEX( 300, 1400,  3300),
    COL_VERTEX( 300, 1400,  2700),
    COL_VERTEX(-300, 1400,  2700),

    // Tower Step 2 (16-19)
    COL_VERTEX(-150, 1800,  3150),
    COL_VERTEX( 150, 1800,  3150),
    COL_VERTEX( 150, 1800,  2850),
    COL_VERTEX(-150, 1800,  2850),

    // Highest Spire Summit (20-23)
    COL_VERTEX(-80,  2200,  3080),
    COL_VERTEX( 80,  2200,  3080),
    COL_VERTEX( 80,  2200,  2920),
    COL_VERTEX(-80,  2200,  2920),

    COL_TRI_INIT(SURFACE_DEFAULT, 12),
    COL_TRI(0, 1, 2),
    COL_TRI(0, 2, 3),

    COL_TRI(4, 5, 6),
    COL_TRI(4, 6, 7),

    COL_TRI(8, 9, 10),
    COL_TRI(8, 10, 11),

    COL_TRI(12, 13, 14),
    COL_TRI(12, 14, 15),

    COL_TRI(16, 17, 18),
    COL_TRI(16, 18, 19),

    COL_TRI(20, 21, 22),
    COL_TRI(20, 22, 23),

    COL_TRI_STOP(),
    COL_END()
};
