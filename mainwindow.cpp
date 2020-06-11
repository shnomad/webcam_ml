#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

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
        connect(camera_timer, SIGNAL(timeout()), this, SLOT(update_camera()));
        camera_timer->start(20);
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
