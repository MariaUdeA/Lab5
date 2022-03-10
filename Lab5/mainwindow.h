#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "pacman.h"
#include "star.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include <vector>
#include <QGraphicsTextItem>
#include <QString>
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
    int prev_key=0;
    int hold_key=0;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    pacman *player;
    std::vector<QGraphicsPixmapItem*>stars;
    std::vector <std::vector <int>> posStar={{44,76},{332,300},{524,204},{332,44},{588,492},
                                             {140,492},{44,268},{588,364},{300,428},{44,556}};
    int score=0;
    QString text;
    QGraphicsTextItem *highScore;
    int numBarras=48;
    int vel=8;
    QTimer *timer;
    bool col_A=false;
    bool col_D=false;
    bool col_S=false;
    bool col_W=false;
    bool caseBreak=false;
    //dimX,dimY,posX,posY maxX=640 maxY=608
    std::vector<std::vector <int>> barras={{32,160,16,112},{288,32,176,48},{32,64,304,96},{160,32,112,176},{192,32,160,112},//1
                                           {32,32,240,144},{64,32,256,176},{288,32,496,48},{32,64,368,96},{32,352,624,240},//2
                                           {160,32,496,112},{32,64,432,160},{32,64,560,160},{64,32,352,176},{32,96,368,240},//3
                                           {32,64,496,192},{160,32,496,240},{32,96,560,304},{64,32,576,400},{32,64,432,320},//4
                                           {32,128,496,352},{32,32,464,400},{64,96,288,272},{64,96,352,368},{32,32,240,240},//5
                                           {32,32,400,400},{64,32,160,240},{32,96,144,304},{32,64,208,320},{96,32,48,240},//6
                                           {32,352,16,400},{256,32,160,592},{32,64,272,544},{192,32,544,464},{32,128,624,544},//7
                                           {288,32,464,592},{32,64,336,544},{32,128,272,416},{32,32,304,464},{64,32,384,464},//8
                                           {32,64,400,512},{160,32,496,528},{32,96,80,496},{128,32,160,528},{32,64,208,480},//9
                                           {32,128,80,352},{128,32,160,400},{32,64,144,448}};
    std::vector <QGraphicsRectItem *> map;
};
#endif // MAINWINDOW_H
