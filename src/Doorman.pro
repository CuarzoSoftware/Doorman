QT += widgets core gui svg
CONFIG += c++17
TARGET = Doorman

target.path = /usr/bin
INSTALLS += target

HEADERS += \
    code/Avatar.h \
    code/IconButton.h \
    code/LoginForm.h \
    code/MainWindow.h \
    code/Shared.h \
    code/UserView.h

SOURCES += \
    code/Avatar.cpp \
    code/IconButton.cpp \
    code/LoginForm.cpp \
    code/MainWindow.cpp \
    code/Shared.cpp \
    code/UserView.cpp \
    code/main.cpp
