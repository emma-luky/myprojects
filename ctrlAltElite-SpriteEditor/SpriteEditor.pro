QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    animationpreview.cpp \
    canvas.cpp \
    framebutton.cpp \
    jsonparser.cpp \
    framesbar.cpp \
    main.cpp \
    mainwindow.cpp \
    sprite.cpp \
    spriteeditor.cpp \
    spriteframe.cpp \
    startscreen.cpp \
    toolbar.cpp

HEADERS += \
    animationpreview.h \
    canvas.h \
    framebutton.h \
    jsonparser.h \
    enumTools.h \
    mainwindow.h \
    sprite.h \
    spriteeditor.h \
    spriteframe.h \
    startscreen.h \
    toolbar.h \
    framesbar.h

FORMS += \
    animationpreview.ui \
    canvas.ui \
    framebutton.ui \
    mainwindow.ui \
    startscreen.ui \
    toolbar.ui \
    framesbar.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc
