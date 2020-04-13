#-------------------------------------------------
#
# Project created by QtCreator 2020-04-06T23:52:38
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtDemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    conf/applicationconfig.cpp \
    other/cjson/cJSON.cpp \
    sql/mytable.cpp \
    ui/buttoncircle.cpp \
    ui/buttonradiogroup.cpp \
    ui/downfileprogress.cpp \
    ui/goodsitem.cpp \
    ui/numkeyboard.cpp \
    ui/signallight.cpp \
    ui/statusbar.cpp \
    ui/switchbutton.cpp \
    ui/virtualkeyboard.cpp \
    util/fileutil.cpp \
    util/httputil.cpp \
    util/jsonutil.cpp \
    util/object.cpp \
    util/sqldatabaseutil.cpp \
    util/sqltableutil.cpp \
    util/upgradeutil.cpp \
    widget/baseapplication.cpp \
    widget/basewidget.cpp \
    widget/dialoginstance.cpp \
    widget/ensuredialog.cpp \
    widget/goodsgrid.cpp \
    widget/numinputdialog.cpp \
    widget/toast.cpp \
    pickupcode.cpp \
    putouttip.cpp \
    other/qrencode-3.4.4/tests/create_frame_pattern.c \
    other/qrencode-3.4.4/tests/create_mqr_frame_pattern.c \
    other/qrencode-3.4.4/tests/decoder.c \
    other/qrencode-3.4.4/tests/prof_qrencode.c \
    other/qrencode-3.4.4/tests/pthread_qrencode.c \
    other/qrencode-3.4.4/tests/test_bitstream.c \
    other/qrencode-3.4.4/tests/test_estimatebit.c \
    other/qrencode-3.4.4/tests/test_mask.c \
    other/qrencode-3.4.4/tests/test_mmask.c \
    other/qrencode-3.4.4/tests/test_mqrspec.c \
    other/qrencode-3.4.4/tests/test_qrencode.c \
    other/qrencode-3.4.4/tests/test_qrinput.c \
    other/qrencode-3.4.4/tests/test_rs.c \
    other/qrencode-3.4.4/tests/test_split.c \
    other/qrencode-3.4.4/bitstream.c \
    other/qrencode-3.4.4/mask.c \
    other/qrencode-3.4.4/mmask.c \
    other/qrencode-3.4.4/mqrspec.c \
    other/qrencode-3.4.4/qrenc.c \
    other/qrencode-3.4.4/qrencode.c \
    other/qrencode-3.4.4/qrinput.c \
    other/qrencode-3.4.4/qrspec.c \
    other/qrencode-3.4.4/rscode.c \
    other/qrencode-3.4.4/split.c

HEADERS  += mainwindow.h \
    conf/applicationconfig.h \
    other/cjson/cJSON.h \
    other/qrencode-3.4.4/tests/common.h \
    other/qrencode-3.4.4/tests/decoder.h \
    other/qrencode-3.4.4/bitstream.h \
    other/qrencode-3.4.4/config.h \
    other/qrencode-3.4.4/mask.h \
    other/qrencode-3.4.4/mmask.h \
    other/qrencode-3.4.4/mqrspec.h \
    other/qrencode-3.4.4/qrencode.h \
    other/qrencode-3.4.4/qrencode_inner.h \
    other/qrencode-3.4.4/qrinput.h \
    other/qrencode-3.4.4/qrspec.h \
    other/qrencode-3.4.4/rscode.h \
    other/qrencode-3.4.4/split.h \
    sql/mytable.h \
    ui/buttoncircle.h \
    ui/buttonradiogroup.h \
    ui/downfileprogress.h \
    ui/goodsitem.h \
    ui/numkeyboard.h \
    ui/signallight.h \
    ui/statusbar.h \
    ui/switchbutton.h \
    ui/virtualkeyboard.h \
    util/fileutil.h \
    util/httputil.h \
    util/jsonutil.h \
    util/object.h \
    util/sqldatabaseutil.h \
    util/sqltableutil.h \
    util/upgradeutil.h \
    widget/baseapplication.h \
    widget/basewidget.h \
    widget/dialoginstance.h \
    widget/ensuredialog.h \
    widget/goodsgrid.h \
    widget/numinputdialog.h \
    widget/toast.h \
    pickupcode.h \
    putouttip.h

#LIBS +=-L$$PWD/ -lqrencode

FORMS    += mainwindow.ui

CONFIG += C++11
