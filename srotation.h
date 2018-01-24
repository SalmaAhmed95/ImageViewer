#ifndef SROTATION_H
#define SROTATION_H
#include <state.h>
#include <QGraphicsView>

class SRotation : public State
{
public:
    SRotation();
    void undo();
    void redo();
private:
    int angle;
    QGraphicsView* image;
};

#endif // SROTATION_H
