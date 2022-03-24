target("small_utility")
    set_kind("static")
    set_symbols("debug")
    set_languages("cxx20")

    set_objectdir("$(buildir)/obj/")
    add_includedirs("$(projectdir)/src/")
    add_linkdirs("$(projectdir)/lib/")

    add_files("$(projectdir)/src/**.cc")
