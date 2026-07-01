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
#include "levels/totwc/header.h"

static const LevelScript script_func_local_1[] = {
    // Guide NPCs
    OBJECT(/*model*/ MODEL_BOBOMB_BUDDY, /*pos*/ -3800, 2800,  200, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM2(DIALOG_132), /*bhv*/ bhvBobombBuddy),
    OBJECT(/*model*/ MODEL_TOAD,         /*pos*/  -500,    0,  500, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(DIALOG_140), /*bhv*/ bhvToadMessage),
    OBJECT(/*model*/ MODEL_BOBOMB_BUDDY, /*pos*/  1200, 1500, 2100, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM2(DIALOG_147), /*bhv*/ bhvBobombBuddy),

    // Enemies
    OBJECT(/*model*/ MODEL_GOOMBA, /*pos*/ -3200, 2100, 0, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvGoomba),
    OBJECT(/*model*/ MODEL_GOOMBA, /*pos*/ -2200, 1400, 0, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvGoomba),

    // Wing Cap Box
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX, /*pos*/ -4000, 2900, 0, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM2(0), /*bhv*/ bhvExclamationBox),

    // Red Coins (8 total)
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/ -4000, 2900,  -500, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/ -3200, 2200,   100, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/ -2200, 1500,  -100, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/ -1200,  600,   100, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/     0,  100,     0, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/  2500, 1100,     0, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/  2500, 2100,     0, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/  4000, 3600, -4000, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),

    // Poles
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ 2500, 1000, 0, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM2(100), /*bhv*/ bhvPoleGrabbing),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ 2500, 2000, 0, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM2(100), /*bhv*/ bhvPoleGrabbing),

    // Stars
    OBJECT(/*model*/ MODEL_STAR,       /*pos*/  2500, 3300,     0, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(STAR_INDEX_ACT_1), /*bhv*/ bhvStar),
    OBJECT(/*model*/ MODEL_STAR,       /*pos*/ -1000, -700, -2000, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(STAR_INDEX_ACT_3), /*bhv*/ bhvStar),
    OBJECT(/*model*/ MODEL_BULLY_BOSS, /*pos*/  2500, 1550,  2250, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(STAR_INDEX_ACT_4), /*bhv*/ bhvBigBully),

    // Warp to Area 2 Dungeon (Z=2250, X=1050)
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ 1050, 1500, 2250, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(10) | BPARAM2(WARP_NODE_0B), /*bhv*/ bhvWarp),

    // Recover Heart
    OBJECT(/*model*/ MODEL_HEART, /*pos*/ -800, -800, -1800, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRecoveryHeart),

    RETURN(),
};

static const LevelScript script_func_local_2[] = {
    // Red Coin Star
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(STAR_INDEX_ACT_2), /*bhv*/ bhvHiddenRedCoinStar),
    RETURN(),
};

static const LevelScript script_func_local_3[] = {
    // Dungeon Traps
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ -1000, 0, 2000, /*angle*/ 0,   0, 0, /*bhvParam*/ 0, /*bhv*/ bhvFlamethrower),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ -1000, 0, 3000, /*angle*/ 0,   0, 0, /*bhvParam*/ 0, /*bhv*/ bhvFlamethrower),

    // Dungeon Shifting Elevator
    OBJECT(/*model*/ MODEL_CHECKERBOARD_PLATFORM, /*pos*/ 0, 0, 4500, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(0) | BPARAM2(60), /*bhv*/ bhvCheckerboardElevatorGroup),

    // Star 5 (Treasure Vault)
    OBJECT(/*model*/ MODEL_STAR, /*pos*/ 0, 800, 6500, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(STAR_INDEX_ACT_5), /*bhv*/ bhvStar),

    // Star 6 Secrets
    OBJECT(/*model*/ MODEL_NONE, /*pos*/     0, 200, 4500, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(STAR_INDEX_ACT_6) | BPARAM2(5), /*bhv*/ bhvHiddenStar),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ -1300,  50, -1300, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvHiddenStarTrigger),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/  1300,  50, -1300, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvHiddenStarTrigger),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ -1800,  50,  5000, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvHiddenStarTrigger),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/  1800,  50,  5000, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvHiddenStarTrigger),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/     0, 800,  7000, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvHiddenStarTrigger),

    RETURN(),
};

const LevelScript level_totwc_entry[] = {
    INIT_LEVEL(),
    LOAD_MIO0        (/*seg*/ 0x07, _totwc_segment_7SegmentRomStart, _totwc_segment_7SegmentRomEnd),
    LOAD_MIO0        (/*seg*/ 0x0A, _cloud_floor_skybox_mio0SegmentRomStart, _cloud_floor_skybox_mio0SegmentRomEnd),
    LOAD_MIO0_TEXTURE(/*seg*/ 0x09, _generic_mio0SegmentRomStart, _generic_mio0SegmentRomEnd),
    LOAD_MIO0        (/*seg*/ 0x05, _group2_mio0SegmentRomStart, _group2_mio0SegmentRomEnd),
    LOAD_RAW         (/*seg*/ 0x0C, _group2_geoSegmentRomStart,  _group2_geoSegmentRomEnd),
    LOAD_MIO0        (/*seg*/ 0x06, _group16_mio0SegmentRomStart, _group16_mio0SegmentRomEnd),
    LOAD_RAW         (/*seg*/ 0x0D, _group16_geoSegmentRomStart,  _group16_geoSegmentRomEnd),
    LOAD_MIO0        (/*seg*/ 0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
    LOAD_RAW         (/*seg*/ 0x0F, _common0_geoSegmentRomStart,  _common0_geoSegmentRomEnd),
    ALLOC_LEVEL_POOL(),
    MARIO(/*model*/ MODEL_MARIO, /*bhvParam*/ BPARAM4(0x01), /*bhv*/ bhvMario),
    JUMP_LINK(script_func_global_1),
    JUMP_LINK(script_func_global_3),
    JUMP_LINK(script_func_global_16),

    // Area 1: Forest Exterior
    AREA(/*index*/ 1, totwc_geo_000188),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/ -4095, 2935, 0, /*angle*/ 0, 90, 0, /*bhvParam*/ BPARAM2(WARP_NODE_0A), /*bhv*/ bhvAirborneWarp),
        
        WARP_NODE(/*id*/ WARP_NODE_0A,         /*destLevel*/ LEVEL_TOTWC,  /*destArea*/ 1, /*destNode*/ WARP_NODE_0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_0B,         /*destLevel*/ LEVEL_TOTWC,  /*destArea*/ 2, /*destNode*/ WARP_NODE_0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_WARP_FLOOR, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 1, /*destNode*/ WARP_NODE_23, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_SUCCESS,    /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 1, /*destNode*/ WARP_NODE_26, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_DEATH,      /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 1, /*destNode*/ WARP_NODE_23, /*flags*/ WARP_NO_CHECKPOINT),
        
        JUMP_LINK(script_func_local_2),
        JUMP_LINK(script_func_local_1),
        TERRAIN(/*terrainData*/ totwc_seg7_collision),
        MACRO_OBJECTS(/*objList*/ totwc_seg7_macro_objs),
        SHOW_DIALOG(/*index*/ 0x00, DIALOG_131),
        SET_BACKGROUND_MUSIC(/*settingsPreset*/ 0x0000, /*seq*/ SEQ_LEVEL_GRASS),
        TERRAIN_TYPE(/*terrainType*/ TERRAIN_GRASS),
    END_AREA(),

    // Area 2: Dungeon Sub-Level
    AREA(/*index*/ 2, totwc_geo_area_2),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/ -1000, 100, -1000, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM2(WARP_NODE_0A), /*bhv*/ bhvAirborneWarp),

        WARP_NODE(/*id*/ WARP_NODE_0A,         /*destLevel*/ LEVEL_TOTWC,  /*destArea*/ 2, /*destNode*/ WARP_NODE_0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_WARP_FLOOR, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 1, /*destNode*/ WARP_NODE_23, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_SUCCESS,    /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 1, /*destNode*/ WARP_NODE_26, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_DEATH,      /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 1, /*destNode*/ WARP_NODE_23, /*flags*/ WARP_NO_CHECKPOINT),

        JUMP_LINK(script_func_local_3),
        TERRAIN(/*terrainData*/ totwc_seg7_collision_area_2),
        MACRO_OBJECTS(/*objList*/ totwc_seg7_macro_objs_area_2),
        SET_BACKGROUND_MUSIC(/*settingsPreset*/ 0x0004, /*seq*/ SEQ_LEVEL_UNDERGROUND),
        TERRAIN_TYPE(/*terrainType*/ TERRAIN_STONE),
    END_AREA(),

    FREE_LEVEL_POOL(),
    MARIO_POS(/*area*/ 1, /*yaw*/ 90, /*pos*/ -4095, 2935, 0),
    CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
    CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
    CLEAR_LEVEL(),
    SLEEP_BEFORE_EXIT(/*frames*/ 1),
    EXIT(),
};
