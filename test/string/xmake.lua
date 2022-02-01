target("test-string")
    set_kind("binary")
    set_symbols("debug")
    set_languages("cxx11")
    set_optimize("fastest")

    set_objectdir("$(buildir)/obj/")
    add_includedirs("$(projectdir)/test/", "$(projectdir)/src/")
    add_linkdirs("$(projectdir)/lib/", "$(projectdir)/build/")

    add_files("**.cc")
    add_links("small_utility")
target_end()
