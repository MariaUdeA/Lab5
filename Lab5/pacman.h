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

private:
    int x;
    int y;
};

#endif // PACMAN_H
