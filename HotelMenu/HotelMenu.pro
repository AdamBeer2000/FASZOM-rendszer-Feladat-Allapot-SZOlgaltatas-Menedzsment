TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Commandpanel.cpp \
        Login.cpp \
        main.cpp \
        manager.cpp \
        user.cpp

HEADERS += \
    Commandpanel.h \
    Login.h \
    User.h \
    manager.h
