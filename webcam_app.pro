#-------------------------------------------------
#
# Project created by QtCreator 2020-06-06T15:32:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = webcam_app
TEMPLATE = app
CONFIG +=c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui


INCLUDEPATH += /opt/qt5pix/sysroot/usr/include \
               /opt/qt5pix/sysroot/usr/local/include/opencv4

LIBS += -L/opt/qt5pix/sysroot/usr/local/lib -lopencv_calib3d \
         -lopencv_core \
         -lopencv_features2d \
         -lopencv_flann \
         -lopencv_highgui \
         -lopencv_imgcodecs \
         -lopencv_imgproc \
         -lopencv_ml \
         -lopencv_objdetect \
         -lopencv_photo \
         -lopencv_shape \
         -lopencv_stitching \
         -lopencv_superres \
         -lopencv_video \
         -lopencv_videoio \
         -lopencv_videostab \
         -lopencv_optflow \
         -lopencv_ximgproc \
         -lopencv_xfeatures2d

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /home/pi/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
