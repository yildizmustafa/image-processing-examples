
#include "stdafx.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace std;
using namespace cv;

int main()
{
	Mat orjinal, kucultulmus, kayıt;

	orjinal = imread("resim.jpg");//eklenecek resim adı

	namedWindow("orjinal hali", CV_WINDOW_AUTOSIZE);//pencere olusturuldu

	imshow("orjinal hali", orjinal);//resim pencereye aktarıldı

	resize(orjinal, kucultulmus, Size(), 0.5, 0.5, INTER_LINEAR);//resim kucultuldu

	namedWindow("kucuk resim",CV_WINDOW_AUTOSIZE);

	imshow("kucuk resim", kucultulmus);

	imwrite("kucuk.jpg", kucultulmus);

	

	waitKey(0);
	


    return 0;
}

