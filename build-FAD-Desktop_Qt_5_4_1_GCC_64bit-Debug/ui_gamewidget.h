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
#include "webcamwindow.h"

QT_BEGIN_NAMESPACE

class Ui_GameWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelLevel;
    QLabel *level;
    QSpacerItem *horizontalSpacer_5;
    QLabel *labelTime;
    QLabel *time;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *buttonStart;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_8;
    Game *myGame;
    QSpacerItem *horizontalSpacer_7;
    WebCamWindow *webcamWidget;

    void setupUi(QWidget *GameWidget)
    {
        if (GameWidget->objectName().isEmpty())
            GameWidget->setObjectName(QStringLiteral("GameWidget"));
        GameWidget->resize(1216, 578);
        verticalLayout_2 = new QVBoxLayout(GameWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(GameWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        labelLevel = new QLabel(GameWidget);
        labelLevel->setObjectName(QStringLiteral("labelLevel"));

        horizontalLayout->addWidget(labelLevel);

        level = new QLabel(GameWidget);
        level->setObjectName(QStringLiteral("level"));
        level->setEnabled(false);

        horizontalLayout->addWidget(level);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        labelTime = new QLabel(GameWidget);
        labelTime->setObjectName(QStringLiteral("labelTime"));

        horizontalLayout->addWidget(labelTime);

        time = new QLabel(GameWidget);
        time->setObjectName(QStringLiteral("time"));
        time->setMinimumSize(QSize(10, 10));

        horizontalLayout->addWidget(time);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        buttonStart = new QPushButton(GameWidget);
        buttonStart->setObjectName(QStringLiteral("buttonStart"));

        horizontalLayout->addWidget(buttonStart);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        myGame = new Game(GameWidget);
        myGame->setObjectName(QStringLiteral("myGame"));
        myGame->setMinimumSize(QSize(500, 300));
        myGame->setMaximumSize(QSize(700, 700));

        horizontalLayout_2->addWidget(myGame);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        webcamWidget = new WebCamWindow(GameWidget);
        webcamWidget->setObjectName(QStringLiteral("webcamWidget"));
        webcamWidget->setMinimumSize(QSize(600, 500));

        horizontalLayout_2->addWidget(webcamWidget);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(GameWidget);

        QMetaObject::connectSlotsByName(GameWidget);
    } // setupUi

    void retranslateUi(QWidget *GameWidget)
    {
        GameWidget->setWindowTitle(QApplication::translate("GameWidget", "Follow And Drop - Jeu", 0));
        label->setText(QApplication::translate("GameWidget", "Follow And Drop", 0));
        labelLevel->setText(QApplication::translate("GameWidget", "Niveau: ", 0));
        level->setText(QString());
        labelTime->setText(QApplication::translate("GameWidget", "Time:", 0));
        time->setText(QString());
        buttonStart->setText(QApplication::translate("GameWidget", "Start", 0));
    } // retranslateUi

};

namespace Ui {
    class GameWidget: public Ui_GameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
