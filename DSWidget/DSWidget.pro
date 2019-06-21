#-------------------------------------------------
#
# Project created by QtCreator 2019-06-05T10:29:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DSWidget
TEMPLATE = app


SOURCES += main.cpp\
        dswidget.cpp \
    Graph/adj_list.cpp \
    Graph/edge.cpp \
    Graph/fadecode.cpp \
    Graph/fadecodescene.cpp \
    Graph/graphwidget.cpp \
    Graph/map_scene.cpp \
    Graph/node.cpp \
    Graph/worker.cpp \
    Graph/adj_list.cpp \
    Graph/edge.cpp \
    Graph/fadecode.cpp \
    Graph/fadecodescene.cpp \
    Graph/graphwidget.cpp \
    Graph/map_scene.cpp \
    Graph/node.cpp \
    Graph/worker.cpp \
    EightQueens/fadecode.cpp \
    EightQueens/fadecodescene.cpp \
    EightQueens/queengrid.cpp \
    EightQueens/queenscene.cpp \
    EightQueens/rewidget.cpp \
    EightQueens/workthread.cpp \
    SortWidget/bucket.cpp \
    SortWidget/element.cpp \
    SortWidget/fadecode.cpp \
    SortWidget/fadecodescene.cpp \
    SortWidget/numberbox.cpp \
    SortWidget/radixscene.cpp \
    SortWidget/sortscene.cpp \
    SortWidget/sortwidget.cpp \
    HanoiTower/fadecode.cpp \
    HanoiTower/fadecodescene.cpp \
    HanoiTower/hanoidish.cpp \
    HanoiTower/hanoipillar.cpp \
    HanoiTower/hanoiscene.cpp \
    HanoiTower/hanoiwidget.cpp \
    infix2suffix/utils/arrow.cpp \
    infix2suffix/utils/mathExpValidator.cpp \
    infix2suffix/infix2suffix.cpp \
    infix2suffix/stacknode.cpp \
    linklist/utils/arrow.cpp \
    linklist/linklist.cpp \
    linklist/linknode.cpp \
    queue/utils/arrow.cpp \
    queue/queue.cpp \
    queue/queuenode.cpp \
    stack/utils/arrow.cpp \
    stack/stack.cpp \
    stack/stacknode.cpp
HEADERS  += dswidget.h \
    Graph/adj_list.h \
    Graph/edge.h \
    Graph/fadecode.h \
    Graph/fadecodescene.h \
    Graph/graphwidget.h \
    Graph/map_scene.h \
    Graph/node.h \
    Graph/ui_graphwidget.h \
    Graph/worker.h \
    ui_dswidget.h \
    EightQueens/fadecode.h \
    EightQueens/fadecodescene.h \
    EightQueens/queengrid.h \
    EightQueens/queenscene.h \
    EightQueens/rewidget.h \
    EightQueens/ui_rewidget.h \
    EightQueens/ui_widget.h \
    EightQueens/workthread.h \
    ui_graphwidget.h \
    SortWidget/bucket.h \
    SortWidget/element.h \
    SortWidget/fadecode.h \
    SortWidget/fadecodescene.h \
    SortWidget/numberbox.h \
    SortWidget/radixscene.h \
    SortWidget/sortscene.h \
    SortWidget/sortwidget.h \
    SortWidget/ui_sortwidget.h \
    HanoiTower/fadecode.h \
    HanoiTower/fadecodescene.h \
    HanoiTower/hanoidish.h \
    HanoiTower/hanoipillar.h \
    HanoiTower/hanoiscene.h \
    HanoiTower/hanoiwidget.h \
    HanoiTower/ui_hanoiwidget.h \
    infix2suffix/utils/arrow.h \
    infix2suffix/utils/mathExpValidator.h \
    infix2suffix/infix2suffix.h \
    infix2suffix/stacknode.h \
    linklist/utils/arrow.h \
    linklist/linklist.h \
    linklist/linknode.h \
    linklist/ui_linklist.h \
    queue/utils/arrow.h \
    queue/queue.h \
    queue/queuenode.h \
    queue/ui_queue.h \
    stack/utils/arrow.h \
    stack/stack.h \
    stack/stacknode.h \
    stack/ui_stack.h \
    ui_rewidget.h \
    ui_sortwidget.h \
    infix2suffix/ui_infix2suffix.h

FORMS    += dswidget.ui \
    Graph/graphwidget.ui \
    EightQueens/rewidget.ui \
    SortWidget/sortwidget.ui \
    HanoiTower/hanoiwidget.ui

DISTFILES += \
    Graph/data.txt \
    sytle.qss
