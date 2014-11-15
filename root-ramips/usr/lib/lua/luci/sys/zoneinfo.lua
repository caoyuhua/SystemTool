--[[
LuCI - Autogenerated Zoneinfo Module

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

]]--

local setmetatable, require, rawget, rawset = setmetatable, require, rawget, rawset

module "luci.sys.zoneinfo"

setmetatable(_M, {
	__index = function(t, k)
		if k == "TZ" and not rawget(t, k) then
			local m = require "luci.sys.zoneinfo.tzdata"
			rawset(t, k, rawget(m, k))
		elseif k == "OFFSET" and not rawget(t, k) then
			local m = require "luci.sys.zoneinfo.tzoffset"
			rawset(t, k, rawget(m, k))
		end

		return rawget(t, k)
	end
})
