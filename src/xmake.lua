target("small_utility")
    set_kind("static")
    set_languages("cxx11")
    set_optimize("fastest")

    set_objectdir("$(buildir)/obj/")
    add_includedirs("$(projectdir)/src/")
    add_linkdirs("$(projectdir)/lib/")

    add_files("$(projectdir)/src/**.cc")
