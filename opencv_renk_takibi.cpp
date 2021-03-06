#include "stdafx.h"
#include <iostream>
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\imgproc\imgproc.hpp"

using namespace std;
using namespace cv;

int main()
{
	VideoCapture cam(0);
	if (cam.isOpened())
		cout << "kamera hata" << endl;

	namedWindow("kontrol", CV_WINDOW_AUTOSIZE);

	int Hmin = 170;
	int Hmax = 179;

	int Smin = 150;
	int Smax = 255;

	int Vmin = 60;
	int Vmax = 255;

	createTrackbar("MinH", "kontrol", &Hmin, 179);
	createTrackbar("MaxH", "kontrol", &Hmax, 179);

	createTrackbar("MinS", "kontrol", &Smin, 255);
	createTrackbar("MaxS", "kontrol", &Smax, 255);


	createTrackbar("MinV", "kontrol", &Vmin, 255);
	createTrackbar("MaxV", "kontrol", &Vmax, 255);

	int eskix = -1;
	int eskiy = -1;

	Mat araframe;
	cam.read(araframe);
	Mat cizgiresim = Mat::zeros(araframe.size(), CV_8UC3);

	while (true)
	{

		Mat yeniframe;
		bool oku = cam.read(yeniframe);

		Mat HSVres;
		//webcamdan gelen BGR formatındaki görüntü HSV formatına çevrildi
		//Renk tanıma için
		cvtColor(yeniframe, HSVres, COLOR_BGR2HSV);

		Mat isres;
		//inrange komutu hsvnin belirtilen değerler aralığındaki pikseller 1 diğerlerini 0 olarak kabul eder
		inRange(HSVres, Scalar(Hmin, Smin, Vmin), Scalar(Hmax, Smax, Vmax),isres);
		//morfolojik işlemler tuz karabiber gürültüler azaltılacak
		erode(isres, isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		dilate(isres, isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		erode(isres, isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		//MOments fonksiyonu siyah beyaz framelerdeki beyaz objelerin konumunu belirler
		Moments konum = moments(isres);
		//moment bulundu konum değeri atandı
		double yeksen = konum.m01;//piksel değeri 1 olan piksellerin y eks konumu
		double xeksen = konum.m10;//x eks
		double alan = konum.m00;//değeri 1 olan pikselllerin alanı
		if (alan > 10000)
		{
			int yenix = xeksen / alan;
			int yeniy = yeksen / alan;


			if (eskix >= 0 && eskiy >= 0 && yenix >= 0,yeniy>=0 )
			{
				line(cizgiresim, Point(yenix, yeniy), Point(eskix, eskiy), Scalar(0, 0, 255), 2);
			}
			eskix = yenix;
			eskiy = yeniy;
		}
		imshow("siyah beyaz resim", isres);

		yeniframe = yeniframe + cizgiresim;
		imshow("orjinal", yeniframe);
		if(waitKey(30)==27)
		{
			break;
		}
	}

    return 0;
}

