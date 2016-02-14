TEMPLATE = lib
CONFIG += console staticlib
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += debug_and_release
LIBS += -L"/usr/local/lib/" -lgtest -lpthread -levent
LIBS += -L../kaiwu/build/ -lkaiwud-1.0
INCLUDEPATH += ../kaiwu/build/inc

VERSION = 1.0
DESTDIR = ../build/

CONFIG(debug, debug|release) {
    TARGET = cpprestd
}else{
    TARGET = cpprest
}

TARGET = $$sprintf(%1-%2, $$TARGET, $$VERSION)

copy_head_file.target = .copy_head_file
copy_head_file.commands += mkdir -p ../build/inc
copy_head_file.commands += && cp *.h ../build/inc/

QMAKE_EXTRA_TARGETS += copy_head_file
POST_TARGETDEPS += .copy_head_file

HEADERS += \
    cpprest.h \
    http_server.h \
    iresponse.h \
    irequest.h

SOURCES += \
    cpprest.cc \
    http_server.cc
