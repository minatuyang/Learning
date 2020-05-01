#pragma once

#include <QtWidgets/QMainWindow>

#include <QWidget>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QCameraInfo>
#include <QList>
#include <QDebug>
#include <QImage>
#include "ui_QtGuiApplication2.h"

class QtGuiApplication2 : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApplication2(QWidget* parent = Q_NULLPTR);

private:
	Ui::QtGuiApplication2Class ui;

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
