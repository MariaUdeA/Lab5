#ifndef STAR_H
#define STAR_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class star:public QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    star(QGraphicsItem* carr=0);
    ~star();
    //void byebye();
};

#endif // STAR_H
