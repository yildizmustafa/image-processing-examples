#include "stdafx.h"
#include "opencv2\opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("kaleici.jpg");
	namedWindow("Original", CV_WINDOW_AUTOSIZE);
	namedWindow("Filtered", CV_WINDOW_AUTOSIZE);
	imshow("Original", img);

	Mat filtres;
	char yazi[60];

	int deger = 1;
	createTrackbar("Filtere", "Filtered", &deger, 13);

	char charCheckForEscKey = 0;
	while (charCheckForEscKey != 27)
	{

		cout << "\nFiltre buyuklugu " << 2 * deger + 1 << " x " << 2 * deger + 1;

		//blur(imgOriginal, filtres, Size(2 * deger - 1, 2 * deger - 1));
		//GaussianBlur(imgOriginal, filtres, Size(2*deger-1,2*deger-1), 0, 0);
		//medianBlur(imgOriginal, filtres, 2 * deger- 1);
		bilateralFilter(img, filtres, 2 * deger - 1, 2 * deger - 1, 2 * deger - 1);

		imshow("Filtered", filtres);

		charCheckForEscKey = cv::waitKey(1);
	}

	waitKey(0);
	return(0);

}
