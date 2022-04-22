TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
HEADERS += \
		ant_fs.h \
        core/ant_inode.h \
        core/ant_super.h \
    core/defines.h
SOURCES += \
		ant_fs.c \
        core/ant_inode.c \
        core/ant_super.c
