#include "QtGuiApplication2.h"

QtGuiApplication2::QtGuiApplication2(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//ui.label->setScaledContents(true);
	camera = new QCamera;//����ͷ
	viewfinder = new QCameraViewfinder(ui.centralWidget);
	imageCapture = new QCameraImageCapture(camera);//��ͼ����
	//ui.label->setScaledContents(true);
	cam = NULL;
	timer = new QTimer(this);
	imag = new QImage();         // ��ʼ��

	///*�źźͲ�*/
	//connect(timer, &QTimer::timeout, this, &Widget::readFarme);// ʱ�䵽����ȡ��ǰ����ͷ��Ϣ
	//connect(ui->pushButton_open, &QPushButton::clicked, this, &Widget::openCamara); //������ͷ
	//connect(ui->pushButton_photo, &QPushButton::clicked, this, &Widget::takingPictures);//����
	//connect(ui->pushButton_close, &QPushButton::clicked, this, &Widget::closeCamara);    //�ر�����ͷ
	camera->setViewfinder(viewfinder);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(ShowTheCapture()));
	connect(ui.SaveButton, SIGNAL(clicked()), this, SLOT(SavePicture()));
	connect(imageCapture, SIGNAL(imageCaptured(int, QImage)), this, SLOT(displayImage(int, QImage)));
	imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
	//QCameraViewfinderSettings viewFinderSettings;
	//viewFinderSettings.setResolution(800, 600);  //���÷ֱ���
	//camera->setViewfinderSettings(viewFinderSettings);
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
	//image = image.convertToFormat(QImage::Format_RGB888);
	//image = image.scaled(ui.label->width(), ui.label->height());
	//ui.label->setPixmap(QPixmap::fromImage(image));
	//QImage::Format format = image.format();
}
void QtGuiApplication2::SavePicture()
{
	//const QPixmap* pixmap = ui.label->pixmap();
	//if (pixmap)
	//{
	//	pixmap->save("E:\\hallo.jpg");
	//	qDebug() << "��������" << endl;
	//}
}