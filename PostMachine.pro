QT += widgets
QMAKE_CXXFLAGS += -std=c++0x
CONFIG += console

SOURCES += \
    src/main.cpp \
    src/window.cpp \
    src/renderarea.cpp

HEADERS += \
    includes/window.h \
    includes/renderarea.h
