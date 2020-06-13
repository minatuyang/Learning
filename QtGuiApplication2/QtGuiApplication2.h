#pragma once

#include <stdio.h>
#include <windows.h>

#include <QApplication>
#include <QCamera>
#include <QCameraImageCapture>
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QDebug>
#include <QImage>
#include <QList>
#include <QTimer>
#include <QWidget>
#include <QtWidgets/QMainWindow>
#include <opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

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
	CvCapture* cam; // ��Ƶ��ȡ�ṹ�� ������Ϊ��Ƶ��ȡ������һ������
	cv::Mat* frame; //����Mat����ָ�룬���������ڴ�ռ������ÿһ֡ͼ��

public:
	~QtGuiApplication2();

public slots:
	void ShowTheCapture();
	void SavePicture();
	void displayImage(int, QImage image);

public:
	QCamera* camera;                   //����ͷ
	QCameraViewfinder* viewfinder;     //����ͷȡ��������
	QCameraImageCapture* imageCapture; //��ͼ����
};
