TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        commandpanel.cpp \
        guest.cpp \
        login.cpp \
        main.cpp \
        manager.cpp \
        task.cpp \
        user.cpp

HEADERS += \
    commandpanel.h \
    guest.h \
    login.h \
    manager.h \
    task.h \
    user.h
