#include <ultra64.h>
#include "sm64.h"

// Great Hall Floor Vertices (0-3)
static const Vtx hazy_castle_vtx_hall[] = {
    {{{ -1500, 0,  1500}, 0, {0, 0}, {0x48, 0x18, 0x48, 0xFF}}},
    {{{  1500, 0,  1500}, 0, {0, 0}, {0x48, 0x18, 0x48, 0xFF}}},
    {{{  1500, 0, -1500}, 0, {0, 0}, {0x48, 0x18, 0x48, 0xFF}}},
    {{{ -1500, 0, -1500}, 0, {0, 0}, {0x48, 0x18, 0x48, 0xFF}}},
};

// Library Floor Vertices (4-7)
static const Vtx hazy_castle_vtx_library[] = {
    {{{ -1500, 0,  4500}, 0, {0, 0}, {0x18, 0x30, 0x20, 0xFF}}},
    {{{  1500, 0,  4500}, 0, {0, 0}, {0x18, 0x30, 0x20, 0xFF}}},
    {{{  1500, 0,  1500}, 0, {0, 0}, {0x18, 0x30, 0x20, 0xFF}}},
    {{{ -1500, 0,  1500}, 0, {0, 0}, {0x18, 0x30, 0x20, 0xFF}}},
};

// Bookshelf Platform Vertices (8-11)
static const Vtx hazy_castle_vtx_bookshelf[] = {
    {{{ -1500, 300,  3500}, 0, {0, 0}, {0x50, 0x30, 0x18, 0xFF}}},
    {{{ -1000, 300,  3500}, 0, {0, 0}, {0x50, 0x30, 0x18, 0xFF}}},
    {{{ -1000, 300,  2500}, 0, {0, 0}, {0x50, 0x30, 0x18, 0xFF}}},
    {{{ -1500, 300,  2500}, 0, {0, 0}, {0x50, 0x30, 0x18, 0xFF}}},
};

// Basement Room Vertices (12-15)
static const Vtx hazy_castle_vtx_basement[] = {
    {{{ -1500, -500, -1500}, 0, {0, 0}, {0x20, 0x30, 0x40, 0xFF}}},
    {{{  1500, -500, -1500}, 0, {0, 0}, {0x20, 0x30, 0x40, 0xFF}}},
    {{{  1500, -500, -4500}, 0, {0, 0}, {0x20, 0x30, 0x40, 0xFF}}},
    {{{ -1500, -500, -4500}, 0, {0, 0}, {0x20, 0x30, 0x40, 0xFF}}},
};

const Gfx hazy_castle_dl_area_2[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),

    // Great Hall
    gsSPVertex(hazy_castle_vtx_hall, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    // Library
    gsSPVertex(hazy_castle_vtx_library, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    // Bookshelf
    gsSPVertex(hazy_castle_vtx_bookshelf, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    // Basement
    gsSPVertex(hazy_castle_vtx_basement, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    gsSPEndDisplayList(),
};
