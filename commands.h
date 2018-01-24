#ifndef COMMANDS_H
#define COMMANDS_H
#include <QMainWindow>
#include <QGraphicsView>
#include <QTextEdit>
#include <imagedata.h>
class commands
{
public:
    commands();
    void zoom (QGraphicsView *image,qreal factor,ImageData* imageData);
    QPixmap crop (QImage image,QPoint point1,QPoint point2);
    void resize (QImage image);
    void flibb (QGraphicsView *image);
    void rotate (QGraphicsView *image,int angle, ImageData* imageData);
    void undo(QImage image);
    void redo (QImage image);
    void fitSelect(QGraphicsView *image,QPoint point1,QPoint point2);


private:

};

#endif // COMMANDS_H
