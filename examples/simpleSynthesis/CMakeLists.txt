file(GLOB EXAMPLE_TTS_SOURCES "*.cc"
                              "../*.cc")
 
file(GLOB EXAMPLE_TTS_HEADERS
     "../*.h"
     "../*.hh")
source_group("Header Files" FILES ${EXAMPLE_TTS_HEADERS})


include_directories("..")
 
 
add_executable(example_tts ${EXAMPLE_TTS_SOURCES} ${EXAMPLE_TTS_HEADERS})
target_link_libraries(example_tts ${TTS_LINK_LIBRARIES})
set_target_properties(example_tts PROPERTIES
    OUTPUT_NAME "example_tts"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}" )