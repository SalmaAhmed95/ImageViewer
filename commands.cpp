#include "commands.h"
commands::commands()
{
}
//return QPixmap of croped image to set the label with
QPixmap commands::crop(QImage image, QPoint point1, QPoint point2)
{
    //crop trial after selection is done bit ther is something wrong with coordinates
    QRect rect(point1,point2);
    QPixmap cropped =QPixmap::fromImage(image).copy(rect);
    return cropped;
}
void commands::rotate(QGraphicsView *image,int angle, ImageData* imageData)
{
     image->rotate(angle);
     imageData->inverse();
}
void commands::zoom(QGraphicsView *image,qreal factor, ImageData* imageData)
{
    if(imageData->validScale(factor)){
        image->scale(factor,factor);
    }

}

void commands::flibb(QGraphicsView *image)
{
     image->scale(-1, 1);
}
void commands::fitSelect(QGraphicsView *image,QPoint point1,QPoint point2){
      QRect rect(point1,point2);
       image->fitInView(rect,Qt::KeepAspectRatio);
}


