TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
DESTDIR = ../build
INCLUDEPATH += ../build/inc ../kaiwu/build/inc

LIBS += -L../build -lcpprestd-1.0
LIBS += -L../kaiwu/build -lkaiwud-1.0
LIBS += -L"/usr/local/lib/" -lgtest -lpthread -levent

SOURCES += \
    cpprest_test.cc \
    http_server_test.cc \
    main.cc \
    make_handler_info_test.cpp

