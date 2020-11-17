TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++14

SOURCES += \
        commandpanel.cpp \
        guest.cpp \
        log.cpp \
        logfix.cpp \
        login.cpp \
        logreservation.cpp \
        main.cpp \
        manager.cpp \
        task.cpp \
        taskcontainer.cpp \
        user.cpp

HEADERS += \
    commandpanel.h \
    date.h \
    guest.h \
    log.h \
    logfix.h \
    login.h \
    logreservation.h \
    manager.h \
    task.h \
    taskcontainer.h \
    user.h
