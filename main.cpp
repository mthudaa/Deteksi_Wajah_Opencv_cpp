#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

CascadeClassifier fc;

void main(){
	Mat img;
	VideoCapture cap(0);
	fc.load("wajah.xml");

	while (true) {
		cap.read(img);
		vector<Rect> wajah;
		fc.detectMultiScale(img, wajah, 1.1, 5);
		for (int i = 0; i < wajah.size(); i++) {
			rectangle(img, wajah[i].tl(), wajah[i].br(), Scalar(0, 255, 0));
		}
		imshow("Wajah", img);
		waitKey(1);
	}
}
