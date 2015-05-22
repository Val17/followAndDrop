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
protected:
    void keyPressEvent(QKeyEvent *e);
private slots:

private:
    Ui::GameWidget *ui;
};

#endif // GAMEWIDGET_H
