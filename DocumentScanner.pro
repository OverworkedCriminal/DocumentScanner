QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    head/

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    head/mainwindow.h

FORMS += \
    forms/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/DocumentScanner/build/release/ -ldocumentscanner
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/DocumentScanner/build/debug/ -ldocumentscanner
else:unix: LIBS += -L$$PWD/lib/DocumentScanner/build/ -ldocumentscanner

INCLUDEPATH += $$PWD/lib/DocumentScanner/include
DEPENDPATH += $$PWD/lib/DocumentScanner/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/DocumentScanner/build/release/libdocumentscanner.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/DocumentScanner/build/debug/libdocumentscanner.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/DocumentScanner/build/release/documentscanner.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/DocumentScanner/build/debug/documentscanner.lib
else:unix: PRE_TARGETDEPS += $$PWD/lib/DocumentScanner/build/libdocumentscanner.a