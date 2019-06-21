/********************************************************************************
** Form generated from reading UI file 'dswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DSWIDGET_H
#define UI_DSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DSWidget
{
public:
    QPushButton *sortptn;
    QPushButton *queenptn;
    QPushButton *honoiptn;
    QPushButton *graphptn;
    QPushButton *linkptn;
    QPushButton *stackptn;
    QPushButton *queueptn;
    QPushButton *infixptn;

    void setupUi(QWidget *DSWidget)
    {
        if (DSWidget->objectName().isEmpty())
            DSWidget->setObjectName(QStringLiteral("DSWidget"));
        DSWidget->resize(1800, 825);
        sortptn = new QPushButton(DSWidget);
        sortptn->setObjectName(QStringLiteral("sortptn"));
        sortptn->setGeometry(QRect(0, 0, 100, 70));
        sortptn->setCheckable(true);
        queenptn = new QPushButton(DSWidget);
        queenptn->setObjectName(QStringLiteral("queenptn"));
        queenptn->setGeometry(QRect(0, 70, 100, 70));
        queenptn->setCheckable(true);
        honoiptn = new QPushButton(DSWidget);
        honoiptn->setObjectName(QStringLiteral("honoiptn"));
        honoiptn->setGeometry(QRect(0, 140, 100, 70));
        honoiptn->setCheckable(true);
        graphptn = new QPushButton(DSWidget);
        graphptn->setObjectName(QStringLiteral("graphptn"));
        graphptn->setGeometry(QRect(0, 210, 100, 70));
        graphptn->setCheckable(true);
        linkptn = new QPushButton(DSWidget);
        linkptn->setObjectName(QStringLiteral("linkptn"));
        linkptn->setGeometry(QRect(0, 280, 100, 70));
        stackptn = new QPushButton(DSWidget);
        stackptn->setObjectName(QStringLiteral("stackptn"));
        stackptn->setGeometry(QRect(0, 350, 100, 70));
        queueptn = new QPushButton(DSWidget);
        queueptn->setObjectName(QStringLiteral("queueptn"));
        queueptn->setGeometry(QRect(0, 420, 100, 70));
        infixptn = new QPushButton(DSWidget);
        infixptn->setObjectName(QStringLiteral("infixptn"));
        infixptn->setGeometry(QRect(0, 490, 100, 70));

        retranslateUi(DSWidget);

        QMetaObject::connectSlotsByName(DSWidget);
    } // setupUi

    void retranslateUi(QWidget *DSWidget)
    {
        DSWidget->setWindowTitle(QApplication::translate("DSWidget", "DSWidget", 0));
        sortptn->setText(QApplication::translate("DSWidget", "\346\216\222\345\272\217", 0));
        queenptn->setText(QApplication::translate("DSWidget", "\345\205\253\347\232\207\345\220\216", 0));
        honoiptn->setText(QApplication::translate("DSWidget", "\346\261\211\350\257\272\345\241\224", 0));
        graphptn->setText(QApplication::translate("DSWidget", "\345\233\276", 0));
        linkptn->setText(QApplication::translate("DSWidget", "\351\223\276\350\241\250", 0));
        stackptn->setText(QApplication::translate("DSWidget", "\346\240\210", 0));
        queueptn->setText(QApplication::translate("DSWidget", "\351\230\237\345\210\227", 0));
        infixptn->setText(QApplication::translate("DSWidget", "\344\270\255\347\274\200\350\275\254\345\220\216\347\274\200", 0));
    } // retranslateUi

};

namespace Ui {
    class DSWidget: public Ui_DSWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DSWIDGET_H
