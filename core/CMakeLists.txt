set(SHADERS shaders/solid.glsl shaders/background.glsl)
foreach(_file ${SHADERS})
	string(REPLACE ".glsl" ".h" _file_h ${_file})
	add_custom_command(OUTPUT ${_file_h}
					   COMMAND xxd -i ${_file} ${_file_h}
					   MAIN_DEPENDENCY ${_file}
					   COMMENT "${_file} -> ${_file_h}"
					   VERBATIM)
endforeach()
set(core_SRCS main.cpp beatmap.cpp primitive.cpp shaderprogram.cpp vsml.cpp osugame.cpp audio.cpp osurenderer.cpp
	shaders/solid.h shaders/background.h)
#add_executable(core ${core_SRCS})
add_library(core ${core_SRCS})
set_target_properties(core PROPERTIES VERSION 1.0.0 SOVERSION 1)


include_directories(${GLEW_INCLUDE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/install/include)
include_directories(${GLEW_INCLUDE_PATH} ${CMAKE_CURRENT_SOURCE_DIR})
include(ExternalProject)
#ExternalProject_Add(libmpg123
#	SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/mpg123
#	CONFIGURE_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/mpg123/configure --prefix=${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/install
#	BUILD_COMMAND ${MAKE})
ExternalProject_Add(libmad
	SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/mad
	CONFIGURE_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/mad/configure --prefix=${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/install
        BUILD_COMMAND ${MAKE}
        BUILD_IN_SOURCE 1
)
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/install)
ExternalProject_Add(libopenal
	SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/OpenAL
        INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/install
        CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/install"
)
set(CMAKE_LIBRARY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/install/lib)

if(WIN32)
    find_library(OPENAL_LIBRARY OpenAL32)
else()
    find_library(OPENAL_LIBRARY openal)
endif(WIN32)
find_library(MAD_LIBRARY mad)
target_link_libraries(core ${GLEW_LIBRARY} ${MAD_LIBRARY} ${OPENAL_LIBRARY})
