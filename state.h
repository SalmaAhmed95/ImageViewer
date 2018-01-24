#ifndef STATE_H
#define STATE_H
#include <QGraphicsView>
#include "imagedata.h"
#include "commands.h"

class State
{
public:
     State(QGraphicsView *image,int angle,ImageData* imageData);//rotate
     State(QGraphicsView *image,qreal factor, ImageData* imageData); // zoom
     State(QGraphicsView *image);//flip
     bool rotate = false;
     bool flip = false;
     bool zoom = false;
     bool crop = false;
     void undo();
     void redo();
private:
     QGraphicsView *imag;
     int angle;
     qreal newFactor;
     ImageData *image_data;
     commands *com = new commands();
};

#endif // STATE_H
