#
# Try to find GLEW library and include path.
# Once done this will define
#
# GLEW_FOUND
# GLEW_INCLUDE_PATH
# GLEW_LIBRARY
#
# Adapted from nvidia-texture-tools
# http://code.google.com/p/nvidia-texture-tools/

if(WIN32)
        find_path( GLEW_INCLUDE_PATH GL/glew.h
                /c/msys/1.0/include
                c:/msys/1.0/include/
                DOC "The directory where GL/glew.h resides")
        find_library( GLEW_LIBRARY
                NAMES glew GLEW glew32 glew32s
                PATHS
                /c/msys/1.0/lib
                c:/msys/1.0/lib/
                $ENV{PROGRAMFILES}/GLEW/lib
                ${PROJECT_SOURCE_DIR}/src/nvgl/glew/bin
                ${PROJECT_SOURCE_DIR}/src/nvgl/glew/lib
                DOC "The GLEW library")
else(WIN32)
        find_path( GLEW_INCLUDE_PATH GL/glew.h
                /usr/include
                /usr/local/include
                /sw/include
                /opt/local/include
                /contrib/projects/glew/include
                DOC "The directory where GL/glew.h resides")
        find_library( GLEW_LIBRARY
                NAMES GLEW glew
                PATHS
                /usr/lib64
                /usr/lib
                /usr/local/lib64
                /usr/local/lib
                /sw/lib
                /opt/local/lib
                /contrib/projects/glew/lib
                DOC "The GLEW library")
endif(WIN32)
if(GLEW_INCLUDE_PATH)
        set(GLEW_FOUND 1)
        message(STATUS ${GLEW_INCLUDE_PATH})
        message(STATUS ${GLEW_LIBRARY})
else(GLEW_INCLUDE_PATH)
        set(GLEW_FOUND 0)
        message(STATUS "GLEW not found.  Either set GLEW_INCLUDE_PATH and GLEW_LIBRARY or make sure GLEW is included in your PATH")
endif(GLEW_INCLUDE_PATH)

MARK_AS_ADVANCED(GLEW_FOUND)
