#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>

using namespace std;
using namespace cv;


void WebCamera()
{
	string name = "WebCam";
	VideoCapture webcam(0);

	if (webcam.isOpened())
	{
		double fps = webcam.get(CAP_PROP_FPS);

		if (fps < 1)
		{
			fps = 23;
		}

		Mat frame;
		namedWindow(name);

		while (true)
		{
			if (webcam.read(frame))
			{
				imshow("name", frame);
			}

			if (waitKey(1000 / fps) >= 0)
			{
				break;
			}


		}
		webcam.release();
		destroyWindow(name);

	}

}


void IPcamera(string ipUrl)
{
	string ekran = "IP Kamera " +ipUrl;

	VideoCapture ipcam(ipUrl);

	ipcam.open(ipUrl);

	if (ipcam.isOpened())
	{
		double fps=ipcam.get(CAP_PROP_FPS);

		if (fps < 1)
		{
			fps = 23;
		}

		Mat frame;

		namedWindow(ekran);

		while (true)
		{
			//Kamerayý açtým çalýþmaya devam edecek mi?
			if (ipcam.grab())
			{
				ipcam.retrieve(frame);
				imshow(ekran, frame);
			}

			if (waitKey(1000 / fps) >= 0)
			{
				break;
			}
		}
		
		ipcam.release();
		destroyWindow(ekran);

	}
	else
	{
		cout << "ÝPCam Acilamadi!!";
	}

}





int main()
{
	WebCamera();

	/*
	string ip = "rtsp://camip:Port/live/0/MAIN";//kamera arayüzü

	 IPcamera(ip);
	
	*/
	
	waitKey(0);
}

