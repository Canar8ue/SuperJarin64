#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

#include "make_const_nonconst.h"
#include "levels/hazy_castle/header.h"

static const LevelScript script_func_local_1[] = {
    // Area 1 Guide NPCs
    OBJECT(/*model*/ MODEL_BOBOMB_BUDDY, /*pos*/ -2200,    0,   300, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM2(DIALOG_148), /*bhv*/ bhvBobombBuddy),
    OBJECT(/*model*/ MODEL_BOBOMB_BUDDY, /*pos*/     0, -400, -2000, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM2(DIALOG_149), /*bhv*/ bhvBobombBuddy),

    // Area 1 Enemies
    OBJECT(/*model*/ MODEL_GOOMBA, /*pos*/ -1500, 0,   100, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvGoomba),
    OBJECT(/*model*/ MODEL_GOOMBA, /*pos*/  1800, 200, 100, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvGoomba),

    // Red Coins (8 total, scattered around Graveyard and Spawn)
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/ -2800,  100,  800, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/ -2800,  100, -800, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/  -800, -300, -1200, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/   800, -300, -1200, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/  -800, -300, -2800, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/   800, -300, -2800, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/  2000,  300,  800, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/  2000,  300, -800, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),

    // Star 2 (Friendly Boo's Secret - spawns directly at spawn clearing)
    OBJECT(/*model*/ MODEL_STAR, /*pos*/ -2500, 300, 200, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(STAR_INDEX_ACT_2), /*bhv*/ bhvStar),

    // Mansion Entrance Door Warp (leads to Area 2)
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ 2800, 200, 0, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(10) | BPARAM2(WARP_NODE_0B), /*bhv*/ bhvWarp),

    RETURN(),
};

static const LevelScript script_func_local_2[] = {
    // Red Coin Star (spawns in graveyard)
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ 0, -300, -2000, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(STAR_INDEX_ACT_1), /*bhv*/ bhvHiddenRedCoinStar),
    RETURN(),
};

static const LevelScript script_func_local_3[] = {
    // Area 2 Guide NPC (Toad)
    OBJECT(/*model*/ MODEL_TOAD, /*pos*/ 0, 0, 3000, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(DIALOG_150), /*bhv*/ bhvToadMessage),

    // Star 3 (Ghost of the Library - Big Boo Boss)
    OBJECT(/*model*/ MODEL_BOO, /*pos*/ 0, 100, 3800, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(STAR_INDEX_ACT_3), /*bhv*/ bhvBalconyBigBoo),

    // Star 4 (Dungeon Pool Climb - suspended above pool)
    OBJECT(/*model*/ MODEL_STAR, /*pos*/ 0, -200, -3000, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(STAR_INDEX_ACT_4), /*bhv*/ bhvStar),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ 0, -500, -3000, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM2(200), /*bhv*/ bhvPoleGrabbing),

    // Attic Exit Trapdoor Warp (leads to Area 3)
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ -1250, 300, 3000, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(10) | BPARAM2(WARP_NODE_0B), /*bhv*/ bhvWarp),

    RETURN(),
};

static const LevelScript script_func_local_4[] = {
    // Area 3 Guide NPC
    OBJECT(/*model*/ MODEL_BOBOMB_BUDDY, /*pos*/ 0, 1000, 1500, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM2(DIALOG_151), /*bhv*/ bhvBobombBuddy),

    // Star 5 (Ascent to the Highest Spire)
    OBJECT(/*model*/ MODEL_STAR, /*pos*/ 0, 2400, 3000, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(STAR_INDEX_ACT_5), /*bhv*/ bhvStar),

    // Star 6 (Five Forest Secrets)
    OBJECT(/*model*/ MODEL_NONE, /*pos*/    0, 1200, 1000, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(STAR_INDEX_ACT_6) | BPARAM2(5), /*bhv*/ bhvHiddenStar),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ -400, 1050, -400, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvHiddenStarTrigger),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/  400, 1050, -400, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvHiddenStarTrigger),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/    0, 1050, 3000, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvHiddenStarTrigger),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/    0, 1450, 3000, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvHiddenStarTrigger),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/    0, 1850, 3000, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvHiddenStarTrigger),

    RETURN(),
};

const LevelScript level_hazy_castle_entry[] = {
    INIT_LEVEL(),
    LOAD_MIO0        (/*seg*/ 0x07, _hazy_castle_segment_7SegmentRomStart, _hazy_castle_segment_7SegmentRomEnd),
    LOAD_MIO0        (/*seg*/ 0x0A, _spooky_skybox_mio0SegmentRomStart, _spooky_skybox_mio0SegmentRomEnd),
    LOAD_MIO0_TEXTURE(/*seg*/ 0x09, _generic_mio0SegmentRomStart, _generic_mio0SegmentRomEnd),
    LOAD_MIO0        (/*seg*/ 0x05, _group10_mio0SegmentRomStart, _group10_mio0SegmentRomEnd),
    LOAD_RAW         (/*seg*/ 0x0C, _group10_geoSegmentRomStart,  _group10_geoSegmentRomEnd),
    LOAD_MIO0        (/*seg*/ 0x06, _group16_mio0SegmentRomStart, _group16_mio0SegmentRomEnd),
    LOAD_RAW         (/*seg*/ 0x0D, _group16_geoSegmentRomStart,  _group16_geoSegmentRomEnd),
    LOAD_MIO0        (/*seg*/ 0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
    LOAD_RAW         (/*seg*/ 0x0F, _common0_geoSegmentRomStart,  _common0_geoSegmentRomEnd),
    ALLOC_LEVEL_POOL(),
    MARIO(/*model*/ MODEL_MARIO, /*bhvParam*/ BPARAM4(0x01), /*bhv*/ bhvMario),
    JUMP_LINK(script_func_global_1),
    JUMP_LINK(script_func_global_11),
    JUMP_LINK(script_func_global_16),

    // Area 1: Spooky Forest
    AREA(/*index*/ 1, hazy_castle_geo_area_1),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/ -2500, 100, 0, /*angle*/ 0, 90, 0, /*bhvParam*/ BPARAM2(WARP_NODE_0A), /*bhv*/ bhvAirborneWarp),
        
        WARP_NODE(/*id*/ WARP_NODE_0A,         /*destLevel*/ LEVEL_UNKNOWN_32,       /*destArea*/ 1, /*destNode*/ WARP_NODE_0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_0B,         /*destLevel*/ LEVEL_UNKNOWN_32,       /*destArea*/ 2, /*destNode*/ WARP_NODE_0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_WARP_FLOOR, /*destLevel*/ LEVEL_CASTLE_COURTYARD, /*destArea*/ 1, /*destNode*/ WARP_NODE_0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_SUCCESS,    /*destLevel*/ LEVEL_CASTLE_COURTYARD, /*destArea*/ 1, /*destNode*/ WARP_NODE_0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_DEATH,      /*destLevel*/ LEVEL_CASTLE_COURTYARD, /*destArea*/ 1, /*destNode*/ WARP_NODE_0A, /*flags*/ WARP_NO_CHECKPOINT),
        
        JUMP_LINK(script_func_local_2),
        JUMP_LINK(script_func_local_1),
        TERRAIN(/*terrainData*/ hazy_castle_collision_area_1),
        MACRO_OBJECTS(/*objList*/ hazy_castle_macro_area_1),
        SET_BACKGROUND_MUSIC(/*settingsPreset*/ 0x0000, /*seq*/ SEQ_LEVEL_SPOOKY),
        TERRAIN_TYPE(/*terrainType*/ TERRAIN_GRASS),
    END_AREA(),

    // Area 2: Haunted Castle Interior
    AREA(/*index*/ 2, hazy_castle_geo_area_2),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/ 0, 100, 1000, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM2(WARP_NODE_0A), /*bhv*/ bhvAirborneWarp),
        
        WARP_NODE(/*id*/ WARP_NODE_0A,         /*destLevel*/ LEVEL_UNKNOWN_32,       /*destArea*/ 2, /*destNode*/ WARP_NODE_0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_0B,         /*destLevel*/ LEVEL_UNKNOWN_32,       /*destArea*/ 3, /*destNode*/ WARP_NODE_0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_WARP_FLOOR, /*destLevel*/ LEVEL_CASTLE_COURTYARD, /*destArea*/ 1, /*destNode*/ WARP_NODE_0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_SUCCESS,    /*destLevel*/ LEVEL_CASTLE_COURTYARD, /*destArea*/ 1, /*destNode*/ WARP_NODE_0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_DEATH,      /*destLevel*/ LEVEL_CASTLE_COURTYARD, /*destArea*/ 1, /*destNode*/ WARP_NODE_0A, /*flags*/ WARP_NO_CHECKPOINT),
        
        JUMP_LINK(script_func_local_3),
        TERRAIN(/*terrainData*/ hazy_castle_collision_area_2),
        MACRO_OBJECTS(/*objList*/ hazy_castle_macro_area_2),
        SET_BACKGROUND_MUSIC(/*settingsPreset*/ 0x0000, /*seq*/ SEQ_LEVEL_SPOOKY),
        TERRAIN_TYPE(/*terrainType*/ TERRAIN_STONE),
    END_AREA(),

    // Area 3: Rooftops
    AREA(/*index*/ 3, hazy_castle_geo_area_3),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/ 0, 1100, 0, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM2(WARP_NODE_0A), /*bhv*/ bhvAirborneWarp),
        
        WARP_NODE(/*id*/ WARP_NODE_0A,         /*destLevel*/ LEVEL_UNKNOWN_32,       /*destArea*/ 3, /*destNode*/ WARP_NODE_0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_WARP_FLOOR, /*destLevel*/ LEVEL_CASTLE_COURTYARD, /*destArea*/ 1, /*destNode*/ WARP_NODE_0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_SUCCESS,    /*destLevel*/ LEVEL_CASTLE_COURTYARD, /*destArea*/ 1, /*destNode*/ WARP_NODE_0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_DEATH,      /*destLevel*/ LEVEL_CASTLE_COURTYARD, /*destArea*/ 1, /*destNode*/ WARP_NODE_0A, /*flags*/ WARP_NO_CHECKPOINT),
        
        JUMP_LINK(script_func_local_4),
        TERRAIN(/*terrainData*/ hazy_castle_collision_area_3),
        MACRO_OBJECTS(/*objList*/ hazy_castle_macro_area_3),
        SET_BACKGROUND_MUSIC(/*settingsPreset*/ 0x0000, /*seq*/ SEQ_LEVEL_SLIDE),
        TERRAIN_TYPE(/*terrainType*/ TERRAIN_STONE),
    END_AREA(),

    FREE_LEVEL_POOL(),
    MARIO_POS(/*area*/ 1, /*yaw*/ 90, /*pos*/ -2500, 100, 0),
    CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
    CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
    CLEAR_LEVEL(),
    SLEEP_BEFORE_EXIT(/*frames*/ 1),
    EXIT(),
};
