#ifndef IMAGEDATA_H
#define IMAGEDATA_H
#include <QTextEdit>

class ImageData
{
public:
    ImageData();
    void set_angle_text(QTextEdit *txt);
    int get_angle_text();
    float get_width();
    float get_height();
    void set_size(float w, float height);
    qreal get_zoom_in_ratio();
    qreal get_zoom_out_ratio();
    bool validScale(qreal factor);
    void inverse();
    bool selected = false;
private:
    float width;
    float height;
    int default_angle_rotate;//check float parsing
    int angle_rotation;
    float scaledPhoto, scaleCom;
    bool wid;
    qreal zoom_in_ratio;
    qreal zoom_out_ratio;
};

#endif // IMAGEDATA_H
