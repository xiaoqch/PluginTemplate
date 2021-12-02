// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include <MC/HashedString.hpp>
#include <LoggerAPI.h>
//#include <MC/SimulatedPlayer.hpp>
#pragma comment(lib, "../../LiteLoaderBDS/LiteLoader/Lib/bedrock_server_api.lib")
#pragma comment(lib, "../../LiteLoaderBDS/LiteLoader/Lib/bedrock_server_var.lib")
#pragma comment(lib, "../../LiteLoaderBDS/LiteLoader/Lib/SymDBHelper.lib")


void entry();

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" {
    _declspec(dllexport) void onPostInit() {
        std::ios::sync_with_stdio(false);
        entry();
    }
}
struct _ActorMapping {
    std::string nameSpace;//0
    std::string name;//32
    std::string alias;
    HashedString fullname;
};
enum class _ActorTypeNamespaceRules : int {
    NameWithNamespace = 0,
    NameWithoutNamespace = 1,
};
static_assert(sizeof(_ActorMapping) == 18 * 8);
void exportActorType() {
    std::unordered_map<int, _ActorMapping> ENTITY_TYPE_MAP = *(std::unordered_map<int, _ActorMapping>*)dlsym_real("?ENTITY_TYPE_MAP@@3V?$unordered_map@W4ActorType@@UActorMapping@@U?$hash@W4ActorType@@@std@@U?$equal_to@W4ActorType@@@4@V?$allocator@U?$pair@$$CBW4ActorType@@UActorMapping@@@std@@@4@@std@@A");
    //Logger::Log("{:{}");
    std::cout << "enum class EntityType : int \u007b" << std::endl;
    int maxWidth = 0;
    std::map<int, _ActorMapping> tmp;
    std::transform(ENTITY_TYPE_MAP.begin(), ENTITY_TYPE_MAP.end(), std::inserter(tmp, tmp.begin()),
        [](std::pair<int, _ActorMapping> a) { return a; });
    for (auto& [type, mapping] : tmp) {
        if (mapping.name.size() > maxWidth)
            maxWidth = mapping.name.size();
    }
    for (auto& [type, mapping] : tmp) {
        //Logger::Log("type: {}, namespace: {}, name: {}, alias: {}, fullname: {}",
        //    type, mapping.nameSpace, mapping.name, mapping.alias, mapping.fullname.getString());
        Logger::Log("    {:"+std::to_string(maxWidth)+"s} = {:#10x},", mapping.name, type);
    }
    //Logger::Log("\u007d;");
    std::cout << "\u007d;" << std::endl;;

}

#define TestGetBlock(liquid, solidOnly, ignoreBorderBlocks, fullOnly)\
FaceID face;\
auto bli = getBlockFromViewVector(face, liquid, solidOnly, 20, false, fullOnly);\
Logger::Info("liquid: {}, solidOnly: {} -> {}, face: {}",liquid, solidOnly, !bli.isNull() ? bli.getBlock()->buildDescriptionName() : "nullptr", (int)face);
static bool logpos = false;
#define TestGetPos(location, unkf)\
Logger::Info("location: {:2}, unkf: {} -> {}",location, unkf, getAttachPos(location, unkf).toString());

//bool dbg = true;
//TInstanceHook(void, "?swing@Mob@@UEAAXXZ", Mob) {
//    if (dbg && isPlayer()) {
//        auto pos = getCameraPos();
//        teleport(pos, 1-getDimensionId());
//        return;
//        logpos = true;
//        //((SimulatedPlayer*)this)->simulateInteract();
//        for (int i = -1; i < 9; i++) {
//            //TestGetPos(i, 0);
//        }
//        //Logger::Info("getCameraOffset() -> {}",getCameraOffset());
//        //auto aabb = *(AABB*)&getAABBShapeComponent();
//        //Logger::Info("height -> {}", aabb.p2.y-aabb.p1.y);
//        auto actor = getActorFromViewVector(100);
//        logpos = false;
//        //Logger::Info("actor: {}, UniqueID: {}", actor ? actor->getNameTag() : "nullptr", actor ? actor->getUniqueID().id:0);
//        //((SimulatedPlayer*)this)->simulateAttack();
//        for (long i = 0; i < 4; ++i) {
//            TestGetBlock(_bittest(&i, 0), _bittest(&i, 1), true, false);
//        }
//    }
//    //Event::addEventListener([](RegCmdEV ev) {
//    //    ev.CMDRg
//    //    });
//    //auto bl = getBlockFromViewVector();
//    //Logger::Info("name: {}", bl->getName().getString());
//}

//TInstanceHook(Block const&, "?getBlock@BlockSource@@UEBAAEBVBlock@@AEBVBlockPos@@@Z", BlockSource, BlockPos& bpos) {
//    //auto bl = getBlockFromViewVector();
//    //Logger::Info("name: {}", bl->getName().getString());
//    //std::cout << bpos.toString() << std::endl;
//    auto& rtn = original(this, bpos);
//    auto name = rtn.buildDescriptionName();
//    //std::cout << rtn.buildDescriptionName() << std::endl;
//    return rtn;
//}
//TInstanceHook(Block const&, "?getBlock@BlockSource@@UEBAAEBVBlock@@HHH@Z", BlockSource, BlockPos& bpos) {
//    //auto bl = getBlockFromViewVector();
//    //Logger::Info("name: {}", bl->getName().getString());
//    //std::cout << bpos.toString() << std::endl;
//    auto& rtn = original(this, bpos);
//    auto name = rtn.buildDescriptionName();
//    //std::cout << name << std::endl;
//    return rtn;
//}

//TInstanceHook(Vec3, "?getAttachPos@Player@@UEBA?AVVec3@@W4ActorLocation@@M@Z", Player, int location, float unk) {
//    //auto bl = getBlockFromViewVector();
//    //Logger::Info("name: {}", bl->getName().getString());
//    //std::cout << bpos.toString() << std::endl;
//    if (!logpos)
//        return original(this, location, unk);
//    Logger::Info("location: {}, unk: {}", location, unk);
//    auto rtn = original(this, location, unk);
//    Logger::Info("location: {}, unk: {} -> pos: {}", location, unk, rtn.toString());
//    //std::cout << name << std::endl;
//    return rtn;
//}

//THook(void, "?searchActors@HitDetection@@YAXAEBVVec3@@M0AEBVAABB@@PEAVActor@@PEAVPlayer@@AEAMAEAPEAV4@AEAV2@_N@Z",
//    class Vec3 const& viewVec, float maxDistance, class Vec3 const& pos, class AABB const& aabb, class Actor* actor, class Player* player, 
//    float& distance, class Actor*& result, class Vec3& v3, bool b) {
//    Logger::Info("viewVec: {}, maxDistance: {}, viewPos: {}", const_cast<Vec3&>(viewVec).toString(), maxDistance, const_cast<Vec3&>(pos).toString());
//    Logger::Info("aabb: {} {}, actor: {}, player: {}", const_cast<Vec3&>(aabb.p1).toString(), const_cast<Vec3&>(aabb.p2).toString(),actor->getNameTag(), player->getNameTag());
//    Logger::Info("distance: {}, result: {}, v3: {}, b: {}", distance, result ? result->getNameTag() : "None", v3.toString(), b);
//    original(viewVec, maxDistance, pos, aabb, actor, player, distance, result, v3, b);
//    Logger::Info("distance: {}, result: {}, v3: {}, b: {}", distance, result?result->getNameTag():"None", v3.toString(), b);
//
//}

//#include <EventAPI.h>
//THook(bool, "?playerWillDestroy@BlockLegacy@@UEBA_NAEAVPlayer@@AEBVBlockPos@@AEBVBlock@@@Z",
//    BlockLegacy* _this, Player& pl, BlockPos& blkpos, Block& bl) {
//    PlayerDestroyEV player_destroy_event = { &pl, blkpos, &bl };
//    auto bs = &pl.getRegion();
//    BlockPos bp = BlockPos{
//        0, 1, 0 };
//    //const Block& blk1 = bs->getBlock(0, 1, 0);
//    const Block& blk1 = VirtualCall<const Block&>(bs, 6 * 8, bp);
//    std::cout << blk1.buildDescriptionName() << std::endl;
//    //const Block& blk2 = bs->getBlock(bp);
//    const Block& blk2 = VirtualCall<const Block&>(bs, 7 * 8, 0, 1, 0);
//    std::cout << blk2.buildDescriptionName() << std::endl;
//    const Block& blk3 = SymCall("?getBlock@BlockSource@@UEBAAEBVBlock@@HHH@Z",
//        const Block&,
//        BlockSource*, int, int, int)(bs, 0, 1, 0);
//    std::cout << blk3.buildDescriptionName() << std::endl;
//    const Block& blk4 = SymCall("?getBlock@BlockSource@@UEBAAEBVBlock@@AEBVBlockPos@@@Z",
//        const Block&,
//        BlockSource*, const BlockPos&)(bs, bp);
//    std::cout << blk4.buildDescriptionName() << std::endl;
//    __int64 base = (__int64)GetModuleHandle(NULL);
//    __int64 fn1 = (__int64)dlsym("?getBlock@BlockSource@@UEBAAEBVBlock@@HHH@Z");
//    __int64 fn2 = (__int64)dlsym("?getBlock@BlockSource@@UEBAAEBVBlock@@AEBVBlockPos@@@Z");
//    __int64 fn3 = ((__int64*)*(void**)bs)[6]; //virtual class Block const& getBlock(int, int, int);
//    __int64 fn4 = ((__int64*)*(void**)bs)[7]; //virtual class Block const& getBlock(class BlockPos const&);
//    std::cout << std::hex << "Base:" << base << std::endl
//        << "fn1 :" << fn1 << std::endl
//        << "fn2 :" << fn2 << std::endl
//        << "fn3 :" << fn3 << std::endl
//        << "fn4 :" << fn4 << std::endl;
//    return original(_this, pl, blkpos, bl);
//}
