set (libraries
	file
	log
	string
	time
	utility
)


add_library (small_utility INTERFACE)
target_link_libraries (small_utility INTERFACE ${libraries})

add_subdirectory (file)
add_subdirectory (log)
add_subdirectory (string)
add_subdirectory (time)
add_subdirectory (utility)
