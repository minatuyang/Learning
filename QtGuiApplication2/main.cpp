#include "QtGuiApplication2.h"
#include <QtWidgets/QApplication>
#include <opencv.hpp>
using namespace cv;
int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	QtGuiApplication2 w;
	w.show();
	return a.exec();
	Mat image = cv::imread("E:/hallo.jpg");
	if (image.empty()) {
		printf("could not load image...\n");
	}
	namedWindow("test_opencv_setup", 0);
	imshow("test_opencv_srtup", image);
	waitKey(0);
	return 0;
}
