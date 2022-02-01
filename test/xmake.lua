target("test")
    set_kind("phony")
    add_deps("small_utility")
target_end()

includes("**/xmake.lua")
