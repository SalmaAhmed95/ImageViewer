#include "imagedata.h"

ImageData::ImageData()
{
   default_angle_rotate = angle_rotation = 90;
   zoom_in_ratio = 1.25;
   zoom_out_ratio = .8;
}
int ImageData::get_angle_text(){
    return angle_rotation;
}

void ImageData::set_angle_text(QTextEdit *txt){
   QString textAng = txt->toPlainText();
   angle_rotation = textAng == "" ? default_angle_rotate : textAng.toInt();
}
float ImageData::get_width(){
    return width;
}
float ImageData::get_height(){
    return height;
}
void ImageData::set_size(float w, float h){
    width = scaledPhoto = scaleCom = w;
    wid = true;
    height = h;
}

qreal ImageData::get_zoom_in_ratio(){
    return zoom_in_ratio;
}
qreal ImageData::get_zoom_out_ratio(){
    return zoom_out_ratio;
}
bool ImageData::validScale(qreal factor){
    return true;
}
void ImageData::inverse(){
    float temp = width;
    width = height;
    height = temp;
}

