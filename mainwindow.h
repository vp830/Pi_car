#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <wiringPi.h>
#include <QFileDialog>
#include <cv.h>
#include <highgui/highgui_c.h>
#include <QTimer>
#include <QPixmap>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void getFrame();

    void stop();

private:
    Ui::MainWindow *ui;
    CvCapture *capture;
    IplImage *frame;
    QTimer *timer;
};

#endif // MAINWINDOW_H
