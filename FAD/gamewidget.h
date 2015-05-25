#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <webcamwindow.h>

namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = 0);
    ~GameWidget();
    void setNamePlayer(QString n) {namePlayer_=n;}
public slots:
    void incrementChrono();
protected:
    void keyPressEvent(QKeyEvent *e);
private slots:
    void moveSphere(cv::Point handPoint);

private:
    Ui::GameWidget *ui;
    cv::Point pointRef;
    int time_;
    QTimer *timerChrono_;

    void startChrono();
    QString namePlayer_; // nom du joueur
signals:
    void startPlay();
};

#endif // GAMEWIDGET_H
