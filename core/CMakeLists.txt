set(core_SRCS main.cpp beatmap.cpp primitive.cpp shaderprogram.cpp vsml.cpp osugame.cpp)
#add_executable(core ${core_SRCS})
add_library(core ${core_SRCS})
set_target_properties(core PROPERTIES VERSION 1.0.0 SOVERSION 1)
target_link_libraries(core ${GLEW_LIBRARY})

include_directories(${GLEW_INCLUDE_PATH})

