#include "custom_graphics_view.h"


custom_graphics_view::custom_graphics_view(QWidget *parent): QGraphicsView(parent)
{

}

void custom_graphics_view::mouseMoveEvent(QMouseEvent *ev)
{
    newPoint = ev->pos();
    emit Mouse_Pos();
}

void custom_graphics_view::mousePressEvent(QMouseEvent *ev)
{
    lastPoint = ev->pos();
//    rubber_band = new QRubberBand(QRubberBand::Rectangle,this);
//    rubber_band->setGeometry(QRect(lastPoint, QSize()));
//    rubber_band->show();
    emit Mouse_Pressed();

}

void custom_graphics_view::mouseReleaseEvent(QMouseEvent *ev)
{
    newPoint = ev->pos();
    emit Mouse_Released();
}

void custom_graphics_view::leaveEvent(QEvent *)
{
    emit Mouse_Left();
}
