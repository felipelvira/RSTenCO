#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//OpenCv libraries
#include <QMainWindow>
#include "cv.h"
#include <highgui.h>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    cv::VideoCapture cap;
        QTimer *timer;

private slots:
        void on_pushButton_clicked();
        void detectAndDisplay();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
