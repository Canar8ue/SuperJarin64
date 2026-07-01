#include <ultra64.h>
#include "sm64.h"

// Attic Landing Vertices (0-3)
static const Vtx hazy_castle_vtx_attic[] = {
    {{{ -500, 1000,  500}, 0, {0, 0}, {0x40, 0x40, 0x44, 0xFF}}},
    {{{  500, 1000,  500}, 0, {0, 0}, {0x40, 0x40, 0x44, 0xFF}}},
    {{{  500, 1000, -500}, 0, {0, 0}, {0x40, 0x40, 0x44, 0xFF}}},
    {{{ -500, 1000, -500}, 0, {0, 0}, {0x40, 0x40, 0x44, 0xFF}}},
};

// Walkway Vertices (4-7)
static const Vtx hazy_castle_vtx_rooftop_walkway[] = {
    {{{ -100, 1000,  2500}, 0, {0, 0}, {0x30, 0x30, 0x33, 0xFF}}},
    {{{  100, 1000,  2500}, 0, {0, 0}, {0x30, 0x30, 0x33, 0xFF}}},
    {{{  100, 1000,   500}, 0, {0, 0}, {0x30, 0x30, 0x33, 0xFF}}},
    {{{ -100, 1000,   500}, 0, {0, 0}, {0x30, 0x30, 0x33, 0xFF}}},
};

// Tower Base Vertices (8-11)
static const Vtx hazy_castle_vtx_tower_base[] = {
    {{{ -500, 1000,  3500}, 0, {0, 0}, {0x2C, 0x2C, 0x30, 0xFF}}},
    {{{  500, 1000,  3500}, 0, {0, 0}, {0x2C, 0x2C, 0x30, 0xFF}}},
    {{{  500, 1000,  2500}, 0, {0, 0}, {0x2C, 0x2C, 0x30, 0xFF}}},
    {{{ -500, 1000,  2500}, 0, {0, 0}, {0x2C, 0x2C, 0x30, 0xFF}}},
};

// Tower Step 1 Vertices (12-15)
static const Vtx hazy_castle_vtx_tower_step1[] = {
    {{{ -300, 1400,  3300}, 0, {0, 0}, {0x80, 0x68, 0x28, 0xFF}}},
    {{{  300, 1400,  3300}, 0, {0, 0}, {0x80, 0x68, 0x28, 0xFF}}},
    {{{  300, 1400,  2700}, 0, {0, 0}, {0x80, 0x68, 0x28, 0xFF}}},
    {{{ -300, 1400,  2700}, 0, {0, 0}, {0x80, 0x68, 0x28, 0xFF}}},
};

// Tower Step 2 Vertices (16-19)
static const Vtx hazy_castle_vtx_tower_step2[] = {
    {{{ -150, 1800,  3150}, 0, {0, 0}, {0x80, 0x68, 0x28, 0xFF}}},
    {{{  150, 1800,  3150}, 0, {0, 0}, {0x80, 0x68, 0x28, 0xFF}}},
    {{{  150, 1800,  2850}, 0, {0, 0}, {0x80, 0x68, 0x28, 0xFF}}},
    {{{ -150, 1800,  2850}, 0, {0, 0}, {0x80, 0x68, 0x28, 0xFF}}},
};

// Tower Spire Summit Vertices (20-23)
static const Vtx hazy_castle_vtx_spire_summit[] = {
    {{{ -80,  2200,  3080}, 0, {0, 0}, {0xB0, 0x90, 0x30, 0xFF}}},
    {{{  80,  2200,  3080}, 0, {0, 0}, {0xB0, 0x90, 0x30, 0xFF}}},
    {{{  80,  2200,  2920}, 0, {0, 0}, {0xB0, 0x90, 0x30, 0xFF}}},
    {{{ -80,  2200,  2920}, 0, {0, 0}, {0xB0, 0x90, 0x30, 0xFF}}},
};

const Gfx hazy_castle_dl_area_3[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),

    // Attic Landing
    gsSPVertex(hazy_castle_vtx_attic, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    // Walkway
    gsSPVertex(hazy_castle_vtx_rooftop_walkway, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    // Tower Base
    gsSPVertex(hazy_castle_vtx_tower_base, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    // Step 1
    gsSPVertex(hazy_castle_vtx_tower_step1, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    // Step 2
    gsSPVertex(hazy_castle_vtx_tower_step2, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    // Spire Summit
    gsSPVertex(hazy_castle_vtx_spire_summit, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    gsSPEndDisplayList(),
};
