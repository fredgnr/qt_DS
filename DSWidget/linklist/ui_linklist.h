/********************************************************************************
** Form generated from reading UI file 'linklist.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINKLIST_H
#define UI_LINKLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_linkList
{
public:
    QGridLayout *gridLayout;
    QSplitter *hSplitter;
    QSplitter *vSplitter;
    QGraphicsView *graphicsView;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *initButton;
    QPushButton *clearButton;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QLabel *insertLocationLabel;
    QComboBox *insertComboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *insertNumberLabel;
    QLineEdit *insertNumberEdit;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *insertButton;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *deleteLocationLabel;
    QComboBox *deleteComboBox;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *deleteButton;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *searchNumberLabel;
    QLineEdit *searchNumberEdit;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *searchButton;
    QHBoxLayout *horizontalLayout_9;
    QLabel *searchResultLabel;
    QLineEdit *searchResultEdit;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *statusLabel;
    QLineEdit *statusEdit;

    void setupUi(QWidget *linkList)
    {
        if (linkList->objectName().isEmpty())
            linkList->setObjectName(QStringLiteral("linkList"));
        linkList->setWindowModality(Qt::ApplicationModal);
        linkList->resize(800, 800);
        gridLayout = new QGridLayout(linkList);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        hSplitter = new QSplitter(linkList);
        hSplitter->setObjectName(QStringLiteral("hSplitter"));
        hSplitter->setOrientation(Qt::Horizontal);
        vSplitter = new QSplitter(hSplitter);
        vSplitter->setObjectName(QStringLiteral("vSplitter"));
        vSplitter->setOrientation(Qt::Vertical);
        graphicsView = new QGraphicsView(vSplitter);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        vSplitter->addWidget(graphicsView);
        hSplitter->addWidget(vSplitter);
        layoutWidget = new QWidget(hSplitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        initButton = new QPushButton(layoutWidget);
        initButton->setObjectName(QStringLiteral("initButton"));

        horizontalLayout->addWidget(initButton);

        clearButton = new QPushButton(layoutWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        horizontalLayout->addWidget(clearButton);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        insertLocationLabel = new QLabel(layoutWidget);
        insertLocationLabel->setObjectName(QStringLiteral("insertLocationLabel"));

        horizontalLayout_2->addWidget(insertLocationLabel);

        insertComboBox = new QComboBox(layoutWidget);
        insertComboBox->setObjectName(QStringLiteral("insertComboBox"));

        horizontalLayout_2->addWidget(insertComboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        insertNumberLabel = new QLabel(layoutWidget);
        insertNumberLabel->setObjectName(QStringLiteral("insertNumberLabel"));

        horizontalLayout_3->addWidget(insertNumberLabel);

        insertNumberEdit = new QLineEdit(layoutWidget);
        insertNumberEdit->setObjectName(QStringLiteral("insertNumberEdit"));

        horizontalLayout_3->addWidget(insertNumberEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        insertButton = new QPushButton(layoutWidget);
        insertButton->setObjectName(QStringLiteral("insertButton"));

        horizontalLayout_4->addWidget(insertButton);


        verticalLayout->addLayout(horizontalLayout_4);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        deleteLocationLabel = new QLabel(layoutWidget);
        deleteLocationLabel->setObjectName(QStringLiteral("deleteLocationLabel"));

        horizontalLayout_5->addWidget(deleteLocationLabel);

        deleteComboBox = new QComboBox(layoutWidget);
        deleteComboBox->setObjectName(QStringLiteral("deleteComboBox"));

        horizontalLayout_5->addWidget(deleteComboBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        deleteButton = new QPushButton(layoutWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        horizontalLayout_6->addWidget(deleteButton);


        verticalLayout->addLayout(horizontalLayout_6);

        line_4 = new QFrame(layoutWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        searchNumberLabel = new QLabel(layoutWidget);
        searchNumberLabel->setObjectName(QStringLiteral("searchNumberLabel"));

        horizontalLayout_7->addWidget(searchNumberLabel);

        searchNumberEdit = new QLineEdit(layoutWidget);
        searchNumberEdit->setObjectName(QStringLiteral("searchNumberEdit"));

        horizontalLayout_7->addWidget(searchNumberEdit);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        searchButton = new QPushButton(layoutWidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));

        horizontalLayout_8->addWidget(searchButton);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        searchResultLabel = new QLabel(layoutWidget);
        searchResultLabel->setObjectName(QStringLiteral("searchResultLabel"));

        horizontalLayout_9->addWidget(searchResultLabel);

        searchResultEdit = new QLineEdit(layoutWidget);
        searchResultEdit->setObjectName(QStringLiteral("searchResultEdit"));

        horizontalLayout_9->addWidget(searchResultEdit);


        verticalLayout->addLayout(horizontalLayout_9);

        line_3 = new QFrame(layoutWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        statusLabel = new QLabel(layoutWidget);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));

        horizontalLayout_10->addWidget(statusLabel);

        statusEdit = new QLineEdit(layoutWidget);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));

        horizontalLayout_10->addWidget(statusEdit);


        verticalLayout->addLayout(horizontalLayout_10);

        hSplitter->addWidget(layoutWidget);

        gridLayout->addWidget(hSplitter, 0, 0, 1, 1);


        retranslateUi(linkList);

        QMetaObject::connectSlotsByName(linkList);
    } // setupUi

    void retranslateUi(QWidget *linkList)
    {
        linkList->setWindowTitle(QApplication::translate("linkList", "\345\215\225\351\223\276\350\241\250", 0));
        initButton->setText(QApplication::translate("linkList", "\345\210\233\345\273\272/\345\210\235\345\247\213\345\214\226", 0));
        clearButton->setText(QApplication::translate("linkList", "\346\270\205\347\251\272", 0));
        insertLocationLabel->setText(QApplication::translate("linkList", "\346\217\222\345\205\245\344\275\215\347\275\256\357\274\232", 0));
        insertNumberLabel->setText(QApplication::translate("linkList", "\346\217\222\345\205\245\345\205\203\347\264\240\345\200\274\357\274\210int\357\274\211\357\274\232", 0));
        insertButton->setText(QApplication::translate("linkList", "\346\217\222\345\205\245\345\205\203\347\264\240", 0));
        deleteLocationLabel->setText(QApplication::translate("linkList", "\345\210\240\351\231\244\344\275\215\347\275\256\357\274\232", 0));
        deleteButton->setText(QApplication::translate("linkList", "\345\210\240\351\231\244\345\205\203\347\264\240", 0));
        searchNumberLabel->setText(QApplication::translate("linkList", "\346\237\245\346\211\276\345\205\203\347\264\240\345\200\274\357\274\210int\357\274\211\357\274\232", 0));
        searchButton->setText(QApplication::translate("linkList", "\346\237\245\346\211\276\345\205\203\347\264\240", 0));
        searchResultLabel->setText(QApplication::translate("linkList", "\346\237\245\350\257\242\347\273\223\346\236\234\357\274\232", 0));
        statusLabel->setText(QApplication::translate("linkList", "\347\212\266\346\200\201\346\217\220\347\244\272\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class linkList: public Ui_linkList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINKLIST_H
