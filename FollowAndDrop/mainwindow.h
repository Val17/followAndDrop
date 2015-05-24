#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <gamewidget.h>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include "ui_mainwindow.h"
#include <QtWidgets>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGraphicsScene myScene;

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_gameButton_clicked();

private:
    Ui::MainWindow *ui;
    GameWidget myGameWidget;


};

#endif // MAINWINDOW_H
