QT += testlib
QT -= gui
CONFIG += c++17 console
CONFIG -= app_bundle
QT += network

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test_case1.cpp \
    ../../Proga_Egz/server/func_for_server.cpp \
    ../../Proga_Egz/server/mytcpserver.cpp

HEADERS += \
    ../../Proga_Egz/server/func_for_server.h \
    ../../Proga_Egz/server/mytcpserver.h
