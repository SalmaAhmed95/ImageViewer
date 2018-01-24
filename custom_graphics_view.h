#ifndef CUSTOM_GRAPHICS_VIEW_H
#define CUSTOM_GRAPHICS_VIEW_H
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QRubberBand>
#include <QGraphicsView>

//#include "resizable_rubber_band.h"

class custom_graphics_view : public QGraphicsView
{
    Q_OBJECT;
public:
   explicit custom_graphics_view(QWidget *parent=0);

    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void leaveEvent(QEvent *);

    int x,y;
    QPoint lastPoint;
    QPoint newPoint;
    //resizable_rubber_band *band;

signals:
    void Mouse_Pressed();
    void Mouse_Pos();
    void Mouse_Left();
    void Mouse_Released();

public slots:
};
#endif // CUSTOM_GRAPHICS_VIEW_H
