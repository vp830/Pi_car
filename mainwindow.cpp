#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wiringPi.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer=new QTimer(this);
   capture=cvCaptureFromCAM(0);
    wiringPiSetup();
    pinMode(26,OUTPUT);
    pinMode(27,OUTPUT);
    pinMode(28,OUTPUT);
    pinMode(29,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(1,INPUT);

   if(capture==NULL)
   {
       qDebug()<<"ERROR";
   }
   timer->start(100);
  connect(timer,SIGNAL(timeout()),this,SLOT(getFrame()));
}
void MainWindow::getFrame()
{
    frame=cvQueryFrame(capture);
    QImage image = QImage((const uchar*)frame->imageData,frame->width,frame->height,QImage::Format_RGB888).rgbSwapped();
   ui->label_3->setPixmap(QPixmap::fromImage(image));
}
void left()
{
    digitalWrite(26,LOW);
    digitalWrite(27,LOW);
    digitalWrite(28,LOW);
    digitalWrite(29,HIGH);
}
void stop()
{
    digitalWrite(26,LOW);
    digitalWrite(27,LOW);
    digitalWrite(28,LOW);
    digitalWrite(29,LOW);
}
void up()
{
    digitalWrite(26,LOW);
    digitalWrite(27,HIGH);
    digitalWrite(28,HIGH);
    digitalWrite(29,LOW);
}
void down()
{
    digitalWrite(26,HIGH);
    digitalWrite(27,LOW);
    digitalWrite(28,LOW);
    digitalWrite(29,HIGH);
}
void right()
{
    digitalWrite(26,HIGH);
    digitalWrite(27,LOW);
    digitalWrite(28,LOW);
    digitalWrite(29,LOW);
}

void MainWindow::stop()
{
    digitalWrite(26,LOW);
    digitalWrite(27,LOW);
    digitalWrite(28,LOW);
    digitalWrite(29,LOW);
}

void MainWindow::on_pushButton_clicked()
{
    stop();
    left();
}
void MainWindow::on_pushButton_2_clicked()
{
    stop();
}

void MainWindow::on_pushButton_5_clicked()
{
    stop();
    right();

}

void MainWindow::on_pushButton_4_clicked()
{
    stop();
    down();
}

void MainWindow::on_pushButton_3_clicked()
{
    stop();
    up();
}

void MainWindow::on_pushButton_6_clicked()
{
    double dist=0;
    double t=0;//ms
    digitalWrite(4,HIGH);
    delay(0.015);
    digitalWrite(4,LOW);
    while (!(digitalRead(1)==1));
    double time_start=(double) clock();
    while (!(digitalRead(1)==0));
    double time_stop=(double) clock();
    t=time_stop-time_start;
    dist=170*t/1000000;
    ui->lcdNumber_2->display(t);
    ui->lcdNumber->display(dist);
}

void MainWindow::on_pushButton_7_clicked()
{
    QTimer *timer2=new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(on_pushButton_6_clicked()));
    timer2->start(2500);

}

MainWindow::~MainWindow()
{
    timer->stop();
    cvReleaseCapture(&capture);
    delete ui;
}
