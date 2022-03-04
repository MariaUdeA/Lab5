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

    player=new pacman();
    player->posicion(50,50);
    scene->addItem(player);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) //Teclas
{
    if (event->key()==Qt::Key_C) close();
    if (event->key()==Qt::Key_D){
        if (player->getX()>(640-32)) player->posicion(0,player->getY());
        player->setX(player->getX()+vel);
    }
    if (event->key()==Qt::Key_A){
        if (player->getX()<(0)) player->posicion((640-32),player->getY());
        player->setX(player->getX()-vel);
    }
    if (event->key()==Qt::Key_W){
        if (player->getY()<(0)) player->posicion(player->getX(),(608-32));
        player->setY(player->getY()-vel);
    }
    if (event->key()==Qt::Key_S){
        if (player->getY()>(608-32)) player->posicion(player->getX(),0);
        player->setY(player->getY()+vel);
    }
    player->posicion();
}

