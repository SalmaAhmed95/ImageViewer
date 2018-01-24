#include "state.h"

State::State(QGraphicsView *image,int angl,ImageData* imageData)
{
  imag = image;
  angle = angl;
  image_data = imageData;
}
State::State(QGraphicsView *image)
{
  imag = image;
}
State::State(QGraphicsView *image,qreal factor, ImageData* imageData)
{
    imag = image;
    newFactor = 1.0 / factor;
    image_data = imageData;

}
void State::undo(){
    if(zoom)
    {
       com->zoom(imag, newFactor, image_data);
    }else if(rotate){
       com->rotate(imag, angle*-1, image_data);
    }else if(flip){
        com->flibb(imag);
    }
}

void State::redo(){
    if(zoom)
    {
       com->zoom(imag, 1.0 / newFactor, image_data);
    }else if(rotate) {
       com->rotate(imag, angle,image_data);
    }else if(flip){
        com->flibb(imag);
    }else if(crop) {

    }
}
