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
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_8;
    Game *myGame;
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelAlpha;
    QPushButton *buttonA;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelBeta;
    QPushButton *buttonB;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelGamma;
    QPushButton *buttonG;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelAngleSphere;
    QPushButton *buttonS;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelXSphere;
    QPushButton *buttonXSphere;
    QHBoxLayout *horizontalLayout_10;
    QLabel *labelYSphere;
    QPushButton *buttonYSphere;
    QHBoxLayout *horizontalLayout;
    QPushButton *sphereButton;
    QPushButton *catchButton;
    QPushButton *reinitializeButton;

    void setupUi(QWidget *GameWidget)
    {
        if (GameWidget->objectName().isEmpty())
            GameWidget->setObjectName(QStringLiteral("GameWidget"));
        GameWidget->resize(678, 410);
        verticalLayout_3 = new QVBoxLayout(GameWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
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

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);

        myGame = new Game(GameWidget);
        myGame->setObjectName(QStringLiteral("myGame"));
        myGame->setMinimumSize(QSize(500, 300));
        myGame->setMaximumSize(QSize(700, 700));

        horizontalLayout_5->addWidget(myGame);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelAlpha = new QLabel(GameWidget);
        labelAlpha->setObjectName(QStringLiteral("labelAlpha"));

        horizontalLayout_2->addWidget(labelAlpha);

        buttonA = new QPushButton(GameWidget);
        buttonA->setObjectName(QStringLiteral("buttonA"));

        horizontalLayout_2->addWidget(buttonA);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelBeta = new QLabel(GameWidget);
        labelBeta->setObjectName(QStringLiteral("labelBeta"));

        horizontalLayout_4->addWidget(labelBeta);

        buttonB = new QPushButton(GameWidget);
        buttonB->setObjectName(QStringLiteral("buttonB"));

        horizontalLayout_4->addWidget(buttonB);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelGamma = new QLabel(GameWidget);
        labelGamma->setObjectName(QStringLiteral("labelGamma"));

        horizontalLayout_3->addWidget(labelGamma);

        buttonG = new QPushButton(GameWidget);
        buttonG->setObjectName(QStringLiteral("buttonG"));

        horizontalLayout_3->addWidget(buttonG);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelAngleSphere = new QLabel(GameWidget);
        labelAngleSphere->setObjectName(QStringLiteral("labelAngleSphere"));

        horizontalLayout_7->addWidget(labelAngleSphere);

        buttonS = new QPushButton(GameWidget);
        buttonS->setObjectName(QStringLiteral("buttonS"));

        horizontalLayout_7->addWidget(buttonS);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        labelXSphere = new QLabel(GameWidget);
        labelXSphere->setObjectName(QStringLiteral("labelXSphere"));

        horizontalLayout_9->addWidget(labelXSphere);

        buttonXSphere = new QPushButton(GameWidget);
        buttonXSphere->setObjectName(QStringLiteral("buttonXSphere"));

        horizontalLayout_9->addWidget(buttonXSphere);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        labelYSphere = new QLabel(GameWidget);
        labelYSphere->setObjectName(QStringLiteral("labelYSphere"));

        horizontalLayout_10->addWidget(labelYSphere);

        buttonYSphere = new QPushButton(GameWidget);
        buttonYSphere->setObjectName(QStringLiteral("buttonYSphere"));

        horizontalLayout_10->addWidget(buttonYSphere);


        verticalLayout->addLayout(horizontalLayout_10);


        horizontalLayout_5->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        sphereButton = new QPushButton(GameWidget);
        sphereButton->setObjectName(QStringLiteral("sphereButton"));
        sphereButton->setAutoDefault(true);

        horizontalLayout->addWidget(sphereButton);

        catchButton = new QPushButton(GameWidget);
        catchButton->setObjectName(QStringLiteral("catchButton"));

        horizontalLayout->addWidget(catchButton);

        reinitializeButton = new QPushButton(GameWidget);
        reinitializeButton->setObjectName(QStringLiteral("reinitializeButton"));

        horizontalLayout->addWidget(reinitializeButton);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        labelAlpha->raise();
        buttonB->raise();
        buttonG->raise();
        buttonS->raise();

        retranslateUi(GameWidget);

        QMetaObject::connectSlotsByName(GameWidget);
    } // setupUi

    void retranslateUi(QWidget *GameWidget)
    {
        GameWidget->setWindowTitle(QApplication::translate("GameWidget", "Game", 0));
        label->setText(QApplication::translate("GameWidget", "Follow and Drop", 0));
        labelAlpha->setText(QApplication::translate("GameWidget", "alpha", 0));
        buttonA->setText(QApplication::translate("GameWidget", "a", 0));
        labelBeta->setText(QApplication::translate("GameWidget", "beta", 0));
        buttonB->setText(QApplication::translate("GameWidget", "b", 0));
        labelGamma->setText(QApplication::translate("GameWidget", "gamma", 0));
        buttonG->setText(QApplication::translate("GameWidget", "g", 0));
        labelAngleSphere->setText(QApplication::translate("GameWidget", "angleSphere", 0));
        buttonS->setText(QApplication::translate("GameWidget", "s", 0));
        labelXSphere->setText(QApplication::translate("GameWidget", "xSphere", 0));
        buttonXSphere->setText(QApplication::translate("GameWidget", "x", 0));
        labelYSphere->setText(QApplication::translate("GameWidget", "ySphere", 0));
        buttonYSphere->setText(QApplication::translate("GameWidget", "y", 0));
        sphereButton->setText(QApplication::translate("GameWidget", "Sphere", 0));
        catchButton->setText(QApplication::translate("GameWidget", "Catch", 0));
        reinitializeButton->setText(QApplication::translate("GameWidget", "Reinitialize", 0));
    } // retranslateUi

};

namespace Ui {
    class GameWidget: public Ui_GameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
