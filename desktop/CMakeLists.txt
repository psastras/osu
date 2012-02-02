find_package(Qt4 REQUIRED)
set(QT_USE_QTOPENGL TRUE)
set(osu_SRCS main.cpp mainwindow.cpp glwidget.cpp)
set(osu_HDRS mainwindow.h glwidget.h) #headers with Q_OBJECTS MUST BE PUT HERE
set(osu_FORMS mainwindow.ui)
QT4_WRAP_CPP(osu_HDRS_MOC ${osu_HDRS})
QT4_WRAP_UI(osu_FORMS_HDRS ${osu_FORMS})
include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})
add_executable(osu	${osu_SRCS}
						${osu_HDRS_MOC}
						${osu_FORMS_HDRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(osu ${QT_LIBRARIES} core)

