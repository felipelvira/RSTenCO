#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <MatToQImage.h>
#include <cv.h>
#include <highgui.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    cap.release();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    cap.open(0);

    if(cap.isOpened() == false)
    {
        qDebug()<<("error: No se puede acceder a la cámara");
        return;
    }


    if (cap.isOpened()){
        //cap.set--algo
        timer= new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(detectAndDisplay()));
        timer->start(100);//milisegundo
    };
}

void MainWindow::detectAndDisplay()
{
    cv::Mat frame, hsvFrame;
    cv::Size size(420,280);
    // hacer la comparacion para verificar si la camweb fue exitosamente abierta
    cap >> frame;

    cv::flip(frame,frame,1);//para la cam web
    cv::cvtColor(frame, hsvFrame,CV_BGR2HSV);
    /*cv::namedWindow("video",CV_WINDOW_AUTOSIZE);
    cv::imshow("video",hsvFrame);*/

    cv::cvtColor(frame, frame, CV_RGB2BGR);

    cv::resize(frame,frame,size);
    QImage qimgOriginal((uchar*)frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
    ui->lbl1->setPixmap(QPixmap::fromImage(qimgOriginal));

    cv::resize(hsvFrame,hsvFrame,size);
    QImage qimgHSV((uchar*)hsvFrame.data, hsvFrame.cols, hsvFrame.rows, hsvFrame.step, QImage::Format_RGB888);
    ui->lbl2->setPixmap(QPixmap::fromImage(qimgHSV));




}

