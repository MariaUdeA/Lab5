#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,640,608);//define tamaño escena
    ui->graphicsView->setScene(scene); //Muestra la escena
    scene->addRect(scene->sceneRect()); //Delimita la escena con una linea negra
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/pacmans/background.png"))); //Background
    //Pacman
    player=new pacman();
    player->posicion(288,320);
    scene->addItem(player);
    //Creacion de barras
    for(int i=0;i<numBarras;i++){ //inicializacion de barras
        map.push_back(new QGraphicsRectItem(-(barras[i][0])/2,-(barras[i][1])/2,barras[i][0],barras[i][1]));
        scene->addItem(map[i]);
        map[i]->setPos(barras[i][2],barras[i][3]);

    //Estrella
    star->setPixmap(QPixmap(":/pacmans/estrella.png"));
    stars.assign(1,star);
    for (int i=0;i<1;i++){
        stars[i]->setPos(24,24);
        scene->addItem(stars[i]);
    }
    //timer=new QTimer;
    //connect(timer,SIGNAL(timeout()),this,SLOT(hmov()));
    //timer->stop();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete player;
}

void MainWindow::keyPressEvent(QKeyEvent *event) //Teclas
{
    if (event->key()==Qt::Key_C) close();
    if (event->isAutoRepeat()) hold_key=event->key();
    else prev_key=hold_key;
    if (event->key()==Qt::Key_D && !col_D){
        if (player->getX()>=(640-32)) player->posicion(0,192);
        switch (prev_key){
        /*case Qt::Key_W:
            player->setY(player->getY()-int(vel*0.7));
            player->setX(player->getX()+int(vel*0.7));
            prev_key=Qt::Key_W;
            break;
        case Qt::Key_S:
            player->setY(player->getY()+int(vel*0.7));
            player->setX(player->getX()+int(vel*0.7));
            prev_key=Qt::Key_S;
            break;*/
        default:
            player->setX(player->getX()+vel);
            //prev_key=Qt::Key_D;
            break;
        }
    }
    if (event->key()==Qt::Key_A && !col_A){
        if (player->getX()<=(0)) player->posicion((640-32),416);
        switch (prev_key){
        /*case Qt::Key_W:
            player->setY(player->getY()-int(vel*0.7));
            player->setX(player->getX()-int(vel*0.7));
            prev_key=Qt::Key_W;
            break;
        case Qt::Key_S:
            player->setY(player->getY()+int(vel*0.7));
            player->setX(player->getX()-int(vel*0.7));
            prev_key=Qt::Key_S;
            break;*/
        default:
            player->setX(player->getX()-vel);
            //prev_key=Qt::Key_A;
            break;
        }
     }
    if (event->key()==Qt::Key_W && !col_W){
        if (player->getY()<=(32)) player->posicion(288,(608-32));
        switch (prev_key){
        case Qt::Key_D:
            player->setY(player->getY()-int(vel*0.5));
            player->setX(player->getX()+int(vel*0.5));
            prev_key=Qt::Key_D;
            break;
        /*case Qt::Key_A:
            player->setY(player->getY()-int(vel*0.7));
            player->setX(player->getX()-int(vel*0.7));
            prev_key=Qt::Key_A;
            break;*/
        default:
            player->setY(player->getY()-vel);
            //prev_key=Qt::Key_W;
            break;
        }
    }
    if (event->key()==Qt::Key_S && !col_S){
        if (player->getY()>=(608-32)) player->posicion(320,32);
        switch (prev_key){
        /*case Qt::Key_D:
            player->setY(player->getY()-int(vel*0.7));
            player->setX(player->getX()+int(vel*0.7));
            prev_key=Qt::Key_D;
            break;
        case Qt::Key_A:
            player->setY(player->getY()+int(vel*0.7));
            player->setX(player->getX()-int(vel*0.7));
            prev_key=Qt::Key_A;
            break;*/
        default:
            player->setY(player->getY()+vel);
            //prev_key=Qt::Key_S;
            break;
        }
    }

    player->animacion();
    player->posicion();
    /*//COLSIONES DE BARRAS
    for (int i=0;i<numBarras;i++){
    if (player->collidesWithItem(map[i])){
        switch(event->key()){
        case Qt::Key_D:
            col_D=true;
            caseBreak=true;
            break;
        case Qt::Key_S:
            col_S=true;
            caseBreak=true;
            break;
        case Qt::Key_A:
            col_A=true;
            caseBreak=true;
            break;
        case Qt::Key_W:
            col_W=true;
            caseBreak=true;
            break;
         default:
            break;
        }
    }
        else{
            caseBreak=caseBreak|false;
        }
    }
    if(caseBreak==false){
        col_D=false;
        col_A=false;
        col_S=false;
        col_W=false;
    }
    caseBreak=false;*/
}
/* REVISAR MOV CON TIMER
void MainWindow::hmov()
{
    timer->start(8);
    if (player->getX()>=(640-32)) player->posicion(0,192);
    player->setX(player->getX()+1);
    player->posicion();
}*/

