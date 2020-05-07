#include "QtGuiApplication2.h"
#include <QtWidgets/QApplication>
#include <opencv.hpp>
using namespace cv;
int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	MEMORYSTATUS mem;//定义一个内存状态变量
	DWORD MemTotal, MemFree, VMemTotal, VMemFree;//存储内存状态信息
	GlobalMemoryStatus(&mem); //存储内存状态信息
	MemTotal = mem.dwTotalPhys;//得到总内存大小（单位b）
	MemFree = mem.dwAvailPhys;//得到剩余内存大小（单位b）
	VMemTotal = mem.dwTotalVirtual;//得到总虚拟内存大小（单位b）
	VMemFree = mem.dwAvailVirtual;//得到剩余虚拟内存内存大小（单位b）
	qDebug() << (MemTotal / 1024) / 1024;
	MessageBox(NULL, TEXT("This is windows window"), TEXT("HAHA YOYO"), MB_OK);
	QtGuiApplication2 w;
	w.show();
	return a.exec();
	/*int i = 0;
	i++;
	Mat image = cv::imread("E:/hallo.jpg");
	if (image.empty()) {
		printf("could not load image...\n");
	}
	namedWindow("test_opencv_setup", 0);
	imshow("test_opencv_srtup", image);
	waitKey(0);
	return 0;*/
}
