/* lua-louis: liblouis bindings for Lua

Copyright (C) 2017 Swiss Library for the Blind, Visually Impaired and Print Disabled

This file is part of lua-louis.

lua-louis is free software: you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published
by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

lua-louis is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with liblouis. If not, see <http://www.gnu.org/licenses/>.

*/

/*** liblouis bindings for Lua

Very basic liblouis bindings for Lua
@module louis
 */
#include <config.h>
#include <stdlib.h>
#include <stdio.h>
#include <lua.h>
#include <lauxlib.h>
#include "liblouis/liblouis.h"
#include "unistr.h"

#if SIZEOF_WIDECHAR > 2
#define to_utf8(input, inputlen, outlen) u32_to_u8(input, inputlen, NULL, outlen)
#define from_utf8(input, inputlen, outlen) u8_to_u32(input, inputlen, NULL, outlen)
#else
#define to_utf8(input, inputlen, outlen) u16_to_u8(input, inputlen, NULL, outlen)
#define from_utf8(input, inputlen, outlen) u8_to_u16(input, inputlen, NULL, outlen)
#endif

/***
Return version string of liblouis
@function version
@treturn string the version string of liblouis
*/
static int lua_lou_version (lua_State *L) {
  lua_pushstring(L, lou_version());
  return 1;
}

/***
Translate a string to braille
@function translateString
@tparam string tables a comma separated list of tables to use for the translation
@tparam string input the text to translate
@treturn string the translated braille
@raise 'Braille translation failed' if the translation fails
*/
static int lua_lou_translateString (lua_State *L) {
  const char *tableList = luaL_checkstring(L, 1);
  const char *input = luaL_checkstring(L, 2);

  size_t input_len = u8_strlen(input);
  size_t inbuflen;
  widechar *inbuf = from_utf8(input, input_len, &inbuflen);

  int inlen = (int) inbuflen;
  int outlen;
  widechar* outbuf = malloc(sizeof(widechar) * input_len * 10);

  if (!lou_translateString(tableList, inbuf, &inlen, outbuf, &outlen,
			   NULL, NULL, 0))
    luaL_error(L, "Braille translation failed.");

  size_t outputlen;
  char *output = to_utf8(outbuf, outlen, &outputlen);
  lua_pushlstring(L, output, outputlen);
  free(inbuf);
  free(outbuf);
  free(output);
  return 1; 
}

static const struct luaL_Reg louis [] = {
  {"version", lua_lou_version},
  {"translateString", lua_lou_translateString},
  {NULL, NULL}  /* sentinel */
};

/* provide backwards compat for lua5.1 see
   http://lua-users.org/wiki/CompatibilityWithLuaFive and
   https://stackoverflow.com/questions/19041215/lual-openlib-replacement-for-lua-5-2#19041283 */
#if !defined LUA_VERSION_NUM || LUA_VERSION_NUM==501
/*
** Adapted from Lua 5.2.0
*/
static void luaL_setfuncs (lua_State *L, const luaL_Reg *l, int nup) {
  luaL_checkstack(L, nup+1, "too many upvalues");
  for (; l->name != NULL; l++) {  /* fill the table with given functions */
    int i;
    lua_pushstring(L, l->name);
    for (i = 0; i < nup; i++)  /* copy upvalues to the top */
      lua_pushvalue(L, -(nup+1));
    lua_pushcclosure(L, l->func, nup);  /* closure with those upvalues */
    lua_settable(L, -(nup + 3));
  }
  lua_pop(L, nup);  /* remove upvalues */
}
#endif

int luaopen_louis (lua_State *L) {
  lua_newtable(L);
  luaL_setfuncs(L, louis, 0);
  return 1;
}
