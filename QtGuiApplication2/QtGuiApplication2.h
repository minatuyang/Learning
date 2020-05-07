#pragma once

#include <QtWidgets/QMainWindow>
#include <QWidget>
#include <QApplication>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QCameraInfo>
#include <QList>
#include <QDebug>
#include <QImage>
#include <QTimer>
#include <windows.h>
#include <stdio.h>
#include <opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include "ui_QtGuiApplication2.h"

class QtGuiApplication2 : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApplication2(QWidget* parent = Q_NULLPTR);

private:
	Ui::QtGuiApplication2Class ui;
	QTimer* timer;
	QImage* imag;
	CvCapture* cam;// 视频获取结构， 用来作为视频获取函数的一个参数
	cv::Mat* frame;//申请Mat类型指针，就是申请内存空间来存放每一帧图像

public:
	~QtGuiApplication2();

public slots:
	void ShowTheCapture();
	void SavePicture();
	void displayImage(int, QImage image);
public:
	QCamera* camera;//摄像头
	QCameraViewfinder* viewfinder;//摄像头取景器部件
	QCameraImageCapture* imageCapture;//截图部件
};
