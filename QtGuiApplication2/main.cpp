#include "QtGuiApplication2.h"
#include <QtWidgets/QApplication>
#include <opencv.hpp>
using namespace cv;
int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	MEMORYSTATUS mem;//����һ���ڴ�״̬����
	DWORD MemTotal, MemFree, VMemTotal, VMemFree;//�洢�ڴ�״̬��Ϣ
	GlobalMemoryStatus(&mem); //�洢�ڴ�״̬��Ϣ
	MemTotal = mem.dwTotalPhys;//�õ����ڴ��С����λb��
	MemFree = mem.dwAvailPhys;//�õ�ʣ���ڴ��С����λb��
	VMemTotal = mem.dwTotalVirtual;//�õ��������ڴ��С����λb��
	VMemFree = mem.dwAvailVirtual;//�õ�ʣ�������ڴ��ڴ��С����λb��
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
