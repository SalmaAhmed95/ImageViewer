#ifndef RESIZABLE_RUBBER_BAND_H
#define RESIZABLE_RUBBER_BAND_H
#include <QRubberBand>
class resizable_rubber_band : public QWidget {
public:
  resizable_rubber_band(QWidget* parent = 0);

private:
  QRubberBand* rubberband;
  void resizeEvent(QResizeEvent *);

};

#endif // RESIZABLE_RUBBER_BAND_H
