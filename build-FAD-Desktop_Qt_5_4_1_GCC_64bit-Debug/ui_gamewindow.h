/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <gamewidget.h>
#include "webcamwindow.h"

QT_BEGIN_NAMESPACE

class Ui_GameWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelName;
    QLabel *name;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelLevel;
    QLabel *level;
    QSpacerItem *horizontalSpacer_5;
    QLabel *labelTime;
    QLabel *time;
    QSpacerItem *horizontalSpacer_4;
    QLabel *labelTimeLevel;
    QLabel *timeLevel;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_8;
    GameWidget *myGame;
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

        labelName = new QLabel(GameWidget);
        labelName->setObjectName(QStringLiteral("labelName"));

        horizontalLayout->addWidget(labelName);

        name = new QLabel(GameWidget);
        name->setObjectName(QStringLiteral("name"));

        horizontalLayout->addWidget(name);

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

        labelTimeLevel = new QLabel(GameWidget);
        labelTimeLevel->setObjectName(QStringLiteral("labelTimeLevel"));

        horizontalLayout->addWidget(labelTimeLevel);

        timeLevel = new QLabel(GameWidget);
        timeLevel->setObjectName(QStringLiteral("timeLevel"));

        horizontalLayout->addWidget(timeLevel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        myGame = new GameWidget(GameWidget);
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
        labelName->setText(QApplication::translate("GameWidget", "Joueur: ", 0));
        name->setText(QApplication::translate("GameWidget", "Nom", 0));
        labelLevel->setText(QApplication::translate("GameWidget", "Niveau: ", 0));
        level->setText(QString());
        labelTime->setText(QApplication::translate("GameWidget", "Time:", 0));
        time->setText(QString());
        labelTimeLevel->setText(QApplication::translate("GameWidget", "TIme Level: ", 0));
        timeLevel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GameWidget: public Ui_GameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
