#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <gamewidget.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_gameButton_clicked();
    void on_gameButton_pressed();
    void on_quitButton_clicked();
    void on_newGameAction_clicked();
    void on_quitAction_clicked();

private:
    Ui::MainWindow *ui;
    GameWidget myGameWidget;


};

#endif // MAINWINDOW_H
