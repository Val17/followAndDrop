#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <webcamwindow.h>
#include "ui_gamewidget.h"

namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = 0);
    ~GameWidget();
protected:
    void keyPressEvent(QKeyEvent *e);
private slots:
    void moveSphere(cv::Point handPoint);

private:
    Ui::GameWidget *ui;
    cv::Point pointRef;
};

#endif // GAMEWIDGET_H
