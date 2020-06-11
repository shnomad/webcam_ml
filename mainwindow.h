#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

QT_BEGIN_NAMESPACE

using namespace std;
using namespace cv;

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_open_clicked();
    void on_close_clicked();
    void update_camera();

private:
    Ui::MainWindow *ui;
    QTimer *camera_timer;
    VideoCapture cap;
    Mat frame;
    QImage qt_image;
};

#endif // MAINWINDOW_H
