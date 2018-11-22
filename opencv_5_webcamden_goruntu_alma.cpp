
#include "stdafx.h"
#include "opencv2\opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
	VideoCapture video(0);//dahili webcam için 0 harici webcalar için 1,2,3 vs 
	if (!video.isOpened())
		cout << "webcam acilmadi" << endl;
	namedWindow("webcam", CV_WINDOW_AUTOSIZE);//webcam isimli windows penceresi olustu

	while (true)//sonsuz dongu
	{
		Mat img;
		bool frameoku = video.read(img);//videoyu imgye frame frame aktarıyor
		if (!frameoku)//okunacak frame kalmadıysa
		{
			cout << "bitti" << endl;
			break;
		}

		imshow("webcam", img);
		if (waitKey(30) == 27)//27 ascii-> ESC tusu
		{cout << "cikis yapildi" << endl;
		destroyWindow("webcam");
		break;
		}
			
	}

	system("Pause");

    return 0;
}

