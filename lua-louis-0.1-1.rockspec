package="lua-louis"
version="0.1-1"
source = {
  url = "https://github.com/liblouis/lua-louis",
  tag = "v0.1"
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
  build_command = "LUA=$(LUA) CPPFLAGS=-I$(LUA_INCDIR) ./configure --prefix=$(PREFIX) --libdir=$(LIBDIR) --datadir=$(LUADIR) && make clean && make",
  install_command = "make install",
  copy_directories = { "doc", "examples" }
}