#include "stdafx.h"
#include "opencv2\opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
	Mat resim = imread("resim.png");
	Mat zitresim;
	bitwise_not(resim, zitresim, noArray());
	imshow("orjinal", resim);
	imshow("ters", zitresim);
	waitKey(0);

    return 0;
}

