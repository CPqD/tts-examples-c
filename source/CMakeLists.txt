project(examples)
cmake_minimum_required(VERSION 3.10)

if (UNIX)
	set(TTS_LINK_LIBRARIES "-lpthread -l${CMAKE_DL_LIBS}" )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wfatal-errors -pedantic -Wall -Wextra -Wconversion -Werror=return-type")
endif()

################################################################################
## simpleSynthesis                                                            ##
################################################################################

file(GLOB EXAMPLE_TTS_SOURCES "simpleSynthesis.cc" "loader.cc")
 file(GLOB EXAMPLE_TTS_HEADERS  "loader.hh" "tts.h")
source_group("Header Files" FILES ${EXAMPLE_TTS_HEADERS})


add_executable(example_tts ${EXAMPLE_TTS_SOURCES} ${EXAMPLE_TTS_HEADERS})
target_link_libraries(example_tts ${TTS_LINK_LIBRARIES})
set_target_properties(example_tts PROPERTIES
    OUTPUT_NAME "example_tts"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}" )

################################################################################
## streamingSynthesis                                                         ##
################################################################################

file(GLOB EXAMPLE_TTS_STREAM_SOURCES "streamingSynthesis.cc" "loader.cc")
file(GLOB EXAMPLE_STREAM_TTS_HEADERS  "loader.hh" "tts.h")
source_group("Header Files" FILES ${EXAMPLE_STREAM_TTS_HEADERS})

add_executable(example_tts_streaming ${EXAMPLE_TTS_STREAM_SOURCES} ${EXAMPLE_STREAM_TTS_HEADERS})
target_link_libraries(example_tts_streaming ${TTS_LINK_LIBRARIES})
set_target_properties(example_tts_streaming PROPERTIES
    OUTPUT_NAME "example_tts_streaming"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}" )


################################################################################
## template                                                                  ##
################################################################################

file(GLOB EXAMPLE_TTS_TEMPLATE_SOURCES "template.cc" "loader.cc")
file(GLOB EXAMPLE_TTS_TEMPLATE_HEADERS  "loader.hh" "tts.h")
source_group("Header Files" FILES ${EXAMPLE_TTS_TEMPLATE_HEADERS})

add_executable(example_tts_template ${EXAMPLE_TTS_TEMPLATE_SOURCES} ${EXAMPLE_TTS_TEMPLATE_HEADERS})
target_link_libraries(example_tts_template ${TTS_LINK_LIBRARIES})
set_target_properties(example_tts_template PROPERTIES
    OUTPUT_NAME "example_tts_template"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}" )