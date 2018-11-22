#include "stdafx.h"
#include "opencv2\opencv.hpp"

using namespace std;
using namespace cv;


int main()
{
	VideoCapture video("video.avi");
	if (!video.isOpened())
		cout << "video açılmadı" << endl;
	video.set(CV_CAP_PROP_POS_MSEC, 3000);
	double fps = video.get(CV_CAP_PROP_FPS);
	cout << "video fps: " << fps << endl;
	namedWindow("video", CV_WINDOW_AUTOSIZE);

	while (true)
	{
		Mat img;
		bool frameokundu = video.read(img);
		if(!frameokundu)//okunacak frame kalmadıysa
		{
			cout << "video bitti" << endl;
			break;
		}

		imshow("video", img);
		if (waitKey(30)==27)
		{
			cout << "esc ile çıkış yapıldı" << endl;
			destroyWindow("video");//pencere kapandı
			break;
		}

	}
		getchar();
		system("Pause");



	

    return 0;
}

