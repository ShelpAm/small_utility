add_deps("small_utility")

set_kind("binary")

set_objectdir("$(buildir)/obj/")
add_includedirs("$(projectdir)/test/", "$(projectdir)/src/")
add_linkdirs("$(projectdir)/lib/", "$(projectdir)/build/")
add_links("small_utility")

target("test-file")
    add_files("file/**.cc")
target_end()


target("test-log")
    add_files("log/**.cc")
target_end()


target("test-string")
    add_files("string/**.cc")
target_end()


target("test-utility")
    add_files("utility/**.cc")
target_end()


target("test-reference_counting")
    add_files("reference_counting/**.cc")
target_end()


target("run_all_tests")
    add_files("run_all_tests/**.cc")
target_end()
