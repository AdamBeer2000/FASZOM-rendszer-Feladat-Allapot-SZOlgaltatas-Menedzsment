TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++14

SOURCES += \
    datacommunicationcenter.cpp \
        main.cpp \
        commandpanel.cpp \
        Log/log.cpp \
        Log/logcleaning.cpp \
        Log/logfix.cpp \
        Log/logreplace.cpp \
        Log/logreservation.cpp \
        Reservation/reservation.cpp \
        Reservation/reservationcontainer.cpp \
        Room/room.cpp \
        Room/roomcontainer.cpp \
        Task/task.cpp \
        Task/taskcontainer.cpp \
        User/cleaner.cpp \
        User/guest.cpp \
        User/janitor.cpp \
        User/manager.cpp \
        User/receptionist.cpp \
        User/user.cpp \
        User/usermanager.cpp \

HEADERS += \
    Log/log.h \
    Log/logcleaning.h \
    Log/logfix.h \
    Log/logreplace.h \
    Log/logreservation.h \
    Reservation/reservation.h \
    Reservation/reservationcontainer.h \
    Room/room.h \
    Room/roomcontainer.h \
    Task/task.h \
    Task/taskcontainer.h \
    User/cleaner.h \
    User/guest.h \
    User/janitor.h \
    User/manager.h \
    User/receptionist.h \
    User/user.h \
    User/usermanager.h \
    cleaner.h \
    commandpanel.h \
    datacommunicationcenter.h \
    date.h \
    enumServing.h \
    enumSuit.h \
    guest.h \
    janitor.h \
    log.h \
    logcleaning.h \
    logfix.h \
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
