/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <custom_graphics_view.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFile;
    QAction *actionEdit;
    QAction *actionView;
    QAction *actioncrop;
    QAction *actionundo;
    QAction *actionredo;
    QAction *actionZoom_in;
    QAction *actionZoom_out;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionExit;
    QAction *actionESC;
    QWidget *centralWidget;
    custom_graphics_view *graphicsView;
    QTextEdit *textEdit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *crop;
    QPushButton *flib;
    QPushButton *rotateR;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *rotatel;
    QPushButton *zoomin;
    QPushButton *zoomout;
    QPushButton *reset;
    QLabel *label;
    QPushButton *undo;
    QPushButton *redo;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(978, 608);
        actionFile = new QAction(MainWindow);
        actionFile->setObjectName(QStringLiteral("actionFile"));
        actionEdit = new QAction(MainWindow);
        actionEdit->setObjectName(QStringLiteral("actionEdit"));
        actionView = new QAction(MainWindow);
        actionView->setObjectName(QStringLiteral("actionView"));
        actioncrop = new QAction(MainWindow);
        actioncrop->setObjectName(QStringLiteral("actioncrop"));
        actionundo = new QAction(MainWindow);
        actionundo->setObjectName(QStringLiteral("actionundo"));
        actionredo = new QAction(MainWindow);
        actionredo->setObjectName(QStringLiteral("actionredo"));
        actionZoom_in = new QAction(MainWindow);
        actionZoom_in->setObjectName(QStringLiteral("actionZoom_in"));
        actionZoom_out = new QAction(MainWindow);
        actionZoom_out->setObjectName(QStringLiteral("actionZoom_out"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionESC = new QAction(MainWindow);
        actionESC->setObjectName(QStringLiteral("actionESC"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new custom_graphics_view(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(40, 60, 891, 431));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(450, 510, 51, 31));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(110, 500, 321, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        crop = new QPushButton(horizontalLayoutWidget);
        crop->setObjectName(QStringLiteral("crop"));

        horizontalLayout->addWidget(crop);

        flib = new QPushButton(horizontalLayoutWidget);
        flib->setObjectName(QStringLiteral("flib"));

        horizontalLayout->addWidget(flib);

        rotateR = new QPushButton(horizontalLayoutWidget);
        rotateR->setObjectName(QStringLiteral("rotateR"));

        horizontalLayout->addWidget(rotateR);

        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(520, 500, 341, 51));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        rotatel = new QPushButton(horizontalLayoutWidget_2);
        rotatel->setObjectName(QStringLiteral("rotatel"));

        horizontalLayout_2->addWidget(rotatel);

        zoomin = new QPushButton(horizontalLayoutWidget_2);
        zoomin->setObjectName(QStringLiteral("zoomin"));

        horizontalLayout_2->addWidget(zoomin);

        zoomout = new QPushButton(horizontalLayoutWidget_2);
        zoomout->setObjectName(QStringLiteral("zoomout"));

        horizontalLayout_2->addWidget(zoomout);

        reset = new QPushButton(centralWidget);
        reset->setObjectName(QStringLiteral("reset"));
        reset->setGeometry(QRect(880, 0, 89, 25));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(440, 537, 81, 20));
        undo = new QPushButton(centralWidget);
        undo->setObjectName(QStringLiteral("undo"));
        undo->setGeometry(QRect(390, 10, 71, 21));
        redo = new QPushButton(centralWidget);
        redo->setObjectName(QStringLiteral("redo"));
        redo->setGeometry(QRect(470, 10, 71, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 978, 22));
        menuBar->setNativeMenuBar(false);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setSizeGripEnabled(false);
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionExit);
        menuEdit->addSeparator();
        menuEdit->addAction(actioncrop);
        menuEdit->addAction(actionundo);
        menuEdit->addAction(actionredo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionESC);
        menuView->addSeparator();
        menuView->addAction(actionZoom_in);
        menuView->addAction(actionZoom_out);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PhotoEditor", Q_NULLPTR));
        actionFile->setText(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        actionEdit->setText(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        actionView->setText(QApplication::translate("MainWindow", "View", Q_NULLPTR));
        actioncrop->setText(QApplication::translate("MainWindow", "Crop", Q_NULLPTR));
        actionundo->setText(QApplication::translate("MainWindow", "Undo", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionundo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionredo->setText(QApplication::translate("MainWindow", "Redo", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionredo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionZoom_in->setText(QApplication::translate("MainWindow", "Zoom in", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionZoom_in->setShortcut(QApplication::translate("MainWindow", "Ctrl+Up", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionZoom_out->setText(QApplication::translate("MainWindow", "Zoom out", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionZoom_out->setShortcut(QApplication::translate("MainWindow", "Ctrl+Down", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionESC->setText(QApplication::translate("MainWindow", "ESC", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionESC->setShortcut(QApplication::translate("MainWindow", "Esc", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        textEdit->setToolTip(QApplication::translate("MainWindow", "step angle", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        crop->setToolTip(QApplication::translate("MainWindow", "crop", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        crop->setText(QString());
#ifndef QT_NO_TOOLTIP
        flib->setToolTip(QApplication::translate("MainWindow", "flip horizontally", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        flib->setText(QString());
#ifndef QT_NO_TOOLTIP
        rotateR->setToolTip(QApplication::translate("MainWindow", "rotate clockwise", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        rotateR->setText(QString());
#ifndef QT_NO_TOOLTIP
        rotatel->setToolTip(QApplication::translate("MainWindow", "rotate counter clockwise", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        rotatel->setText(QString());
#ifndef QT_NO_TOOLTIP
        zoomin->setToolTip(QApplication::translate("MainWindow", "zoom out", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        zoomin->setText(QString());
#ifndef QT_NO_TOOLTIP
        zoomout->setToolTip(QApplication::translate("MainWindow", "zoom out", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        zoomout->setText(QString());
        reset->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Step Angle", Q_NULLPTR));
        undo->setText(QString());
        redo->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("MainWindow", "View", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
