#include <ultra64.h>
#include "sm64.h"

// Dark stone floor vertices (Entry Room: -1500 to 1500, Z: -1500 to 1500, Y: 0)
static const Vtx totwc_dungeon_entry_floor[] = {
    {{{ -1500, 0,  1500}, 0, {0, 0}, {0x30, 0x30, 0x35, 0xFF}}},
    {{{  1500, 0,  1500}, 0, {0, 0}, {0x30, 0x30, 0x35, 0xFF}}},
    {{{  1500, 0, -1500}, 0, {0, 0}, {0x30, 0x30, 0x35, 0xFF}}},
    {{{ -1500, 0, -1500}, 0, {0, 0}, {0x30, 0x30, 0x35, 0xFF}}},
};

// Dark stone corridor vertices (Z: 1500 to 3500, X: -400 to 400, Y: 0)
static const Vtx totwc_dungeon_corridor_floor[] = {
    {{{ -400, 0,  3500}, 0, {0, 0}, {0x28, 0x28, 0x2C, 0xFF}}},
    {{{  400, 0,  3500}, 0, {0, 0}, {0x28, 0x28, 0x2C, 0xFF}}},
    {{{  400, 0,  1500}, 0, {0, 0}, {0x28, 0x28, 0x2C, 0xFF}}},
    {{{ -400, 0,  1500}, 0, {0, 0}, {0x28, 0x28, 0x2C, 0xFF}}},
};

// Puzzle Chamber floor (Z: 3500 to 5500, X: -2000 to 2000, Y: 0)
static const Vtx totwc_dungeon_puzzle_floor[] = {
    {{{ -2000, 0,  5500}, 0, {0, 0}, {0x20, 0x20, 0x24, 0xFF}}},
    {{{  2000, 0,  5500}, 0, {0, 0}, {0x20, 0x20, 0x24, 0xFF}}},
    {{{  2000, 0,  3500}, 0, {0, 0}, {0x20, 0x20, 0x24, 0xFF}}},
    {{{ -2000, 0,  3500}, 0, {0, 0}, {0x20, 0x20, 0x24, 0xFF}}},
};

// Treasure Vault floor (Z: 5500 to 7500, X: -1500 to 1500, Y: 600)
static const Vtx totwc_dungeon_vault_floor[] = {
    {{{ -1500, 600,  7500}, 0, {0, 0}, {0x40, 0x38, 0x20, 0xFF}}}, // Golden tint
    {{{  1500, 600,  7500}, 0, {0, 0}, {0x40, 0x38, 0x20, 0xFF}}},
    {{{  1500, 600,  5500}, 0, {0, 0}, {0x40, 0x38, 0x20, 0xFF}}},
    {{{ -1500, 600,  5500}, 0, {0, 0}, {0x40, 0x38, 0x20, 0xFF}}},
};

// Ramps / Steps connecting Puzzle Chamber to Treasure Vault (Z: 5300 to 5500, X: -300 to 300, Y: 0 to 600)
static const Vtx totwc_dungeon_ramp[] = {
    {{{ -300, 600,  5500}, 0, {0, 0}, {0x35, 0x35, 0x3B, 0xFF}}},
    {{{  300, 600,  5500}, 0, {0, 0}, {0x35, 0x35, 0x3B, 0xFF}}},
    {{{  300,   0,  5300}, 0, {0, 0}, {0x20, 0x20, 0x24, 0xFF}}},
    {{{ -300,   0,  5300}, 0, {0, 0}, {0x20, 0x20, 0x24, 0xFF}}},
};

// Dungeon Walls (just safety boundaries to make it look like a dungeon)
static const Vtx totwc_dungeon_walls[] = {
    // Entry Room Back Wall (Z = -1500, Y = 0 to 800)
    {{{ -1500,   0, -1500}, 0, {0, 0}, {0x18, 0x18, 0x1F, 0xFF}}},
    {{{  1500,   0, -1500}, 0, {0, 0}, {0x18, 0x18, 0x1F, 0xFF}}},
    {{{  1500, 800, -1500}, 0, {0, 0}, {0x18, 0x18, 0x1F, 0xFF}}},
    {{{ -1500, 800, -1500}, 0, {0, 0}, {0x18, 0x18, 0x1F, 0xFF}}},

    // Entry Room Left Wall (X = -1500, Y = 0 to 800)
    {{{ -1500,   0,  1500}, 0, {0, 0}, {0x18, 0x18, 0x1F, 0xFF}}},
    {{{ -1500,   0, -1500}, 0, {0, 0}, {0x18, 0x18, 0x1F, 0xFF}}},
    {{{ -1500, 800, -1500}, 0, {0, 0}, {0x18, 0x18, 0x1F, 0xFF}}},
    {{{ -1500, 800,  1500}, 0, {0, 0}, {0x18, 0x18, 0x1F, 0xFF}}},

    // Entry Room Right Wall (X = 1500, Y = 0 to 800)
    {{{  1500,   0, -1500}, 0, {0, 0}, {0x18, 0x18, 0x1F, 0xFF}}},
    {{{  1500,   0,  1500}, 0, {0, 0}, {0x18, 0x18, 0x1F, 0xFF}}},
    {{{  1500, 800,  1500}, 0, {0, 0}, {0x18, 0x18, 0x1F, 0xFF}}},
    {{{  1500, 800, -1500}, 0, {0, 0}, {0x18, 0x18, 0x1F, 0xFF}}},
};

const Gfx totwc_seg7_dl_area_2[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),

    // Entry Room Floor
    gsSPVertex(totwc_dungeon_entry_floor, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    // Corridor Floor
    gsSPVertex(totwc_dungeon_corridor_floor, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    // Puzzle Floor
    gsSPVertex(totwc_dungeon_puzzle_floor, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    // Vault Floor
    gsSPVertex(totwc_dungeon_vault_floor, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    // Ramp
    gsSPVertex(totwc_dungeon_ramp, 4, 0),
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),

    // Walls
    gsSPVertex(totwc_dungeon_walls, 12, 0),
    // Back wall
    gsSP2Triangles(0, 1, 2, 0x0, 0, 2, 3, 0x0),
    // Left wall
    gsSP2Triangles(4, 5, 6, 0x0, 4, 6, 7, 0x0),
    // Right wall
    gsSP2Triangles(8, 9, 10, 0x0, 8, 10, 11, 0x0),

    gsSPEndDisplayList(),
};
