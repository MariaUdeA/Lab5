#ifndef PACMAN_H
#define PACMAN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class pacman:public QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    pacman(QGraphicsItem* carr=0);
    void setX(int newX);
    void setY(int newY);
    int getX() const;
    int getY() const;
    void posicion();
    void posicion(int newX,int newY);
    void animacion();

private:
    int x;
    int y;
    bool flag=true;
    char cont=0;
};

#endif // PACMAN_H
