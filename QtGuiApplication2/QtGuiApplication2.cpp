#include "QtGuiApplication2.h"

QtGuiApplication2::QtGuiApplication2(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//ui.label->setScaledContents(true);
	camera = new QCamera;//摄像头
	viewfinder = new QCameraViewfinder(ui.centralWidget);
	imageCapture = new QCameraImageCapture(camera);//截图部件
	//ui.label->setScaledContents(true);
	cam = NULL;
	timer = new QTimer(this);
	imag = new QImage();         // 初始化

	///*信号和槽*/
	//connect(timer, &QTimer::timeout, this, &Widget::readFarme);// 时间到，读取当前摄像头信息
	//connect(ui->pushButton_open, &QPushButton::clicked, this, &Widget::openCamara); //打开摄像头
	//connect(ui->pushButton_photo, &QPushButton::clicked, this, &Widget::takingPictures);//照相
	//connect(ui->pushButton_close, &QPushButton::clicked, this, &Widget::closeCamara);    //关闭摄像头
	camera->setViewfinder(viewfinder);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(ShowTheCapture()));
	connect(ui.SaveButton, SIGNAL(clicked()), this, SLOT(SavePicture()));
	connect(imageCapture, SIGNAL(imageCaptured(int, QImage)), this, SLOT(displayImage(int, QImage)));
	imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
	//QCameraViewfinderSettings viewFinderSettings;
	//viewFinderSettings.setResolution(800, 600);  //设置分辨率
	//camera->setViewfinderSettings(viewFinderSettings);
	camera->setCaptureMode(QCamera::CaptureStillImage);
	camera->setViewfinder(viewfinder);
	camera->start(); //启动摄像头
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
	//	qDebug() << "保存上了" << endl;
	//}
}