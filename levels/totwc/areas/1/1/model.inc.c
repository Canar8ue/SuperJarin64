#include <ultra64.h>
#include "sm64.h"

// Spawn Plaza vertices (0-3) - Grass Green
static const Vtx totwc_vtx_spawn_plaza[] = {
    {{{ -4500, 2800,  1000}, 0, {0, 0}, {0x20, 0x60, 0x20, 0xFF}}},
    {{{ -3500, 2800,  1000}, 0, {0, 0}, {0x20, 0x60, 0x20, 0xFF}}},
    {{{ -3500, 2800, -1000}, 0, {0, 0}, {0x20, 0x60, 0x20, 0xFF}}},
    {{{ -4500, 2800, -1000}, 0, {0, 0}, {0x20, 0x60, 0x20, 0xFF}}},
};

// Platform A vertices (4-7) - Wooden Brown
static const Vtx totwc_vtx_platform_a[] = {
    {{{ -3400, 2100,  200}, 0, {0, 0}, {0x70, 0x40, 0x20, 0xFF}}},
    {{{ -3000, 2100,  200}, 0, {0, 0}, {0x70, 0x40, 0x20, 0xFF}}},
    {{{ -3000, 2100, -200}, 0, {0, 0}, {0x70, 0x40, 0x20, 0xFF}}},
    {{{ -3400, 2100, -200}, 0, {0, 0}, {0x70, 0x40, 0x20, 0xFF}}},
};

// Platform B vertices (8-11) - Wooden Brown
static const Vtx totwc_vtx_platform_b[] = {
    {{{ -2400, 1400,  200}, 0, {0, 0}, {0x70, 0x40, 0x20, 0xFF}}},
    {{{ -2000, 1400,  200}, 0, {0, 0}, {0x70, 0x40, 0x20, 0xFF}}},
    {{{ -2000, 1400, -200}, 0, {0, 0}, {0x70, 0x40, 0x20, 0xFF}}},
    {{{ -2400, 1400, -200}, 0, {0, 0}, {0x70, 0x40, 0x20, 0xFF}}},
};

// Platform C vertices (12-15) - Wooden Brown
static const Vtx totwc_vtx_platform_c[] = {
    {{{ -1400,  500,  200}, 0, {0, 0}, {0x70, 0x40, 0x20, 0xFF}}},
    {{{ -1000,  500,  200}, 0, {0, 0}, {0x70, 0x40, 0x20, 0xFF}}},
    {{{ -1000,  500, -200}, 0, {0, 0}, {0x70, 0x40, 0x20, 0xFF}}},
    {{{ -1400,  500, -200}, 0, {0, 0}, {0x70, 0x40, 0x20, 0xFF}}},
};

// Wind Garden vertices (16-19) - Dark Grass/Stone
static const Vtx totwc_vtx_wind_garden[] = {
    {{{ -1000, 0,  1000}, 0, {0, 0}, {0x18, 0x48, 0x18, 0xFF}}},
    {{{  1000, 0,  1000}, 0, {0, 0}, {0x18, 0x48, 0x18, 0xFF}}},
    {{{  1000, 0, -1000}, 0, {0, 0}, {0x18, 0x48, 0x18, 0xFF}}},
    {{{ -1000, 0, -1000}, 0, {0, 0}, {0x18, 0x48, 0x18, 0xFF}}},
};

// Gatehouse Base vertices (20-23) - Brick Red
static const Vtx totwc_vtx_gatehouse_base[] = {
    {{{ 2000, 1000,  500}, 0, {0, 0}, {0x60, 0x30, 0x30, 0xFF}}},
    {{{ 3000, 1000,  500}, 0, {0, 0}, {0x60, 0x30, 0x30, 0xFF}}},
    {{{ 3000, 1000, -500}, 0, {0, 0}, {0x60, 0x30, 0x30, 0xFF}}},
    {{{ 2000, 1000, -500}, 0, {0, 0}, {0x60, 0x30, 0x30, 0xFF}}},
};

// Gatehouse Mid vertices (24-27) - Brick Red
static const Vtx totwc_vtx_gatehouse_mid[] = {
    {{{ 2000, 2000,  500}, 0, {0, 0}, {0x70, 0x38, 0x38, 0xFF}}},
    {{{ 3000, 2000,  500}, 0, {0, 0}, {0x70, 0x38, 0x38, 0xFF}}},
    {{{ 3000, 2000, -500}, 0, {0, 0}, {0x70, 0x38, 0x38, 0xFF}}},
    {{{ 2000, 2000, -500}, 0, {0, 0}, {0x70, 0x38, 0x38, 0xFF}}},
};

// Gatehouse Summit vertices (28-31) - Brick Gold
static const Vtx totwc_vtx_gatehouse_summit[] = {
    {{{ 2000, 3000,  500}, 0, {0, 0}, {0x80, 0x70, 0x30, 0xFF}}},
    {{{ 3000, 3000,  500}, 0, {0, 0}, {0x80, 0x70, 0x30, 0xFF}}},
    {{{ 3000, 3000, -500}, 0, {0, 0}, {0x80, 0x70, 0x30, 0xFF}}},
    {{{ 2000, 3000, -500}, 0, {0, 0}, {0x80, 0x70, 0x30, 0xFF}}},
};

// Great Bridge vertices (32-35) - Stone Gray
static const Vtx totwc_vtx_great_bridge[] = {
    {{{ 1000, 1500,  2500}, 0, {0, 0}, {0x40, 0x40, 0x45, 0xFF}}},
    {{{ 3500, 1500,  2500}, 0, {0, 0}, {0x40, 0x40, 0x45, 0xFF}}},
    {{{ 3500, 1500,  2000}, 0, {0, 0}, {0x40, 0x40, 0x45, 0xFF}}},
    {{{ 1000, 1500,  2000}, 0, {0, 0}, {0x40, 0x40, 0x45, 0xFF}}},
};

// Secret Cliffside vertices (36-39) - Mossy Gray
static const Vtx totwc_vtx_cliffside[] = {
    {{{ -1500, -800, -1500}, 0, {0, 0}, {0x28, 0x38, 0x28, 0xFF}}},
    {{{ -500,  -800, -1500}, 0, {0, 0}, {0x28, 0x38, 0x28, 0xFF}}},
    {{{ -500,  -800, -2500}, 0, {0, 0}, {0x28, 0x38, 0x28, 0xFF}}},
    {{{ -1500, -800, -2500}, 0, {0, 0}, {0x28, 0x38, 0x28, 0xFF}}},
};

// Sky Ring cloud vertices (40-43) - Bright White
static const Vtx totwc_vtx_sky_ring[] = {
    {{{ 3500, 3500, -3500}, 0, {0, 0}, {0xE0, 0xE0, 0xF0, 0xFF}}},
    {{{ 4500, 3500, -3500}, 0, {0, 0}, {0xE0, 0xE0, 0xF0, 0xFF}}},
    {{{ 4500, 3500, -4500}, 0, {0, 0}, {0xE0, 0xE0, 0xF0, 0xFF}}},
    {{{ 3500, 3500, -4500}, 0, {0, 0}, {0xE0, 0xE0, 0xF0, 0xFF}}},
};

const Gfx totwc_seg7_dl_07005D28[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),

    // Spawn Plaza
    gsSPVertex(totwc_vtx_spawn_plaza, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    // Platforms
    gsSPVertex(totwc_vtx_platform_a, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),
    gsSPVertex(totwc_vtx_platform_b, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),
    gsSPVertex(totwc_vtx_platform_c, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    // Wind Garden
    gsSPVertex(totwc_vtx_wind_garden, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    // Gatehouse Towers
    gsSPVertex(totwc_vtx_gatehouse_base, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),
    gsSPVertex(totwc_vtx_gatehouse_mid, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),
    gsSPVertex(totwc_vtx_gatehouse_summit, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    // Great Bridge
    gsSPVertex(totwc_vtx_great_bridge, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    // Secret Cliffside
    gsSPVertex(totwc_vtx_cliffside, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    // Sky Ring
    gsSPVertex(totwc_vtx_sky_ring, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    gsSPEndDisplayList(),
};
