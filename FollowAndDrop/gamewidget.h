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
    int xCoord; // Coordonnee x de l'endroit ou l'on clique
    int yCoord; // Coordonnee y de l'endroit ou l'on clique
    int zCoord; // Coordonnee z de l'endroit ou l'on clique


protected:
    void keyPressEvent(QKeyEvent *e);
private slots:
    void on_dropButton_clicked();
    void on_targetButton_clicked();


    void on_coordonateButton_clicked();

    void on_menuButton_clicked();


private:
    Ui::GameWidget *ui;
};

#endif // GAMEWIDGET_H
