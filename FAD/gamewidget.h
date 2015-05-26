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
    QString getNamePlayer() {return namePlayer_;}
    void show(QString n);
public slots:
    void incrementChrono();
protected:
    void keyPressEvent(QKeyEvent *e);
private slots:
    void moveSphere(cv::Point handPoint);

    void on_buttonStart_clicked();

private:
    Ui::GameWidget *ui;
    cv::Point pointRef;
    QTime time_;
    QTimer *timerChrono_;
    int level_; // niveau de jeu

    void startChrono();
    QString namePlayer_; // nom du joueur
signals:
    void startPlay();
};

#endif // GAMEWIDGET_H
