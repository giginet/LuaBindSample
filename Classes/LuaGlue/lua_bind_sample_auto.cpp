#include "lua_bind_sample_auto.hpp"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "LuaBindSample.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_bind_sample_GameObject_method(lua_State* tolua_S)
{
    int argc = 0;
    GameObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_bind_sample_GameObject_method'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->method();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "method",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_bind_sample_GameObject_method'.",&tolua_err);
#endif
    return 0;
}
int lua_bind_sample_GameObject_constructor(lua_State* tolua_S)
{
    int argc = 0;
    GameObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj = new GameObject(arg0, arg1);
        if (nullptr != dynamic_cast<cocos2d::Object *>(cobj)) 
        {
            cobj->autorelease();
            int ID = (cobj) ? (int)cobj->_ID : -1;
            int* luaID = (cobj) ? &cobj->_luaID : NULL;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"GameObject");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"GameObject");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "GameObject",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_bind_sample_GameObject_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_bind_sample_GameObject_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameObject)");
    return 0;
}

int lua_register_bind_sample_GameObject(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"GameObject");
    tolua_cclass(tolua_S,"GameObject","GameObject","Node",NULL);

    tolua_beginmodule(tolua_S,"GameObject");
        tolua_function(tolua_S,"method",lua_bind_sample_GameObject_method);
        tolua_function(tolua_S,"new",lua_bind_sample_GameObject_constructor);
    tolua_endmodule(tolua_S);
    uint32_t typeId = typeid(GameObject).hash_code();
    g_luaType[typeId] = "GameObject";
    return 1;
}
TOLUA_API int register_all_bind_sample(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_bind_sample_GameObject(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

