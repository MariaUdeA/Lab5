#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "pacman.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include <vector>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);
private slots:
    //void hmov();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    pacman *player;
    int numBarras=18;
    int vel=8;
    QTimer *timer;
    bool col_A=false;
    bool col_D=false;
    bool col_S=false;
    bool col_W=false;
    bool caseBreak=false;
    //dimX,dimY,posX,posY
    std::vector<std::vector <int>> barras={{32,160,16,112},{288,32,176,48},{32,64,304,96},{160,32,112,176},{192,32,160,112},
                                           {32,32,240,144},{64,32,256,176},{288,32,496,48},{32,64,368,96},{32,352,624,240},
                                           {160,32,496,112},{32,64,432,160},{32,64,560,160},{64,32,352,176},{32,96,368,240},
                                           {32,64,496,192},{160,32,496,240},{32,96,560,304}};
    std::vector <QGraphicsRectItem *> map;
};
#endif // MAINWINDOW_H
