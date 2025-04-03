QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appconfiguration.cpp \
    connectsettingform.cpp \
    logutil.cpp \
    main.cpp \
    autoscope.cpp \
    msgboxhelper.cpp \
    mytreeview.cpp

HEADERS += \
    ProjectNode.h \
    appconfiguration.h \
    autoscope.h \
    connectsettingform.h \
    logutil.h \
    msgboxhelper.h \
    mytreeview.h

FORMS += \
    autoscope.ui \
    connectsettingform.ui


DEFINES += QT_MESSAGELOGCONTEXT
DISTFILES += config.json

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc \
    res.qrc
