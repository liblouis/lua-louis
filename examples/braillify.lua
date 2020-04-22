-- A pandoc filter that converts all text to braille
--
-- # SYNOPSIS
-- 
--      pandoc --lua-filter braillify.lua -t rst input.md
--
local louis = require "liblua-louis"

BRAILLE_TABLE = 'en-ueb-g2.ctb'

return {
   {
      Str = function (elem)
	 local brl = louis.translateString(BRAILLE_TABLE, elem.text)
	 -- FIXME: for some reason translateString seems to return the
	 -- empty string
	 if brl ~= "" then
	    return pandoc.Str(brl)
	 else
	    return elem
	 end
      end,
   }
}
