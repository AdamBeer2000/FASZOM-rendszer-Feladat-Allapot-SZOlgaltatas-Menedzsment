TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        commandpanel.cpp \
        guest.cpp \
        log.cpp \
        logfix.cpp \
        login.cpp \
        main.cpp \
        manager.cpp \
        task.cpp \
        taskcontainer.cpp \
        user.cpp

HEADERS += \
    commandpanel.h \
    guest.h \
    log.h \
    logfix.h \
    login.h \
    manager.h \
    task.h \
    taskcontainer.h \
    user.h
