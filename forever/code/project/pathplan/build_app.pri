####################################### TEMPLATE BEGIN#######################################
#static lib
TEMPLATE = app

#CONFIG   += staticlib
#CONFIG   += lib_flag # my definition:lib_flag means TEMPLATE is lib. After the operation, lib_flag is also a conditon
CONFIG   -= qt
QT       -= core gui
####################################### TEMPLATE END ########################################


####################################### Set up PATH BEGIN####################################
# path
P_T = $$PWD/../.. #P_T project top path

#project path vars
PTVAR_SRC = $$P_T/src
PTVAR_INC = $$P_T/include
PTVAR_SAMP = $$P_T/sample
PTVAR_BIN = $$P_T/bin
PTVAR_LIB = $$P_T/lib
PTVAR_BUILD = $$P_T/build

#tell qmake to fine files in project top when in trouble
#VPATH += $$P_T
#VPATH += $$PTVAR_SRC
#VPATH += $$PTVAR_INC
#VPATH += $$PTVAR_SAMP

######Set up INCLUDE PATH
INCLUDEPATH += $$PTVAR_INC
INCLUDEPATH += $$PTVAR_SRC
INCLUDEPATH += $$PTVAR_SAMP




######Set up LIB PATH
#LIBS += -L$$PTVAR_LIB
#LIBS += -L$$PTVAR_BIN
#LIBS += -L/usr/lib/x86_64-linux-gnu -lboost_date_time





######Set up build path
BUILDTYPE=
CONFIG(debug, debug|release){
    BUILDTYPE = debug
} else {
    BUILDTYPE = release
}
TARGET_DIR = $$TARGET
isEmpty(TARGET){
    TARGET_DIR = other
}

OBJECTS_DIR = $$PTVAR_BUILD/$$BUILDTYPE/$$TARGET_DIR/o
UI_DIR = $$PTVAR_BUILD/$$BUILDTYPE/$$TARGET_DIR/ui
MOC_DIR = $$PTVAR_BUILD/$$BUILDTYPE/$$TARGET_DIR/moc
RCC_DIR = $$PTVAR_BUILD/$$BUILDTYPE/$$TARGET_DIR/rcc


######Set up DESTDIR
#include(dlloutpath.pri)

isEmpty(DESTDIR):
CONFIG(debug, debug|release){
    DESTDIR = $$PTVAR_BIN/debug
} else {
    DESTDIR = $$PTVAR_BIN/release
}

#### note: DLLDESTDIR where to cp the target dll . But in linux os, it doesn't work.
contains(TEMPLATE, "lib"){
CONFIG(debug, debug|release){
    DLLDESTDIR = $$PTVAR_BIN/debug
    DESTDIR = $$PTVAR_LIB
} else {
    DLLDESTDIR = $$PTVAR_BIN/release
    DESTDIR = $$PTVAR_LIB
}
}

# unix install path
#unix{
#    target.path = /usr/lib
#    INSTALLS += target
#}

