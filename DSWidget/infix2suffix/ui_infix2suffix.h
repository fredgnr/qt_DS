/********************************************************************************
** Form generated from reading UI file 'infix2suffix.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFIX2SUFFIX_H
#define UI_INFIX2SUFFIX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Infix2Suffix
{
public:
    QGridLayout *gridLayout;
    QSplitter *vSplitter;
    QSplitter *hSplitter;
    QTextBrowser *textBrowser;
    QGraphicsView *graphicsView;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *infixEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *convertButton;
    QPushButton *clearButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *suffixEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *statusEdit;

    void setupUi(QWidget *Infix2Suffix)
    {
        if (Infix2Suffix->objectName().isEmpty())
            Infix2Suffix->setObjectName(QStringLiteral("Infix2Suffix"));
        Infix2Suffix->setWindowModality(Qt::ApplicationModal);
        Infix2Suffix->resize(800, 800);
        gridLayout = new QGridLayout(Infix2Suffix);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        vSplitter = new QSplitter(Infix2Suffix);
        vSplitter->setObjectName(QStringLiteral("vSplitter"));
        vSplitter->setOrientation(Qt::Vertical);
        hSplitter = new QSplitter(vSplitter);
        hSplitter->setObjectName(QStringLiteral("hSplitter"));
        hSplitter->setOrientation(Qt::Horizontal);
        textBrowser = new QTextBrowser(hSplitter);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        hSplitter->addWidget(textBrowser);
        graphicsView = new QGraphicsView(hSplitter);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        hSplitter->addWidget(graphicsView);
        vSplitter->addWidget(hSplitter);
        widget = new QWidget(vSplitter);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        infixEdit = new QLineEdit(widget);
        infixEdit->setObjectName(QStringLiteral("infixEdit"));

        horizontalLayout->addWidget(infixEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        convertButton = new QPushButton(widget);
        convertButton->setObjectName(QStringLiteral("convertButton"));

        horizontalLayout_2->addWidget(convertButton);

        clearButton = new QPushButton(widget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        horizontalLayout_2->addWidget(clearButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        suffixEdit = new QLineEdit(widget);
        suffixEdit->setObjectName(QStringLiteral("suffixEdit"));

        horizontalLayout_3->addWidget(suffixEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        statusEdit = new QLineEdit(widget);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));

        horizontalLayout_4->addWidget(statusEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        vSplitter->addWidget(widget);

        gridLayout->addWidget(vSplitter, 0, 0, 1, 1);


        retranslateUi(Infix2Suffix);

        QMetaObject::connectSlotsByName(Infix2Suffix);
    } // setupUi

    void retranslateUi(QWidget *Infix2Suffix)
    {
        Infix2Suffix->setWindowTitle(QApplication::translate("Infix2Suffix", "\344\270\255\347\274\200\350\275\254\345\220\216\347\274\200", 0));
        label->setText(QApplication::translate("Infix2Suffix", "\344\270\255\347\274\200\350\241\250\350\276\276\345\274\217\357\274\232", 0));
        convertButton->setText(QApplication::translate("Infix2Suffix", "\344\270\255\347\274\200\350\275\254\345\220\216\347\274\200", 0));
        clearButton->setText(QApplication::translate("Infix2Suffix", "\346\270\205\347\251\272", 0));
        label_2->setText(QApplication::translate("Infix2Suffix", "\345\220\216\347\274\200\350\241\250\350\276\276\345\274\217\357\274\232", 0));
        label_3->setText(QApplication::translate("Infix2Suffix", "\347\212\266\346\200\201\346\217\220\347\244\272\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class Infix2Suffix: public Ui_Infix2Suffix {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFIX2SUFFIX_H
