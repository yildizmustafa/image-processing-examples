
#include "stdafx.h"
#include "opencv2\opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("resim.jpg");
	if (img.empty())
		cout << "dosya bos" << endl;
	else {
		namedWindow("Resim", CV_WINDOW_AUTOSIZE);
		imshow("Resim", img);
		waitKey(0);
		destroyWindow("Resim");

	}
		


    return 0;
}

