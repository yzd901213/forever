#
#Step1: set version
#
VERSION = 1.0.0

#
#Step2: configure project management
#
#two kinds of way: cmit_project or cmit_product
#CONFIG += cmit_project

#Step2.1: add user custom configuration items  (console)
CONFIG += console
#
#Step3: set up the project relies on third-party libraries
#
#the third-party lib's default inventory directory is: $SOFTWARE_PATH/lib
#when set up the lib directory, you need only add variables to LIB_DIRS.
#but if one lib is a subproject of the product, and you don't have copy it to $SOFTWARE_PATH/lib
#during the development process, you can use LIB_SRC_DIRS to save its relate dircetory.
LIB_DIRS =
LIB_SRC_DIRS =


#
#Step4: set up the project genarated target name(default set as projectname)
#
#TARGET =

#
#Step5: predefined macros
#
#DEFINES += EKFSLAM_RADAR_BUILD_DLL
#DEFINES += BOOST_DATE_TIME_USE_LIB
DEFINES += JIAN_TEST_MACRAO #TEST_MACRO

#
#Step6: include project template file
#
include(./build_app.pri)

#
#Step7: add project source file
#
SOURCES += \
    ../../src/pathplan.cpp \
    ../../src/main.cpp \
#    ../../sample/main.cpp
    ../../src/map.cpp \
    ../../src/astar.cpp \
#    ../../include/commondef.cpp




HEADERS += \
    ../../include/pathplan.hpp \
    ../../include/map.hpp \
    ../../include/commondef.hpp \
    ../../include/astar.hpp
