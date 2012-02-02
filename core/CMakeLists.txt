set(osu_SRCS main.cpp beatmap.cpp primitive.cpp shaderprogram.cpp vsml.cpp)
add_executable(osu ${osu_SRCS})
target_link_libraries(osu ${GLEW_LIBRARY} opengl32)
include_directories(${GLEW_INCLUDE_PATH})

