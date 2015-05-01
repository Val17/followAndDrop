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
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    Game *myGame;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout;
    QPushButton *dropButton;
    QPushButton *targetButton;
    QPushButton *coordonateButton;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *xLabel;
    QLineEdit *xCoord;
    QHBoxLayout *horizontalLayout_3;
    QLabel *yLabel;
    QLineEdit *yCoord;
    QHBoxLayout *horizontalLayout_4;

    void setupUi(QWidget *GameWidget)
    {
        if (GameWidget->objectName().isEmpty())
            GameWidget->setObjectName(QStringLiteral("GameWidget"));
        GameWidget->resize(539, 413);
        verticalLayout_2 = new QVBoxLayout(GameWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        label = new QLabel(GameWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_7->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_7);

        myGame = new Game(GameWidget);
        myGame->setObjectName(QStringLiteral("myGame"));
        myGame->setMinimumSize(QSize(300, 300));

        verticalLayout->addWidget(myGame);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        dropButton = new QPushButton(GameWidget);
        dropButton->setObjectName(QStringLiteral("dropButton"));

        horizontalLayout->addWidget(dropButton);

        targetButton = new QPushButton(GameWidget);
        targetButton->setObjectName(QStringLiteral("targetButton"));

        horizontalLayout->addWidget(targetButton);

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

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));

        horizontalLayout_5->addLayout(horizontalLayout_4);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(verticalLayout);

        myGame->raise();
        label->raise();
        dropButton->raise();
        targetButton->raise();
        yCoord->raise();
        xCoord->raise();
        xLabel->raise();
        yLabel->raise();
        yCoord->raise();
        dropButton->raise();

        retranslateUi(GameWidget);

        QMetaObject::connectSlotsByName(GameWidget);
    } // setupUi

    void retranslateUi(QWidget *GameWidget)
    {
        GameWidget->setWindowTitle(QApplication::translate("GameWidget", "Game", 0));
        label->setText(QApplication::translate("GameWidget", "Follow and Drop", 0));
        dropButton->setText(QApplication::translate("GameWidget", "Drop", 0));
        targetButton->setText(QApplication::translate("GameWidget", "Target", 0));
        coordonateButton->setText(QApplication::translate("GameWidget", "Coordonate", 0));
        xLabel->setText(QApplication::translate("GameWidget", "x:", 0));
        yLabel->setText(QApplication::translate("GameWidget", "y:", 0));
    } // retranslateUi

};

namespace Ui {
    class GameWidget: public Ui_GameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
