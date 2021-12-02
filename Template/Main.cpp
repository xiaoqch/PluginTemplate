#include "pch.h"
#include <filesystem>
#include <LLAPI.h>
#include <MC/Level.hpp>
#include <MC/Player.hpp>
#include <LoggerAPI.h>
#include <MC/HashedString.hpp>
#include <MC/Block.hpp>
#include <MC/BlockSource.hpp>
#include <MC/ActorMapping.hpp>
#include <MC/Minecraft.hpp>
#include <MC/NetworkHandler.hpp>
#include <regCommandAPI.h>
#include <EventAPI.h>
#include <regCommandAPI.h>
#include <Utils/FileHelper.h>
#include <MC/CompoundTag.hpp>
#define NbtFileDir "./test/"

bool dynregCommand(CommandOrigin const& ori, CommandOutput& outp, optional<string>& name) {
    string cmdName = name.set ? name.val() : "tpDim";
    bool (*func)(CommandOrigin const& ori, CommandOutput & outp, int dimid, optional<CommandPosition> cmdpos) = [](CommandOrigin const& ori, CommandOutput& outp, int dimid, optional<CommandPosition> cmdpos) -> bool {
        auto actor = const_cast<CommandOrigin&>(ori).getEntity();
        std::unordered_map<int, string> dimensionNameMap = {
            {0, "Overworld"},
            {1, "Nether"},
            {2, "The End"},
        };
        if (!actor) {
            outp.error("");
            return false;
        }
        if (dimid < 0 || dimid > 3) {
            outp.error(fmt::format("Invaild dimid: " + std::to_string(dimid)));
            return false;
        }
        if (cmdpos.set) {
            auto pos = cmdpos.val().getPosition(ori, { 0, 0, 0 });
            actor->teleport(pos, dimid);
            outp.success(fmt::format("Teleported {} to {} ({:2f}, {:2f}, {:2f})",
                actor->getNameTag(), dimensionNameMap[dimid], pos.x, pos.y, pos.z));
        }
        else {
            auto pos = *(Vec3*)&actor->getStateVectorComponent();
            actor->teleport(pos, dimid);
            outp.success(fmt::format("Teleported {} to {} ({:2f}, {:2f}, {:2f})",
                actor->getNameTag(), dimensionNameMap[dimid], pos.x, pos.y, pos.z));
        }
        return true;
    };
    MakeCommand("tpdim", "View plugin information", 0);
    CmdOverload(tpdim, func, "dimid", "position");
    Global<CommandRegistry>->registerAlias("tpdim", cmdName);
    char filler[256];
    Packet& (CommandRegistry:: * func2)(void*);
    *(void**)&func2=dlsym_real("?serializeAvailableCommands@CommandRegistry@@QEBA?AVAvailableCommandsPacket@@XZ");
    auto& pkt = (Global<CommandRegistry>->*func2)(filler);
    for (auto& pl : Level::getAllPlayers()) {
        Global<Minecraft>->getNetworkHandler().send(*pl->getNetworkIdentifier(), pkt, (unsigned char)0);
    }
    return true;
}

bool testCommand(CommandOrigin const& ori, CommandOutput& outp, optional<string>& name, optional<string>& suffix) {
    bool isLittleEndian = true;
    auto fileName = name.set ? name.val() : "test";
    auto fileType = "." + (suffix.set ? suffix.val() : "nbt");
    auto binary = fileType == ".nbt";
    auto filePath = fmt::format("{}{}{}", NbtFileDir, fileName, fileType);

    auto content = ReadAllFile(filePath, binary);
    if (!content.has_value()) {
        outp.error(fmt::format("文件 {} 不存在", filePath));
        return false;
    }
    auto& nbt = content.value();
    Tag* tag;
    if (binary) {
        tag = Tag::fromBinaryNBT((void*)nbt.c_str(), nbt.size(), isLittleEndian);
    }
    else {
        tag = Tag::fromSNBT(nbt);
    }
    outp.success(fmt::format("读取文件 {} 成功，内容:", filePath));
    //std::cout << tag->toSNBT() << std::endl;
    auto new_bnbt = tag->toBinaryNBT(isLittleEndian);
    if (binary) {
        if (new_bnbt== nbt) {
            outp.success("bin->tag->bin测试通过");
        }
        else {
            WriteAllFile(NbtFileDir"error.nbt", new_bnbt, true);
            outp.error("bin->tag->bin测试失败");
            return false;
        }
    }
    auto new_tag = Tag::fromBinaryNBT((void*)new_bnbt.c_str(), new_bnbt.size(), isLittleEndian);

    if (new_tag->equals(*tag)) {
        outp.success("tag->bin->tag测试通过");
    }
    else {
        WriteAllFile(NbtFileDir"error.nbt", new_tag->toBinaryNBT(), isLittleEndian);
        outp.error("tag->bin->tag测试失败");
        std::cout << tag->toJson(0) << std::endl;
        return false;
    }
    auto snbt = tag->toSNBT();
    std::cout << snbt << std::endl;
    auto new_tag_from_snbt = Tag::fromSNBT(snbt);

    if (new_tag_from_snbt->equals(*tag)) {
        outp.success("tag->snbt->tag测试通过");
    }
    else {
        WriteAllFile(NbtFileDir"error.nbt", new_tag->toBinaryNBT(), isLittleEndian);
        outp.error("tag->snbt->tag测试失败");
        return false;
    }
    auto json = tag->toJson(4);
    std::cout << json << std::endl;
    return true;
}

void registerCommands() {
    Event::addEventListener([](RegCmdEV ev) { // Register commands
        //CMDREG::SetCommandRegistry(ev.CMDRg);
        MakeCommand("dynreg", "dynreg", 0);
        CmdOverload(dynreg, dynregCommand, "name");
        MakeCommand("test", "test", 0);
        CmdOverload(test, testCommand, "name", "type");
        });
}

void entry() {
    registerCommands();
}