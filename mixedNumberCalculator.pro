TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    parser.cpp \
    calculate.cpp \
    fraction.cpp \
    mixednumber.cpp

HEADERS += \
    parser.h \
    calculate.h \
    fraction.h \
    mixednumber.h
