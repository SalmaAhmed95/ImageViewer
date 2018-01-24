#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include <QToolBar>
#include <QAction>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //mouse postion represents mouse moving
    connect(ui->graphicsView,SIGNAL(Mouse_Pos()),this,SLOT(Mouse_current_pos()));
    connect(ui->graphicsView,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_pressed()));
    connect(ui->graphicsView,SIGNAL(Mouse_Left()),this,SLOT(Mouse_left()));
    connect(ui->graphicsView,SIGNAL(Mouse_Released()),this,SLOT(Mouse_released()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Mouse_current_pos()
{

    if(button_pressed == true) {
        newPoint=ui->graphicsView->newPoint;
        band->resize(abs(newPoint.x()-lastPoint.x()),abs( newPoint.y()-lastPoint.y()));
        band->show();
    }
}

void MainWindow::Mouse_pressed()
{
    if (button_pressed == true) {
       band->close();
    }
    button_pressed = true;
    band = new resizable_rubber_band(ui->graphicsView);
    lastPoint=ui->graphicsView->lastPoint;
    band->move(lastPoint.x(), lastPoint.y());
    band->hide();

}

void MainWindow::Mouse_left()
{

}
void MainWindow::Mouse_released(){
    newPoint = ui->graphicsView->newPoint;
    band->resize(abs(newPoint.x()-lastPoint.x()),abs( newPoint.y()-lastPoint.y()));
    imageData->selected = true;
}


void MainWindow::on_rotateR_clicked()
{
    if(!selectionMod){
        history.push(qMakePair(current.copy(), angle));
    angle += imageData->get_angle_text()%360;
    rotate();
     ui->graphicsView->fitInView(scn->itemsBoundingRect(),Qt::KeepAspectRatio);
    }
}

void MainWindow::on_rotatel_clicked()
{
    if(!selectionMod){
        history.push(qMakePair(current.copy(), angle));
    angle -= imageData->get_angle_text()%360;
    rotate();
     ui->graphicsView->fitInView(scn->itemsBoundingRect(),Qt::KeepAspectRatio);
    }
}

void MainWindow::on_zoomin_clicked()
{
    int deltaX = lastPoint.x() - newPoint.x();
    int deltaY = lastPoint.y() - newPoint.y();

    if (imageData->selected && button_pressed == true && deltaX != 0 && deltaY != 0){
        selectionMod = true;
        displayQmessage();
        crop();
        imageData->selected = false;
    }else{
    command->zoom(ui->graphicsView, imageData->get_zoom_in_ratio(), imageData);
    }

 }

void MainWindow::on_zoomout_clicked()
{
    int deltaX = lastPoint.x() - newPoint.x();
    int deltaY = lastPoint.y() - newPoint.y();

    if (imageData->selected && button_pressed == true && deltaX != 0 && deltaY != 0){
        selectionMod = true;
        displayQmessage();
        crop();
        imageData->selected = false;
    }else{
       command->zoom(ui->graphicsView, imageData->get_zoom_out_ratio(), imageData);
    }

}

void MainWindow::on_flib_clicked()
{
    if(!selectionMod){
   history.push(qMakePair(current.copy(), angle));
   current = current.transformed(QTransform().scale(-1, 1));
   pixImage = current;
   load();
   ui->graphicsView->fitInView(scn->itemsBoundingRect(),Qt::KeepAspectRatio);
    }
    /*QMatrix matrix;
    matrix.scale(-1,1);
    current.transformed(matrix);
    pixImage = current;*/
}


void MainWindow::createActions()
{

}

void MainWindow::on_actionZoom_in_triggered()
{
    on_zoomin_clicked();
}

void MainWindow::on_actionZoom_out_triggered()
{
    on_zoomout_clicked();
}

void MainWindow::on_actionOpen_triggered()
{
    if(!selectionMod){

    filename = QFileDialog::getOpenFileName(this, tr("Choose"), getenv("HOME"),tr("images(*.png *.jpg *.jpeg *.bmp *.gif *.PNG *.JPG *.JPEG *.BMP *.GIF)"));
    if(QString :: compare(filename, QString()) != 0)
    {
       ui->graphicsView->setTransform(QTransform());
       bool valid = image.load(filename);
       pixImage = QPixmap(filename);
       openedImage = QPixmap(filename);
       current = pixImage;
       load();
       ui->graphicsView->fitInView(scn->itemsBoundingRect(),Qt::KeepAspectRatio);
      }
    }
}

void MainWindow::on_actionSave_triggered()
{
    filename = QFileDialog::getSaveFileName(this, tr("Save Image As"), tr("images(*.png *.jpg *.jpeg *.bmp *.gif *.PNG *.JPG *.JPEG *.BMP *.GIF)"));
    pixImage.save(filename);
    openedImage = pixImage;
}

void MainWindow::on_textEdit_textChanged()
{
    imageData->set_angle_text(ui->textEdit);
}

void MainWindow::on_crop_clicked()
{   if(!selectionMod){
     history.push(qMakePair(current.copy(), angle));
    int deltaX = lastPoint.x() - newPoint.x();
    int deltaY = lastPoint.y() - newPoint.y();
    if (button_pressed == true && deltaX != 0 && deltaY != 0) {
    QPointF scenePtL = ui->graphicsView->mapToScene(lastPoint);
    QPointF scenePtN = ui->graphicsView->mapToScene(newPoint);
    QPointF aftermapNewPoint = imag->mapFromScene(scenePtN);
    QPointF aftermapLastPoint = imag->mapFromScene(scenePtL);
    QRect rect(aftermapLastPoint.toPoint(),aftermapNewPoint.toPoint());
    pixImage = pixImage.copy(rect);
    current = pixImage;
     //QRect rect(aftermapLastPoint.toPoint(),aftermapNewPoint.toPoint());
    load();
    ui->graphicsView->fitInView(scn->itemsBoundingRect(),Qt::KeepAspectRatio);
    button_pressed = false;
    imageData->selected = false;
    band->close();
    }
    }
}
void MainWindow::load(){
    imag = new QGraphicsPixmapItem(pixImage);
    scn = new QGraphicsScene(this);
    ui->graphicsView->setScene(scn);
    ui->graphicsView->scene()->addItem(imag);
}



void MainWindow::on_reset_clicked()
{
    selectionMod = false;
    pixImage = current = openedImage;
    load();
    ui->graphicsView->fitInView(scn->itemsBoundingRect() ,Qt::KeepAspectRatio);  //???
    imageData->set_size(pixImage.width(), pixImage.height());
    removeStack();
}

void MainWindow::on_actionSave_as_triggered()
{
    QString Asfilename = QFileDialog::getSaveFileName(this, tr("Save Image As"), tr("images(*.png *.jpg *.jpeg *.bmp *.gif *.PNG *.JPG *.JPEG *.BMP *.GIF)"));
    pixImage.save(Asfilename);
    removeStack();
}

void MainWindow::on_actionExit_triggered()
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "PhotoEditor",
                                                      tr("Are you sure you want to leave us?\n"), QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes);
                                                       if (resBtn != QMessageBox::Yes) { qApp->quit(); }

}

void MainWindow::closeEvent (QCloseEvent *event) { QMessageBox::StandardButton resBtn = QMessageBox::question( this, "PhotoEditor",
                                                  tr("Are you sure you want to leave us?\n"), QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes);
                                                   if (resBtn != QMessageBox::Yes) { event->ignore(); }
                                                   else { event->accept(); } }

void MainWindow::on_actionESC_triggered()
{
    selectionMod = false;
   rotate();
   ui->graphicsView->fitInView(scn->itemsBoundingRect(),Qt::KeepAspectRatio);


}
void MainWindow::crop(){
    int deltaX = lastPoint.x() - newPoint.x();
    int deltaY = lastPoint.y() - newPoint.y();
    if (button_pressed == true && deltaX != 0 && deltaY != 0) {
    QPointF scenePtL = ui->graphicsView->mapToScene(lastPoint);
    QPointF scenePtN = ui->graphicsView->mapToScene(newPoint);
    QPointF aftermapNewPoint = imag->mapFromScene(scenePtN);
    QPointF aftermapLastPoint = imag->mapFromScene(scenePtL);
    QRect rect(aftermapLastPoint.toPoint(),aftermapNewPoint.toPoint());
    pixImage = pixImage.copy(rect);
    load();
    ui->graphicsView->fitInView(scn->itemsBoundingRect(),Qt::KeepAspectRatio);
    button_pressed = false;
    imageData->selected = false;
    band->close();
}
}
void MainWindow::rotate(){
    QPixmap temp = current;
    QMatrix matrix;
    QPoint center = temp.rect().center();
    matrix.translate(center.x(), center.y());
    matrix.rotate(angle);
    pixImage = temp.transformed(matrix);
    load();
}
void MainWindow::displayQmessage(){
    QMessageBox msgBox;
    msgBox.setText("Press ESC to return to skip zoom mode");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}

void MainWindow::on_undo_clicked()
{
    if (!history.empty()) {
        qDebug("histoary called");
        redoStack.push(qMakePair(current.copy(), angle));
        QPair<QPixmap,int> snap = history.top();
        history.pop();
        current = snap.first;
        angle = snap.second;
        rotate();
        ui->graphicsView->fitInView(scn->itemsBoundingRect(),Qt::KeepAspectRatio);

    }
}

void MainWindow::on_redo_clicked()
{
    if (!redoStack.empty()) {
        qDebug("histoary called");
        history.push(qMakePair(current.copy(), angle));
        QPair<QPixmap,int> snap = redoStack.top();
        redoStack.pop();
        current = snap.first;
        angle = snap.second;
        rotate();
        ui->graphicsView->fitInView(scn->itemsBoundingRect(),Qt::KeepAspectRatio);

    }
}
void MainWindow::removeStack(){
    while(!history.empty()){
        history.pop();
    }
    while(!redoStack.empty()){
        redoStack.pop();
    }
}
