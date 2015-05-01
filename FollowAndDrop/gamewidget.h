#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>

namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = 0);
    ~GameWidget();

private slots:
    void on_dropButton_clicked();

private:
    Ui::GameWidget *ui;
};

#endif // GAMEWIDGET_H
