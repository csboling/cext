#include <stdio.h>

#include <lua.h>
#include <lauxlib.h>

int sum2(lua_State* L)
{
    if (lua_gettop(L) != 2) {
        return luaL_error(L, "expected 2 args");
    }
    int left = luaL_checkinteger(L, 1);
    int right = luaL_checkinteger(L, 2);
    int sum = left + right;
    lua_pushinteger(L, (lua_Integer)sum);
    return 1;
}

int luaopen_test(lua_State* L)
{
    lua_newtable(L);
    lua_pushcfunction(L, &sum2);
    lua_setfield(L, -2, "sum2");
    return 1;
}
