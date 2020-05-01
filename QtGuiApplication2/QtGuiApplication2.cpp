#include "QtGuiApplication2.h"

QtGuiApplication2::QtGuiApplication2(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	camera = new QCamera;//����ͷ
	viewfinder = new QCameraViewfinder(this);
	imageCapture = new QCameraImageCapture(camera);//��ͼ����
	camera->setViewfinder(viewfinder);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(ShowTheCapture()));
	connect(ui.SaveButton, SIGNAL(clicked()), this, SLOT(SavePicture()));
	connect(imageCapture, SIGNAL(imageCaptured(int, QImage)), this, SLOT(displayImage(int, QImage)));
	imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
	camera->setCaptureMode(QCamera::CaptureStillImage);
	camera->setViewfinder(viewfinder);
	camera->start(); //��������ͷ
}
QtGuiApplication2::~QtGuiApplication2()
{}
void QtGuiApplication2::ShowTheCapture()
{
	imageCapture->capture();
}
void QtGuiApplication2::displayImage(int, QImage image)
{
	//qDebug() << (int)format;
	image = image.convertToFormat(QImage::Format_RGB888);
	ui.label->setPixmap(QPixmap::fromImage(image));
	QImage::Format format = image.format();
	qDebug() << (int)format;

}
void QtGuiApplication2::SavePicture()
{
	const QPixmap* pixmap = ui.label->pixmap();
	if (pixmap)
	{
		pixmap->save("E:\\hallo.jpg");
		qDebug() << "��������" << endl;
	}

}
