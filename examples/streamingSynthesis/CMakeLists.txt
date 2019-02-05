file(GLOB EXAMPLE_TTS_STREAM_SOURCES "*.cc"
                              "../*.cc")
 
file(GLOB EXAMPLE_STREAM_TTS_HEADERS
     "../*.h"
     "../*.hh")
source_group("Header Files" FILES ${EXAMPLE_STREAM_TTS_HEADERS})

include_directories("..")
 
add_executable(example_tts_streaming ${EXAMPLE_TTS_STREAM_SOURCES} ${EXAMPLE_STREAM_TTS_HEADERS})
target_link_libraries(example_tts_streaming ${TTS_LINK_LIBRARIES})
set_target_properties(example_tts_streaming PROPERTIES
    OUTPUT_NAME "example_tts_streaming"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}" )