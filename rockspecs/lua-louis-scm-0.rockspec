package = "lua-louis"
version = "scm-0"
source = {
   url = "https://github.com/liblouis/lua-louis",
   tag = "HEAD"
}
description = {
   summary = "Bindings for liblouis, the Braille translator",
   homepage = "http://github.com/liblouis/lua-louis/",
   license = "LGPLv3+"
}
dependencies = {
   "lua >= 5.1"
}
build = {
   type = "command",
   copy_directories = {
      "doc",
      "examples"
   },
   build_command = "LUA=$(LUA) CPPFLAGS=-I$(LUA_INCDIR) ./configure --prefix=$(PREFIX) --libdir=$(LIBDIR) --datadir=$(LUADIR) && make clean && make",
   install_command = "sleep 1 && make install"
}
