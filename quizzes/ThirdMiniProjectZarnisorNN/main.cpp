

extern "C"
{
#include "lua-5.4.6/src/lapi.h"
#include "lua-5.4.6/src/lauxlib.h"
#include "lua-5.4.6/src/lcode.h"
#include "lua-5.4.6/src/lctype.h"
#include "lua-5.4.6/src/ldebug.h"
#include "lua-5.4.6/src/ldo.h"
#include "lua-5.4.6/src/lfunc.h"
#include "lua-5.4.6/src/lgc.h"
#include "lua-5.4.6/src/ljumptab.h"
#include "lua-5.4.6/src/llex.h"
#include "lua-5.4.6/src/llimits.h"
#include "lua-5.4.6/src/lmem.h"
#include "lua-5.4.6/src/lobject.h"
#include "lua-5.4.6/src/lopcodes.h"
#include "lua-5.4.6/src/lopnames.h"
#include "lua-5.4.6/src/lparser.h"
#include "lua-5.4.6/src/lprefix.h"
#include "lua-5.4.6/src/lstate.h"
#include "lua-5.4.6/src/lstring.h"
#include "lua-5.4.6/src/ltable.h"
#include "lua-5.4.6/src/ltm.h"
#include "lua-5.4.6/src/lua.h"
#include "lua-5.4.6/src/luaconf.h"
#include "lua-5.4.6/src/lualib.h"
#include "lua-5.4.6/src/lundump.h"
#include "lua-5.4.6/src/lvm.h"
#include "lua-5.4.6/src/lzio.h"
}


#include "gameIndyCat.hpp"
#include "LuaBridge/detail/CFunctions.h"
#include "LuaBridge/detail/ClassInfo.h"
#include "LuaBridge/detail/Constructor.h"
#include "LuaBridge/detail/FuncTraits.h"
#include "LuaBridge/detail/Iterator.h"
#include "LuaBridge/detail/LuaException.h"
#include "LuaBridge/detail/LuaHelpers.h"

#include "LuaBridge/detail/Namespace.h"
#include "LuaBridge/detail/Security.h"
#include "LuaBridge/detail/Stack.h"
#include "LuaBridge/detail/TypeList.h"
#include "LuaBridge/detail/TypeTraits.h"
#include "LuaBridge/detail/Userdata.h"
#include "LuaBridge/detail/LuaRef.h"

using namespace ilrd;

int main()
{
    
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    luabridge::getGlobalNamespace(L)
        .beginClass<Game>("Game")
        .addConstructor<void (*)()>()
        .addFunction("run", &Game::Run)
        .addFunction("exit", &Game::Exit)
        .addFunction("getUserDataInput", &Game::GetUserDataInput)
        .addFunction("prepareForNewRound", &Game::PreapareForNewRound)
        .addFunction("moveSquare", &Game::MoveSquare)
        .endClass();

    // Execute Lua code directly
    const char* luaCode = R"(
        local game = Game()
        game:run()
    )";

    if (luaL_dostring(L, luaCode) != LUA_OK) 
    {
        const char* errorMessage = lua_tostring(L, -1);
        std::cerr << "Lua error: " << errorMessage << std::endl;
    }

    lua_close(L);

    return 0;
}