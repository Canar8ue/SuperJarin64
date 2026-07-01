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
    // === Spawn Platform & Starting Ramp ===
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/ -4095, 2800, 0, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,    /*pos*/ -4000, 2900, 0, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM2(0), /*bhv*/ bhvExclamationBox), // Wing Cap Box
    
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/ -3200, 2100, 0, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/ -2200, 1400, 0, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/ -1200,  -600, 0, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/  -300, -1800, 0, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),

    // === Central Tower & Cap Switch ===
    OBJECT(/*model*/ MODEL_CAP_SWITCH, /*pos*/ 0, -2047, 10, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvCapSwitch),
    OBJECT(/*model*/ MODEL_CHECKERBOARD_PLATFORM, /*pos*/ 0, -2047, 200, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(0) | BPARAM2(20), /*bhv*/ bhvCheckerboardElevatorGroup),
    OBJECT(/*model*/ MODEL_GOOMBA, /*pos*/ -200, -1842, 200, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvGoomba),
    OBJECT(/*model*/ MODEL_GOOMBA, /*pos*/  200, -1842, -200, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvGoomba),

    // === Southeast Diagonal Bridge (Climbing from Y=-1842 to Y=1024) ===
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/  800, -1400,  800, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/ 1600,  -900, 1600, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/ 2400,  -400, 2400, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/ 3200,   100, 3200, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/ 4000,   600, 4000, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_GOOMBA,            /*pos*/ 3200,   200, 3200, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvGoomba),

    // === Southeast Tower Lower & Upper Deck ===
    OBJECT(/*model*/ MODEL_CHECKERBOARD_PLATFORM, /*pos*/ 4096, 1024, 4096, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(0) | BPARAM2(100), /*bhv*/ bhvCheckerboardElevatorGroup),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,       /*pos*/ 4096, 2150, 4096, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM2(3), /*bhv*/ bhvExclamationBox), // Koopa Shell Box

    // === Shell Surf Wave Clouds (Connecting 4096 to -4096) ===
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/  2800, 1800, 4096, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/  1600, 1500, 4096, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/     0, 1200, 4096, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/ -1600, 1500, 4096, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/ -2800, 1800, 4096, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_HEART,                 /*pos*/     0, 1300, 4096, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRecoveryHeart),

    // === Southwest to Northwest Bridge Clouds ===
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/ -4096, 2048,  2700, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/ -4096, 2048,  1400, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_GOOMBA,            /*pos*/ -4096, 2150,  1400, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvGoomba),
    
    // Moving Checkerboard Platform in the middle gap
    OBJECT(/*model*/ MODEL_CHECKERBOARD_PLATFORM, /*pos*/ -4096, 2048, 0, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(0) | BPARAM2(50), /*bhv*/ bhvCheckerboardElevatorGroup),
    
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/ -4096, 2048, -1400, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_GOOMBA,            /*pos*/ -4096, 2150, -1400, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvGoomba),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/ -4096, 2048, -2700, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),

    // === Northwest to Northeast Bridge Clouds (Climbing 2048 to 3994) ===
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/ -2800, 2400, -4096, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/ -1600, 2800, -4096, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/     0, 3200, -4096, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/  1600, 3500, -4096, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/  2800, 3700, -4096, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvStaticObject),
    
    OBJECT(/*model*/ MODEL_GOOMBA,            /*pos*/ -1600, 2900, -4096, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvGoomba),
    OBJECT(/*model*/ MODEL_GOOMBA,            /*pos*/  1600, 3600, -4096, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvGoomba),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,   /*pos*/     0, 3300, -4096, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM2(7), /*bhv*/ bhvExclamationBox), // 1UP Box

    // === Northeast Tower Summit Star ===
    OBJECT(/*model*/ MODEL_STAR, /*pos*/ 4096, 4300, -4096, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(STAR_INDEX_ACT_2), /*bhv*/ bhvStar),

    // === 8 Red Coins Placement ===
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/   800, -1300,   800, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/  2400,  -300,  2400, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/  4096,  1100,  4096, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/  2800,  1900,  4096, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/ -2800,  1900,  4096, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/ -4096,  2150, -4096, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/ -1600,  2900, -4096, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN, /*pos*/  2800,  3800, -4096, /*angle*/ 0, 0, 0, /*bhvParam*/ 0, /*bhv*/ bhvRedCoin),

    RETURN(),
};

static const LevelScript script_func_local_2[] = {
    // Red Coin Star
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ 800, -1700, 0, /*angle*/ 0, 0, 0, /*bhvParam*/ BPARAM1(STAR_INDEX_ACT_1), /*bhv*/ bhvHiddenRedCoinStar),
    RETURN(),
};

const LevelScript level_totwc_entry[] = {
    INIT_LEVEL(),
    LOAD_MIO0        (/*seg*/ 0x07, _totwc_segment_7SegmentRomStart, _totwc_segment_7SegmentRomEnd),
    LOAD_MIO0        (/*seg*/ 0x0A, _cloud_floor_skybox_mio0SegmentRomStart, _cloud_floor_skybox_mio0SegmentRomEnd),
    LOAD_MIO0_TEXTURE(/*seg*/ 0x09, _sky_mio0SegmentRomStart, _sky_mio0SegmentRomEnd),
    LOAD_MIO0        (/*seg*/ 0x05, _group8_mio0SegmentRomStart, _group8_mio0SegmentRomEnd),
    LOAD_RAW         (/*seg*/ 0x0C, _group8_geoSegmentRomStart,  _group8_geoSegmentRomEnd),
    LOAD_MIO0        (/*seg*/ 0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
    LOAD_RAW         (/*seg*/ 0x0F, _common0_geoSegmentRomStart,  _common0_geoSegmentRomEnd),
    ALLOC_LEVEL_POOL(),
    MARIO(/*model*/ MODEL_MARIO, /*bhvParam*/ BPARAM4(0x01), /*bhv*/ bhvMario),
    JUMP_LINK(script_func_global_1),
    JUMP_LINK(script_func_global_9),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, totwc_geo_000160),

    AREA(/*index*/ 1, totwc_geo_000188),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/ -4095, 2935, 0, /*angle*/ 0, 90, 0, /*bhvParam*/ BPARAM2(WARP_NODE_0A), /*bhv*/ bhvFlyingWarp),
        
        WARP_NODE(/*id*/ WARP_NODE_0A,         /*destLevel*/ LEVEL_TOTWC,  /*destArea*/ 1, /*destNode*/ WARP_NODE_0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_WARP_FLOOR, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 1, /*destNode*/ WARP_NODE_20, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_SUCCESS,    /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 1, /*destNode*/ WARP_NODE_26, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_DEATH,      /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 1, /*destNode*/ WARP_NODE_23, /*flags*/ WARP_NO_CHECKPOINT),
        
        JUMP_LINK(script_func_local_2),
        JUMP_LINK(script_func_local_1),
        TERRAIN(/*terrainData*/ totwc_seg7_collision),
        MACRO_OBJECTS(/*objList*/ totwc_seg7_macro_objs),
        SHOW_DIALOG(/*index*/ 0x00, DIALOG_131),
        SET_BACKGROUND_MUSIC(/*settingsPreset*/ 0x0000, /*seq*/ SEQ_LEVEL_SLIDE),
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
