#pragma once


enum class EntityType : int {
    item                   =       0x40,
    tnt                    =       0x41,
    falling_block          =       0x42,
    moving_block           =       0x43,
    xp_orb                 =       0x45,
    eye_of_ender_signal    =       0x46,
    ender_crystal          =       0x47,
    fireworks_rocket       =       0x48,
    fishing_hook           =       0x4d,
    chalkboard             =       0x4e,
    painting               =       0x53,
    leash_knot             =       0x58,
    boat                   =       0x5a,
    lightning_bolt         =       0x5d,
    area_effect_cloud      =       0x5f,
    balloon                =       0x6b,
    shield                 =       0x75,
    npc                    =      0x133,
    agent                  =      0x138,
    armor_stand            =      0x13d,
    tripod_camera          =      0x13e,
    player                 =      0x13f,
    bee                    =      0x17a,
    piglin                 =      0x17b,
    piglin_brute           =      0x17f,
    iron_golem             =      0x314,
    snow_golem             =      0x315,
    wandering_trader       =      0x376,
    creeper                =      0xb21,
    slime                  =      0xb25,
    enderman               =      0xb26,
    ghast                  =      0xb29,
    magma_cube             =      0xb2a,
    blaze                  =      0xb2b,
    witch                  =      0xb2d,
    guardian               =      0xb31,
    elder_guardian         =      0xb32,
    ender_dragon           =      0xb35,
    shulker                =      0xb36,
    vindicator             =      0xb39,
    ravager                =      0xb3b,
    evocation_illager      =      0xb68,
    vex                    =      0xb69,
    pillager               =      0xb72,
    elder_guardian_ghost   =      0xb78,
    chicken                =     0x130a,
    cow                    =     0x130b,
    pig                    =     0x130c,
    sheep                  =     0x130d,
    mooshroom              =     0x1310,
    rabbit                 =     0x1312,
    polar_bear             =     0x131c,
    llama                  =     0x131d,
    turtle                 =     0x134a,
    panda                  =     0x1371,
    fox                    =     0x1379,
    hoglin                 =     0x137c,
    strider                =     0x137d,
    goat                   =     0x1380,
    axolotl                =     0x1382,
    squid                  =     0x2311,
    dolphin                =     0x231f,
    pufferfish             =     0x236c,
    salmon                 =     0x236d,
    tropicalfish           =     0x236f,
    cod                    =     0x2370,
    glow_squid             =     0x2381,
    wolf                   =     0x530e,
    ocelot                 =     0x5316,
    parrot                 =     0x531e,
    cat                    =     0x534b,
    bat                    =     0x8113,
    zombie_pigman          =    0x10b24,
    wither                 =    0x10b34,
    phantom                =    0x10b3a,
    zoglin                 =    0x10b7e,
    zombie                 =    0x30b20,
    zombie_villager        =    0x30b2c,
    husk                   =    0x30b2f,
    drowned                =    0x30b6e,
    zombie_villager_v2     =    0x30b74,
    spider                 =    0x40b23,
    silverfish             =    0x40b27,
    cave_spider            =    0x40b28,
    endermite              =    0x40b37,
    minecart               =    0x80054,
    hopper_minecart        =    0x80060,
    tnt_minecart           =    0x80061,
    chest_minecart         =    0x80062,
    command_block_minecart =    0x80064,
    skeleton               =   0x110b22,
    stray                  =   0x110b2e,
    wither_skeleton        =   0x110b30,
    horse                  =   0x205317,
    donkey                 =   0x205318,
    mule                   =   0x205319,
    skeleton_horse         =   0x215b1a,
    zombie_horse           =   0x215b1b,
    xp_bottle              =   0x400044,
    shulker_bullet         =   0x40004c,
    dragon_fireball        =   0x40004f,
    snowball               =   0x400051,
    egg                    =   0x400052,
    fireball               =   0x400055,
    splash_potion          =   0x400056,
    ender_pearl            =   0x400057,
    wither_skull           =   0x400059,
    wither_skull_dangerous =   0x40005b,
    small_fireball         =   0x40005e,
    lingering_potion       =   0x400065,
    llama_spit             =   0x400066,
    evocation_fang         =   0x400067,
    ice_bomb               =   0x40006a,
    thrown_trident         =   0xc00049,
    arrow                  =   0xc00050,
    villager               =  0x100030f,
    villager_v2            =  0x1000373,
};

/*
type : 4938,     namespace : minecraft, name : turtle,                 alias : ,                       fullname : minecraft:turtle
type : 4874,     namespace : minecraft, name : chicken,                alias : ,                       fullname : minecraft:chicken
type : 378,      namespace : minecraft, name : bee,                    alias : ,                       fullname : minecraft:bee
type : 4994,     namespace : minecraft, name : axolotl,                alias : ,                       fullname : minecraft:axolotl
type : 4876,     namespace : minecraft, name : pig,                    alias : ,                       fullname : minecraft:pig
type : 4988,     namespace : minecraft, name : hoglin,                 alias : ,                       fullname : minecraft:hoglin
type : 264995,   namespace : minecraft, name : spider,                 alias : ,                       fullname : minecraft:spider
type : 68478,    namespace : minecraft, name : zoglin,                 alias : ,                       fullname : minecraft:zoglin
type : 21323,    namespace : minecraft, name : cat,                    alias : ,                       fullname : minecraft:cat
type : 70,       namespace : minecraft, name : eye_of_ender_signal,    alias : eyeofender,             fullname : minecraft:eye_of_ender_signal
type : 4875,     namespace : minecraft, name : cow,                    alias : ,                       fullname : minecraft:cow
type : 4877,     namespace : minecraft, name : sheep,                  alias : ,                       fullname : minecraft:sheep
type : 21262,    namespace : minecraft, name : wolf,                   alias : ,                       fullname : minecraft:wolf
type : 12582985, namespace : minecraft, name : thrown_trident,         alias : ,                       fullname : minecraft:thrown_trident
type : 16777999, namespace : minecraft, name : villager,               alias : ,                       fullname : minecraft:villager
type : 16778099, namespace : minecraft, name : villager_v2,            alias : ,                       fullname : minecraft:villager_v2
type : 2870,     namespace : minecraft, name : shulker,                alias : ,                       fullname : minecraft:shulker
type : 886,      namespace : minecraft, name : wandering_trader,       alias : ,                       fullname : minecraft:wandering_trader
type : 4880,     namespace : minecraft, name : mooshroom,              alias : mushroomcow,            fullname : minecraft:mooshroom
type : 8977,     namespace : minecraft, name : squid,                  alias : ,                       fullname : minecraft:squid
type : 9089,     namespace : minecraft, name : glow_squid,             alias : ,                       fullname : minecraft:glow_squid
type : 4989,     namespace : minecraft, name : strider,                alias : ,                       fullname : minecraft:strider
type : 4882,     namespace : minecraft, name : rabbit,                 alias : ,                       fullname : minecraft:rabbit
type : 33043,    namespace : minecraft, name : bat,                    alias : ,                       fullname : minecraft:bat
type : 788,      namespace : minecraft, name : iron_golem,             alias : irongolem,              fullname : minecraft:iron_golem
type : 4194372,  namespace : minecraft, name : xp_bottle,              alias : potion.experience,      fullname : minecraft:xp_bottle
type : 2861,     namespace : minecraft, name : witch,                  alias : ,                       fullname : minecraft:witch
type : 789,      namespace : minecraft, name : snow_golem,             alias : snowgolem,              fullname : minecraft:snow_golem
type : 21270,    namespace : minecraft, name : ocelot,                 alias : ,                       fullname : minecraft:ocelot
type : 2118423,  namespace : minecraft, name : horse,                  alias : ,                       fullname : minecraft:horse
type : 2869,     namespace : minecraft, name : ender_dragon,           alias : dragon,                 fullname : minecraft:ender_dragon
type : 4893,     namespace : minecraft, name : llama,                  alias : ,                       fullname : minecraft:llama
type : 4892,     namespace : minecraft, name : polar_bear,             alias : polarbear,              fullname : minecraft:polar_bear
type : 21278,    namespace : minecraft, name : parrot,                 alias : ,                       fullname : minecraft:parrot
type : 8991,     namespace : minecraft, name : dolphin,                alias : ,                       fullname : minecraft:dolphin
type : 2865,     namespace : minecraft, name : guardian,               alias : ,                       fullname : minecraft:guardian
type : 4977,     namespace : minecraft, name : panda,                  alias : ,                       fullname : minecraft:panda
type : 4985,     namespace : minecraft, name : fox,                    alias : ,                       fullname : minecraft:fox
type : 199471,   namespace : minecraft, name : husk,                   alias : ,                       fullname : minecraft:husk
type : 9071,     namespace : minecraft, name : tropicalfish,           alias : ,                       fullname : minecraft:tropicalfish
type : 1116976,  namespace : minecraft, name : wither_skeleton,        alias : skeleton.wither,        fullname : minecraft:wither_skeleton
type : 4992,     namespace : minecraft, name : goat,                   alias : ,                       fullname : minecraft:goat
type : 9072,     namespace : minecraft, name : cod,                    alias : ,                       fullname : minecraft:cod
type : 199468,   namespace : minecraft, name : zombie_villager,        alias : zombievillager,         fullname : minecraft:zombie_villager
type : 9068,     namespace : minecraft, name : pufferfish,             alias : ,                       fullname : minecraft:pufferfish
type : 9069,     namespace : minecraft, name : salmon,                 alias : ,                       fullname : minecraft:salmon
type : 2118424,  namespace : minecraft, name : donkey,                 alias : ,                       fullname : minecraft:donkey
type : 2118425,  namespace : minecraft, name : mule,                   alias : ,                       fullname : minecraft:mule
type : 2186010,  namespace : minecraft, name : skeleton_horse,         alias : skeletonhorse,          fullname : minecraft:skeleton_horse
type : 2186011,  namespace : minecraft, name : zombie_horse,           alias : zombiehorse,            fullname : minecraft:zombie_horse
type : 199456,   namespace : minecraft, name : zombie,                 alias : ,                       fullname : minecraft:zombie
type : 1116974,  namespace : minecraft, name : stray,                  alias : skeleton.stray,         fullname : minecraft:stray
type : 199534,   namespace : minecraft, name : drowned,                alias : ,                       fullname : minecraft:drowned
type : 2849,     namespace : minecraft, name : creeper,                alias : ,                       fullname : minecraft:creeper
type : 1116962,  namespace : minecraft, name : skeleton,               alias : ,                       fullname : minecraft:skeleton
type : 68388,    namespace : minecraft, name : zombie_pigman,          alias : pig_zombie,             fullname : minecraft:zombie_pigman
type : 2853,     namespace : minecraft, name : slime,                  alias : ,                       fullname : minecraft:slime
type : 2854,     namespace : minecraft, name : enderman,               alias : ,                       fullname : minecraft:enderman
type : 264999,   namespace : minecraft, name : silverfish,             alias : ,                       fullname : minecraft:silverfish
type : 265000,   namespace : minecraft, name : cave_spider,            alias : cavespider,             fullname : minecraft:cave_spider
type : 2857,     namespace : minecraft, name : ghast,                  alias : ,                       fullname : minecraft:ghast
type : 2858,     namespace : minecraft, name : magma_cube,             alias : magmacube,              fullname : minecraft:magma_cube
type : 4194398,  namespace : minecraft, name : small_fireball,         alias : fireball.small,         fullname : minecraft:small_fireball
type : 2859,     namespace : minecraft, name : blaze,                  alias : ,                       fullname : minecraft:blaze
type : 68404,    namespace : minecraft, name : wither,                 alias : wither.boss,            fullname : minecraft:wither
type : 199540,   namespace : minecraft, name : zombie_villager_v2,     alias : ,                       fullname : minecraft:zombie_villager_v2
type : 2866,     namespace : minecraft, name : elder_guardian,         alias : guardian.elder,         fullname : minecraft:elder_guardian
type : 2936,     namespace : minecraft, name : elder_guardian_ghost,   alias : guardian.elderghost,    fullname : minecraft:elder_guardian_ghost
type : 265015,   namespace : minecraft, name : endermite,              alias : ,                       fullname : minecraft:endermite
type : 64,       namespace : minecraft, name : item,                   alias : ,                       fullname : minecraft:item
type : 2873,     namespace : minecraft, name : vindicator,             alias : ,                       fullname : minecraft:vindicator
type : 2920,     namespace : minecraft, name : evocation_illager,      alias : evocationillager,       fullname : minecraft:evocation_illager
type : 2921,     namespace : minecraft, name : vex,                    alias : vex,                    fullname : minecraft:vex
type : 68410,    namespace : minecraft, name : phantom,                alias : ,                       fullname : minecraft:phantom
type : 2930,     namespace : minecraft, name : pillager,               alias : ,                       fullname : minecraft:pillager
type : 2875,     namespace : minecraft, name : ravager,                alias : ,                       fullname : minecraft:ravager
type : 383,      namespace : minecraft, name : piglin_brute,           alias : ,                       fullname : minecraft:piglin_brute
type : 379,      namespace : minecraft, name : piglin,                 alias : ,                       fullname : minecraft:piglin
type : 319,      namespace : minecraft, name : player,                 alias : ,                       fullname : minecraft:player
type : 524372,   namespace : minecraft, name : minecart,               alias : ,                       fullname : minecraft:minecart
type : 524384,   namespace : minecraft, name : hopper_minecart,        alias : minecarthopper,         fullname : minecraft:hopper_minecart
type : 524385,   namespace : minecraft, name : tnt_minecart,           alias : minecarttnt,            fullname : minecraft:tnt_minecart
type : 524386,   namespace : minecraft, name : chest_minecart,         alias : minecartchest,          fullname : minecraft:chest_minecart
type : 524388,   namespace : minecraft, name : command_block_minecart, alias : commandblockminecart,   fullname : minecraft:command_block_minecart
type : 65,       namespace : minecraft, name : tnt,                    alias : primedtnt,              fullname : minecraft:tnt
type : 66,       namespace : minecraft, name : falling_block,          alias : fallingblock,           fullname : minecraft:falling_block
type : 67,       namespace : minecraft, name : moving_block,           alias : movingblock,            fullname : minecraft:moving_block
type : 69,       namespace : minecraft, name : xp_orb,                 alias : xporb,                  fullname : minecraft:xp_orb
type : 71,       namespace : minecraft, name : ender_crystal,          alias : endercrystal,           fullname : minecraft:ender_crystal
type : 4194380,  namespace : minecraft, name : shulker_bullet,         alias : shulkerbullet,          fullname : minecraft:shulker_bullet
type : 77,       namespace : minecraft, name : fishing_hook,           alias : fishinghook,            fullname : minecraft:fishing_hook
type : 4194383,  namespace : minecraft, name : dragon_fireball,        alias : fireball.dragon,        fullname : minecraft:dragon_fireball
type : 12582992, namespace : minecraft, name : arrow,                  alias : arrow.skeleton,         fullname : minecraft:arrow
type : 4194385,  namespace : minecraft, name : snowball,               alias : ,                       fullname : minecraft:snowball
type : 4194386,  namespace : minecraft, name : egg,                    alias : thrownegg,              fullname : minecraft:egg
type : 83,       namespace : minecraft, name : painting,               alias : ,                       fullname : minecraft:painting
type : 117,      namespace : minecraft, name : shield,                 alias : ,                       fullname : minecraft:shield
type : 4194389,  namespace : minecraft, name : fireball,               alias : fireball.large,         fullname : minecraft:fireball
type : 4194390,  namespace : minecraft, name : splash_potion,          alias : thrownpotion,           fullname : minecraft:splash_potion
type : 4194391,  namespace : minecraft, name : ender_pearl,            alias : thrownenderpearl,       fullname : minecraft:ender_pearl
type : 88,       namespace : minecraft, name : leash_knot,             alias : leashknot,              fullname : minecraft:leash_knot
type : 4194393,  namespace : minecraft, name : wither_skull,           alias : wither.skull,           fullname : minecraft:wither_skull
type : 4194395,  namespace : minecraft, name : wither_skull_dangerous, alias : wither.skull.dangerous, fullname : minecraft:wither_skull_dangerous
type : 90,       namespace : minecraft, name : boat,                   alias : ,                       fullname : minecraft:boat
type : 93,       namespace : minecraft, name : lightning_bolt,         alias : lightningbolt,          fullname : minecraft:lightning_bolt
type : 4194406,  namespace : minecraft, name : llama_spit,             alias : llama.spit,             fullname : minecraft:llama_spit
type : 95,       namespace : minecraft, name : area_effect_cloud,      alias : areaeffectcloud,        fullname : minecraft:area_effect_cloud
type : 4194405,  namespace : minecraft, name : lingering_potion,       alias : lingeringpotion,        fullname : minecraft:lingering_potion
type : 4194407,  namespace : minecraft, name : evocation_fang,         alias : evocationfang,          fullname : minecraft:evocation_fang
type : 317,      namespace : minecraft, name : armor_stand,            alias : armorstand,             fullname : minecraft:armor_stand
type : 72,       namespace : minecraft, name : fireworks_rocket,       alias : ,                       fullname : minecraft:fireworks_rocket
type : 312,      namespace : minecraft, name : agent,                  alias : ,                       fullname : minecraft:agent
type : 4194410,  namespace : minecraft, name : ice_bomb,               alias : thrownicebomb,          fullname : minecraft:ice_bomb
type : 107,      namespace : minecraft, name : balloon,                alias : ,                       fullname : minecraft:balloon
type : 78,       namespace : minecraft, name : chalkboard,             alias : ,                       fullname : minecraft:chalkboard
type : 307,      namespace : minecraft, name : npc,                    alias : ,                       fullname : minecraft:npc
type : 318,      namespace : minecraft, name : tripod_camera,          alias : tripodcamera,           fullname : minecraft:tripod_camera
*/