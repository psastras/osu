

include(ExternalProject)
ExternalProject_Add(libopenal
	SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/OpenAL
	CMAKE_ARGS ${LOCAL_CMAKE_BUILD_OPTIONS} -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/install
	INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/install
)
ExternalProject_Add(libmpg123
	SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/mpg123
	CONFIGURE_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/mpg123/configure --prefix=${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/install
	BUILD_COMMAND ${MAKE})

set(EXTERNAL_LIBRARIES ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/install/lib/openal)
set(core_SRCS main.cpp beatmap.cpp primitive.cpp shaderprogram.cpp vsml.cpp osugame.cpp)

add_library(core ${core_SRCS})
set_target_properties(core PROPERTIES VERSION 1.0.0 SOVERSION 1)

set(CMAKE_LIBRARY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/install/lib)
find_library(MPG123_LIBRARY mpg123)
find_library(OPENAL_LIBRARY openal)
target_link_libraries(core ${MPG123_LIBRARY} ${OPENAL_LIBRARY})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/install/include
					${CMAKE_CURRENT_SOURCE_DIR}/)
