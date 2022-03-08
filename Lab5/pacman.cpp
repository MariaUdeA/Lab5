#include "pacman.h"

pacman::pacman(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/pacmans/OPEN.png"));
}

void pacman::setX(int newX)
{
    x = newX;
}
void pacman::setY(int newY)
{
    y = newY;
}
int pacman::getX() const
{
    return x;
}
int pacman::getY() const
{
    return y;
}
void pacman::posicion()
{
    setPos(x,y);
}
void pacman::posicion(int newX,int newY)
{
    x=newX;
    y=newY;
    setPos(x,y);
}

void pacman::animacion()
{
    if (flag && cont<4){
        setPixmap(QPixmap(":/pacmans/OPEN.png"));
        flag=false;
    }
    if (! flag && cont>4){
        setPixmap(QPixmap(":/pacmans/CLOSED.png"));
        flag=true;
    }
    if (cont==8)  cont=0;
    cont++;
}
