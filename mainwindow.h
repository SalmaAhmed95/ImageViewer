#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMessageBox>
#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include<QPair>
#include <QRubberBand>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPainter>
#include "resizable_rubber_band.h"
#include <commands.h>
#include <imagedata.h>
#include <stack>
#include <state.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void closeEvent (QCloseEvent *event);
    ~MainWindow();

private slots:

    void Mouse_current_pos();
    void Mouse_pressed();
    void Mouse_left();
    void Mouse_released();
    void on_rotateR_clicked();

    void on_rotatel_clicked();

    void on_zoomin_clicked();

    void on_zoomout_clicked();

    void on_flib_clicked();

    void createActions();
    void on_actionZoom_in_triggered();

    void on_actionZoom_out_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_textEdit_textChanged();

    void on_crop_clicked();

    void on_reset_clicked();

    void on_actionSave_as_triggered();

    void on_actionExit_triggered();

    void on_actionESC_triggered();

    void on_undo_clicked();

    void on_redo_clicked();

private:
    Ui::MainWindow *ui;
    QString filename;
    QImage image;
    QPixmap openedImage;
    QPixmap current;
    QPixmap pixImage;
    commands* command = new commands();
    ImageData* imageData = new ImageData();
    resizable_rubber_band *band;
    QGraphicsPixmapItem *imag;
    QGraphicsScene *scn;
    QPoint lastPoint;
    QPoint newPoint;
    bool button_pressed = false, selectionMod = false;
    int angle = 0;
    std::stack<QPair<QPixmap, int>> history;
    std::stack<QPair<QPixmap, int>> redoStack;
    void load();
    void crop();
    void rotate();
    void displayQmessage();
    void removeStack();


};

#endif // MAINWINDOW_H
