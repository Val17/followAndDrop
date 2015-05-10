/********************************************************************************
** Form generated from reading UI file 'gamewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
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
    QHBoxLayout *horizontalLayout_5;
    QPushButton *reinitializeButton;
    QPushButton *menuButton;

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


        horizontalLayout_6->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        reinitializeButton = new QPushButton(GameWidget);
        reinitializeButton->setObjectName(QStringLiteral("reinitializeButton"));

        horizontalLayout_5->addWidget(reinitializeButton);

        menuButton = new QPushButton(GameWidget);
        menuButton->setObjectName(QStringLiteral("menuButton"));

        horizontalLayout_5->addWidget(menuButton);


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
        reinitializeButton->setText(QApplication::translate("GameWidget", "Reinitialize", 0));
        menuButton->setText(QApplication::translate("GameWidget", "Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class GameWidget: public Ui_GameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
