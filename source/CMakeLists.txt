
project(examples)

cmake_minimum_required(VERSION 2.8)

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS -DNOMINMAX -DWIN32_LEAN_AND_MEAN)
endif()


if (NOT CMAKE_BUILD_PLATFORM OR "${CMAKE_BUILD_PLATFORM}" STREQUAL "auto")
    if (${CMAKE_SIZEOF_VOID_P} EQUAL 4)
        set(CMAKE_BUILD_PLATFORM "x86")
    elseif(${CMAKE_SIZEOF_VOID_P} EQUAL 8)
        set(CMAKE_BUILD_PLATFORM "x86_64")
    endif()
endif()

if (LINUX)

    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden -Wl,-rpath,\$ORIGIN" )
    set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fvisibility=hidden" )
    set(TTS_LINK_LIBRARIES "-lpthread -l${CMAKE_DL_LIBS} -lm" )

    if(CMAKE_BUILD_PLATFORM STREQUAL "x86")
        set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32" )
        set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32" )
        set( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -m32 -z nodelete" )
        set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -m32" )
    elseif(CMAKE_BUILD_PLATFORM STREQUAL "x86_64")
        set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64" )
        set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64" )
        set( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -m64 -z nodelete" )
        set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -m64" )
    endif()

elseif (UNIX)

    set(TTS_LINK_LIBRARIES "-lm" )
    if (NOT ${CMAKE_DL_LIBS} STREQUAL "")
        set(TTS_LINK_LIBRARIES "-l${CMAKE_DL_LIBS}" )
    endif()

endif()


if (UNIX OR ANDROID)
    set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -Wfatal-errors -pedantic -std=gnu99 -Wl,--no-undefined -fPIC -Wall -Wextra -Wconversion -Werror=return-type -Werror=implicit-function-declaration")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wfatal-errors -pedantic -std=c++17 -Wl,--no-undefined -fPIC -Wall -Wextra -Wconversion -Werror=return-type")
    
    if (ANDROID)
       set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-register")
    endif()
       
    set(CMAKE_C_FLAGS_RELEASE  "${CMAKE_C_FLAGS_RELEASE} -O3 -DIS_RELEASE")
    set(CMAKE_CXX_FLAGS_RELEASE  "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DIS_RELEASE")
    if (NOT ENABLE_VALGRIND)
        set(CMAKE_CXX_FLAGS_RELEASE  "${CMAKE_CXX_FLAGS_RELEASE} -s")
    else()
        set(CMAKE_CXX_FLAGS_RELEASE  "${CMAKE_CXX_FLAGS_RELEASE} -g -gdwarf-4")
    endif()

    set(CMAKE_C_FLAGS_DEBUG  "${CMAKE_C_FLAGS_DEBUG} -g -gdwarf-4 -O0 -DIS_DEBUG")
    set(CMAKE_CXX_FLAGS_DEBUG  "${CMAKE_CXX_FLAGS_DEBUG} -g -gdwarf-4 -O0 -DIS_DEBUG")
elseif (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif()




if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif()


################################################################################
## simpleSynthesis                                                            ##
################################################################################

file(GLOB EXAMPLE_TTS_SOURCES "simpleSynthesis.cc"
                              "loader.cc")
 
file(GLOB EXAMPLE_TTS_HEADERS  "loader.hh"
                               "tts.h")
source_group("Header Files" FILES ${EXAMPLE_TTS_HEADERS})


add_executable(example_tts ${EXAMPLE_TTS_SOURCES} ${EXAMPLE_TTS_HEADERS})
target_link_libraries(example_tts ${TTS_LINK_LIBRARIES})
set_target_properties(example_tts PROPERTIES
    OUTPUT_NAME "example_tts"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}" )






################################################################################
## streamingSynthesis                                                         ##
################################################################################

file(GLOB EXAMPLE_TTS_STREAM_SOURCES "streamingSynthesis.cc"
                                     "loader.cc")
 
file(GLOB EXAMPLE_STREAM_TTS_HEADERS  "loader.hh"
                               "tts.h")
source_group("Header Files" FILES ${EXAMPLE_STREAM_TTS_HEADERS})


add_executable(example_tts_streaming ${EXAMPLE_TTS_STREAM_SOURCES} ${EXAMPLE_STREAM_TTS_HEADERS})
target_link_libraries(example_tts_streaming ${TTS_LINK_LIBRARIES})
set_target_properties(example_tts_streaming PROPERTIES
    OUTPUT_NAME "example_tts_streaming"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}" )


################################################################################
## template                                                                  ##
################################################################################

file(GLOB EXAMPLE_TTS_TEMPLATE_SOURCES "template.cc"
                                       "loader.cc")
 
file(GLOB EXAMPLE_TTS_TEMPLATE_HEADERS  "loader.hh"
                                         "tts.h")
source_group("Header Files" FILES ${EXAMPLE_TTS_TEMPLATE_HEADERS})


add_executable(example_tts_template ${EXAMPLE_TTS_TEMPLATE_SOURCES} ${EXAMPLE_TTS_TEMPLATE_HEADERS})
target_link_libraries(example_tts_template ${TTS_LINK_LIBRARIES})
set_target_properties(example_tts_template PROPERTIES
    OUTPUT_NAME "example_tts_template"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}" )
    
    
message("")
message("  ======== Compilation =======")
if (CMAKE_CXX_COMPILER_VERSION)
    set(CPQD_COMPILER_STR "${CMAKE_CXX_COMPILER} ${CMAKE_CXX_COMPILER_ARG1} (ver ${CMAKE_CXX_COMPILER_VERSION})")
elseif(CMAKE_COMPILER_IS_CLANGCXX)
    set(CPQD_COMPILER_STR "${CMAKE_CXX_COMPILER} ${CMAKE_CXX_COMPILER_ARG1} (ver ${CMAKE_CLANG_REGEX_VERSION})")
elseif(CMAKE_COMPILER_IS_GNUCXX)
    set(CPQD_COMPILER_STR "${CMAKE_CXX_COMPILER} ${CMAKE_CXX_COMPILER_ARG1} (ver ${CMAKE_GCC_REGEX_VERSION})")
else()
    set(CPQD_COMPILER_STR "${CMAKE_CXX_COMPILER} ${CMAKE_CXX_COMPILER_ARG1}")
endif()
string(STRIP "${CPQD_COMPILER_STR}" CPQD_COMPILER_STR)
message("       C++ Compiler:  ${CPQD_COMPILER_STR}")
message("         C Compiler:  ${CMAKE_C_COMPILER} ${CMAKE_C_COMPILER_ARG1}")
message("")
message("  --- Debug ---")
message("          C++ flags:  ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG}")
message("            C flags:  ${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_DEBUG}")
message("   Executable flags:  ${CMAKE_EXE_LINKER_FLAGS} ${CMAKE_EXE_LINKER_FLAGS_DEBUG}")
message("      Library flags:  ${CMAKE_SHARED_LINKER_FLAGS} ${CMAKE_SHARED_LINKER_FLAGS_DEBUG}")
message("")
message("  --- Release ---")
message("          C++ flags:  ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE}")
message("            C flags:  ${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_RELEASE}")
message("   Executable flags:  ${CMAKE_EXE_LINKER_FLAGS} ${CMAKE_EXE_LINKER_FLAGS_RELEASE}")
message("      Library flags:  ${CMAKE_SHARED_LINKER_FLAGS} ${CMAKE_SHARED_LINKER_FLAGS_RELEASE}")
message("")