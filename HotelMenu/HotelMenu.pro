TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++14

SOURCES += \
        cleaner.cpp \
        commandpanel.cpp \
        guest.cpp \
        janitor.cpp \
        log.cpp \
        logcleaning.cpp \
        logfix.cpp \
        login.cpp \
        logreplace.cpp \
        logreservation.cpp \
        main.cpp \
        manager.cpp \
        receptionist.cpp \
        reservation.cpp \
        reservationcontainer.cpp \
        room.cpp \
        roomcontainer.cpp \
        task.cpp \
        taskcontainer.cpp \
        user.cpp \
        usermanager.cpp

HEADERS += \
    cleaner.h \
    commandpanel.h \
    date.h \
    enumServing.h \
    enumSuit.h \
    guest.h \
    janitor.h \
    log.h \
    logcleaning.h \
    logfix.h \
    login.h \
    logreplace.h \
    logreservation.h \
    manager.h \
    receptionist.h \
    reservation.h \
    reservationcontainer.h \
    room.h \
    roomcontainer.h \
    task.h \
    taskcontainer.h \
    user.h \
    usermanager.h
