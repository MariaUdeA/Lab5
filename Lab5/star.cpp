#include "star.h"
star::star(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/pacmans/star.png"));
}

star::~star()
{

}

