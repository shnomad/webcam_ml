#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <QDateTime>
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    camera_timer = new QTimer(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_clicked()
{
    cap.open(0);

    if(!cap.isOpened())
    {

    }
    else
    {
        system("v4l2-ctl -d /dev/video0 --set-ctrl=exposure_auto=1");
        QThread::msleep(100);

        system("v4l2-ctl -d /dev/video0 --set-ctrl=focus_auto=1");
        QThread::msleep(100);

        connect(camera_timer, SIGNAL(timeout()), this, SLOT(update_camera()));
        camera_timer->start(50);
    }
}

void MainWindow::on_close_clicked()
{
    disconnect(camera_timer, SIGNAL(timeout()), this, SLOT(update_camera()));

    cap.release();
    Mat image = Mat::zeros(frame.size(), CV_8UC3);
    qt_image = QImage((const unsigned char*)(image.data), image.cols, image.rows, QImage::Format_RGB888);
    ui->preview->setPixmap(QPixmap::fromImage(qt_image));
//  ui->label->resize(ui->label->pixmap()->size());       //resize the camera display
//  ui->label->setStyleSheet("color: yellow");            //font color
}

void MainWindow::update_camera()
{
    cap >> frame;
    cvtColor(frame, frame, COLOR_BGR2RGB);

    if(ui->capture->isChecked())
    {
         QDateTime Current_Time = QDateTime::currentDateTime();
         QString filename = "/home/pi/capture_file/" + Current_Time.toString("yyyyMMddhhmmsszzz") + ".jpg";
         imwrite(filename.toStdString(),frame);
    }

    qt_image = QImage((const unsigned char*)(frame.data), frame.cols, frame.rows, QImage::Format_RGB888);
    ui->preview->setPixmap(QPixmap::fromImage(qt_image));
}
