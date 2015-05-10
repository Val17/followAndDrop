/********************************************************************************
** Form generated from reading UI file 'gamewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWIDGET_H
#define UI_GAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "game.h"

QT_BEGIN_NAMESPACE

class Ui_GameWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_8;
    Game *myGame;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout;
    QPushButton *dropButton;
    QPushButton *sphereButton;
    QPushButton *coordonateButton;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *xLabel;
    QLineEdit *xCoord;
    QHBoxLayout *horizontalLayout_3;
    QLabel *yLabel;
    QLineEdit *yCoord;
    QPushButton *menuButton;
    QHBoxLayout *horizontalLayout_4;

    void setupUi(QWidget *GameWidget)
    {
        if (GameWidget->objectName().isEmpty())
            GameWidget->setObjectName(QStringLiteral("GameWidget"));
        GameWidget->resize(689, 396);
        verticalLayout_2 = new QVBoxLayout(GameWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        label = new QLabel(GameWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_8->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_8);

        myGame = new Game(GameWidget);
        myGame->setObjectName(QStringLiteral("myGame"));
        myGame->setMinimumSize(QSize(500, 300));
        myGame->setMaximumSize(QSize(700, 700));

        horizontalLayout_10->addWidget(myGame);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_7);


        horizontalLayout_11->addLayout(horizontalLayout_10);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        dropButton = new QPushButton(GameWidget);
        dropButton->setObjectName(QStringLiteral("dropButton"));

        horizontalLayout->addWidget(dropButton);

        sphereButton = new QPushButton(GameWidget);
        sphereButton->setObjectName(QStringLiteral("sphereButton"));
        sphereButton->setAutoDefault(true);

        horizontalLayout->addWidget(sphereButton);

        coordonateButton = new QPushButton(GameWidget);
        coordonateButton->setObjectName(QStringLiteral("coordonateButton"));

        horizontalLayout->addWidget(coordonateButton);


        horizontalLayout_6->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        xLabel = new QLabel(GameWidget);
        xLabel->setObjectName(QStringLiteral("xLabel"));

        horizontalLayout_2->addWidget(xLabel);

        xCoord = new QLineEdit(GameWidget);
        xCoord->setObjectName(QStringLiteral("xCoord"));
        xCoord->setEnabled(false);

        horizontalLayout_2->addWidget(xCoord);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        yLabel = new QLabel(GameWidget);
        yLabel->setObjectName(QStringLiteral("yLabel"));

        horizontalLayout_3->addWidget(yLabel);

        yCoord = new QLineEdit(GameWidget);
        yCoord->setObjectName(QStringLiteral("yCoord"));
        yCoord->setEnabled(false);

        horizontalLayout_3->addWidget(yCoord);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        menuButton = new QPushButton(GameWidget);
        menuButton->setObjectName(QStringLiteral("menuButton"));

        horizontalLayout_5->addWidget(menuButton);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));

        horizontalLayout_5->addLayout(horizontalLayout_4);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(horizontalLayout_6);


        retranslateUi(GameWidget);

        QMetaObject::connectSlotsByName(GameWidget);
    } // setupUi

    void retranslateUi(QWidget *GameWidget)
    {
        GameWidget->setWindowTitle(QApplication::translate("GameWidget", "Game", 0));
        label->setText(QApplication::translate("GameWidget", "Follow and Drop", 0));
        dropButton->setText(QApplication::translate("GameWidget", "Drop", 0));
        sphereButton->setText(QApplication::translate("GameWidget", "Sphere", 0));
        coordonateButton->setText(QApplication::translate("GameWidget", "Coordonate", 0));
        xLabel->setText(QApplication::translate("GameWidget", "x:", 0));
        yLabel->setText(QApplication::translate("GameWidget", "y:", 0));
        menuButton->setText(QApplication::translate("GameWidget", "Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class GameWidget: public Ui_GameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
