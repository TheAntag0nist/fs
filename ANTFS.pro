TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

COREDIR = core
PARTSSDIR = $$COREDIR/fs_parts
HELPERDIR = $$COREDIR/helper

HEADERS += \
    $$PARTSSDIR/ant_fs_struct.h \
    $$PARTSSDIR/ant_gdt.h \
    $$PARTSSDIR/ant_inode.h \
    $$PARTSSDIR/ant_super.h \
    $$HELPERDIR/ant_helpers.h \
    $$COREDIR/ant_core.h \
    $$COREDIR/defines.h \
    commands/commands.h \
    log/logger.h \
    log/colors.h
SOURCES += \
    $$COREDIR/ant_core.c \
    $$HELPERDIR/ant_helpers.c \
    commands/commands.c \
    code_style/code_style.c \
    ant_fs.c \
    log/logger.c \
    log/colors.c



