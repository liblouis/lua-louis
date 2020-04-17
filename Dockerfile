FROM debian:latest

LABEL maintainer="Liblouis Maintainers <liblouis-liblouisxml@freelists.org>"

# Fetch build dependencies
RUN apt-get update && apt-get install -y \
    autoconf \
    automake \
    libtool \
    make \
    liblouis-dev \
    liblouis-data

# install lua
ARG LUA=lua5.1
ARG LUA_DEV=liblua5.1-dev
RUN apt-get install -y $LUA $LUA_DEV luarocks

# build bindings
ADD . /usr/src/lua-louis
WORKDIR /usr/src/lua-louis
RUN ./autogen.sh && luarocks make rockspecs/lua-louis-scm-0.rockspec

# test the bindings
RUN eval `luarocks path` && lua -e "print(require'liblua-louis'.translateString('en-ueb-g2.ctb', 'Hello World'))"
