set (libraries
	file
	log
	string
	time
	utility
)

link_libraries (${libraries})

add_subdirectory (file)
add_subdirectory (log)
add_subdirectory (math)
add_subdirectory (reference_counting)
add_subdirectory (string)
add_subdirectory (utility)
