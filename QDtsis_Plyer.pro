#-------------------------------------------------
#
# Project created by QtCreator 2018-03-31T22:04:41
#
#-------------------------------------------------

QT       += core gui charts
CONFIG +=qwt
 QMAKE_CXXFLAGS_WARN_OFF -= -Wunused-parameter
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
0
TARGET = QDtsis_Plyer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH +=  ../QtAV-master \
                ../QtAV-master/src \
                ../QtAV-master/src/QtAV \
                ../QtAV-master/widgets \
                ../QtAV-master/widgets/QtAVWidgets \

CONFIG(debug, debug|release) {
    LIBS += \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Debug/bin/ -lQtAVd1 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Debug/bin/ -lQtAVWidgetsd1 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Debug/bin/ -lavcodec-57 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Debug/bin/ -lavdevice-57 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Debug/bin/ -lavfilter-6 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Debug/bin/ -lavformat-57 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Debug/bin/ -lavresample-3 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Debug/bin/ -lavutil-55 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Debug/bin/ -ld3dcompiler_47 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Debug/bin/ -llibEGLd \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Debug/bin/ -llibgcc_s_dw2-1 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Debug/bin/ -llibGLESv2d \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Debug/bin/ -llibwinpthread-1 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Debug/bin/ -lopengl32sw \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Debug/bin/ -lpostproc-54 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Debug/bin/ -lswresample-2 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Debug/bin/ -lswscale-4 \
} else {
    LIBS += \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Release/bin/ -lQtAV1 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Release/bin/ -lQtAVWidgets1 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Release/bin/ -lavcodec-57 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Release/bin/ -lavdevice-57 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Release/bin/ -lavfilter-6 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Release/bin/ -lavformat-57 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Release/bin/ -lavresample-3 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Release/bin/ -lavutil-55 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Release/bin/ -ld3dcompiler_47 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Release/bin/ -llibEGL \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Release/bin/ -llibgcc_s_dw2-1 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Release/bin/ -llibGLESv2 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Release/bin/ -llibwinpthread-1 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Release/bin/ -lopengl32sw \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Release/bin/ -lpostproc-54 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Release/bin/ -lswresample-2 \
        -L../build-QtAV-Desktop_Qt_5_10_1_MinGW_32bit-Release/bin/ -lswscale-4 \
}

SOURCES += main.cpp\
        player.cpp \
    plot.cpp

HEADERS  += player.h \
    plot.h \
    settings.h

FORMS    += player.ui

DISTFILES += \
    video_bk.jpg \
    time.png
