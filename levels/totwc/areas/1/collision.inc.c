#include "surface_terrains.h"

const Collision totwc_seg7_collision[] = {
    COL_INIT(),
    COL_VERTEX_INIT(44),
    // Spawn Plaza (0-3)
    COL_VERTEX(-4500, 2800,  1000),
    COL_VERTEX(-3500, 2800,  1000),
    COL_VERTEX(-3500, 2800, -1000),
    COL_VERTEX(-4500, 2800, -1000),

    // Platform A (4-7)
    COL_VERTEX(-3400, 2100,  200),
    COL_VERTEX(-3000, 2100,  200),
    COL_VERTEX(-3000, 2100, -200),
    COL_VERTEX(-3400, 2100, -200),

    // Platform B (8-11)
    COL_VERTEX(-2400, 1400,  200),
    COL_VERTEX(-2000, 1400,  200),
    COL_VERTEX(-2000, 1400, -200),
    COL_VERTEX(-2400, 1400, -200),

    // Platform C (12-15)
    COL_VERTEX(-1400,  500,  200),
    COL_VERTEX(-1000,  500,  200),
    COL_VERTEX(-1000,  500, -200),
    COL_VERTEX(-1400,  500, -200),

    // Wind Garden (16-19)
    COL_VERTEX(-1000, 0,  1000),
    COL_VERTEX( 1000, 0,  1000),
    COL_VERTEX( 1000, 0, -1000),
    COL_VERTEX(-1000, 0, -1000),

    // Gatehouse Base (20-23)
    COL_VERTEX(2000, 1000,  500),
    COL_VERTEX(3000, 1000,  500),
    COL_VERTEX(3000, 1000, -500),
    COL_VERTEX(2000, 1000, -500),

    // Gatehouse Mid (24-27)
    COL_VERTEX(2000, 2000,  500),
    COL_VERTEX(3000, 2000,  500),
    COL_VERTEX(3000, 2000, -500),
    COL_VERTEX(2000, 2000, -500),

    // Gatehouse Summit (28-31)
    COL_VERTEX(2000, 3000,  500),
    COL_VERTEX(3000, 3000,  500),
    COL_VERTEX(3000, 3000, -500),
    COL_VERTEX(2000, 3000, -500),

    // Great Bridge (32-35)
    COL_VERTEX(1000, 1500,  2500),
    COL_VERTEX(3500, 1500,  2500),
    COL_VERTEX(3500, 1500,  2000),
    COL_VERTEX(1000, 1500,  2000),

    // Secret Cliffside Ledge (36-39)
    COL_VERTEX(-1500, -800, -1500),
    COL_VERTEX(-500,  -800, -1500),
    COL_VERTEX(-500,  -800, -2500),
    COL_VERTEX(-1500, -800, -2500),

    // Sky Ring Cloud Platform (40-43)
    COL_VERTEX(3500, 3500, -3500),
    COL_VERTEX(4500, 3500, -3500),
    COL_VERTEX(4500, 3500, -4500),
    COL_VERTEX(3500, 3500, -4500),

    COL_TRI_INIT(SURFACE_DEFAULT, 22),
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

    COL_TRI(24, 25, 26),
    COL_TRI(24, 26, 27),

    COL_TRI(28, 29, 30),
    COL_TRI(28, 30, 31),

    COL_TRI(32, 33, 34),
    COL_TRI(32, 34, 35),

    COL_TRI(36, 37, 38),
    COL_TRI(36, 38, 39),

    COL_TRI(40, 41, 42),
    COL_TRI(40, 42, 43),

    COL_TRI_STOP(),
    COL_END()
};
