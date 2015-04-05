QT += widgets
win32-g++{
    QMAKE_CXXFLAGS += -std=c++1y
}else:win32-msvc*{
    cpp.cxxFlags: "-std=c++1y"
}

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/postlogic.cpp

HEADERS += \
    includes/mainwindow.h \
    includes/postlogic.h

FORMS += \
    mainwindow.ui
