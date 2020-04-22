#!/usr/bin/env lua

-- An example how to invoke liblouis from lua

local louis = require "liblua-louis"
print(louis.translateString("de-g2.ctb", "Güten Tag"))
print(louis.translateString("de-g2.ctb", "Guter Mann"))
print(louis.translateString("de-g2.ctb", "Gute Nacht"))
