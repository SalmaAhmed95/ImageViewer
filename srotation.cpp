#include "srotation.h"

SRotation::SRotation(int ang,QGraphicsView* imag)
{
     angle = ang;
     image = imag;
}
void SRotation::undo(){
    image->rotate(angle*-1);
}
void SRotation::redo(){
    image->rotate(angle*-1);
}
