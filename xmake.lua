set_project("small_utility")
set_version("0.0.2", {build = "%Y%m%d%H%M"})

set_targetdir("$(projectdir)/build/")

includes("src/xmake.lua")
includes("test/xmake.lua")
