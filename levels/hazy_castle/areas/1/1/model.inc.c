#include <ultra64.h>
#include "sm64.h"

// Spawn Clearing Floor Vertices (0-3)
static const Vtx hazy_castle_vtx_forest_spawn[] = {
    {{{ -3000, 0,  1000}, 0, {0, 0}, {0x18, 0x40, 0x18, 0xFF}}},
    {{{ -1000, 0,  1000}, 0, {0, 0}, {0x18, 0x40, 0x18, 0xFF}}},
    {{{ -1000, 0, -1000}, 0, {0, 0}, {0x18, 0x40, 0x18, 0xFF}}},
    {{{ -3000, 0, -1000}, 0, {0, 0}, {0x18, 0x40, 0x18, 0xFF}}},
};

// Graveyard Floor Vertices (4-7)
static const Vtx hazy_castle_vtx_graveyard[] = {
    {{{ -1000, -400, -1000}, 0, {0, 0}, {0x38, 0x2C, 0x20, 0xFF}}},
    {{{  1000, -400, -1000}, 0, {0, 0}, {0x38, 0x2C, 0x20, 0xFF}}},
    {{{  1000, -400, -3000}, 0, {0, 0}, {0x38, 0x2C, 0x20, 0xFF}}},
    {{{ -1000, -400, -3000}, 0, {0, 0}, {0x38, 0x2C, 0x20, 0xFF}}},
};

// Castle Gates Yard Vertices (8-11)
static const Vtx hazy_castle_vtx_gates_yard[] = {
    {{{ 1000, 200,  1000}, 0, {0, 0}, {0x40, 0x40, 0x48, 0xFF}}},
    {{{ 3000, 200,  1000}, 0, {0, 0}, {0x40, 0x40, 0x48, 0xFF}}},
    {{{ 3000, 200, -1000}, 0, {0, 0}, {0x40, 0x40, 0x48, 0xFF}}},
    {{{ 1000, 200, -1000}, 0, {0, 0}, {0x40, 0x40, 0x48, 0xFF}}},
};

// Ramp Vertices (12-15)
static const Vtx hazy_castle_vtx_forest_ramp[] = {
    {{{ -1000,   0,  500}, 0, {0, 0}, {0x28, 0x38, 0x20, 0xFF}}},
    {{{  1000, 200,  500}, 0, {0, 0}, {0x28, 0x38, 0x20, 0xFF}}},
    {{{  1000, 200, -500}, 0, {0, 0}, {0x28, 0x38, 0x20, 0xFF}}},
    {{{ -1000,   0, -500}, 0, {0, 0}, {0x28, 0x38, 0x20, 0xFF}}},
};

const Gfx hazy_castle_dl_area_1[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),

    // Spawn Clearing
    gsSPVertex(hazy_castle_vtx_forest_spawn, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    // Graveyard
    gsSPVertex(hazy_castle_vtx_graveyard, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    // Gates Yard
    gsSPVertex(hazy_castle_vtx_gates_yard, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    // Ramp
    gsSPVertex(hazy_castle_vtx_forest_ramp, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    gsSPEndDisplayList(),
};
