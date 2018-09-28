/*
#include <stdlib.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;



int main(int argc, char* argv[]) {
	cv::Mat image = cv::imread("C:/Users/msi/Desktop/aaa.jpg", cv::IMREAD_COLOR);

	int row = image.rows;//421 ����
	int col = image.cols;//559 ����
	int a = 1, b = 1, c = 1, d = 1;
	int color[600][600][3] = { 0 };

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			color[i][j][2] = image.at<cv::Vec3b>(i, j)[2];
			color[i][j][1] = image.at<cv::Vec3b>(i, j)[1];
			color[i][j][0] = image.at<cv::Vec3b>(i, j)[0];
		}
	}

	int avg0 = color[row / 2][col / 2][0] * 10;
	int avg1 = color[row / 2][col / 2][1] * 10;
	int avg2 = color[row / 2][col / 2][2] * 10;

	int upx[3] = { 0 }, downx[3] = { 0 }, leftx[3] = { 0 }, rightx[3] = { 0 };

	int up = 0;
	int down = 0;
	int left = 0;
	int right = 0;

	int upsub = 0;
	int downsub = 0;
	int leftsub = 0;
	int rightsub = 0;

	int sub = 700;
	int sub2 = 0;

	for (int i = row / 2; i < row - 30; i += 10) {
		for (int a = i; a < i + 10; a++) {
			upx[0] += color[a][col / 2][0];
			upx[1] += color[a][col / 2][1];
			upx[2] += color[a][col / 2][2];
		}
		if(abs(abs(avg0-upx[0])+ abs(avg1 - upx[1])+ abs(avg2 - upx[2]))>(upsub+10)){
			
			if ((up != 0) && (abs(i - up) > 30))
				break;
			
			upsub = abs(abs(avg0 - upx[0]) + abs(avg1 - upx[1]) + abs(avg2 - upx[2]));
			up = i;

		}
	}

	for (int i = row / 2; i > 30; i -= 10) {
		for (int a = i; a > i - 10; a--) {
			downx[0] += color[a][col / 2][0];
			downx[1] += color[a][col / 2][1];
			downx[2] += color[a][col / 2][2];
		}
		if (abs(abs(avg0 - downx[0]) + abs(avg1 - downx[1]) + abs(avg2 - downx[2])) > (downsub + 10)) {

						if ((down != 0) && (abs(i - down) >30))
							break;

			downsub = abs(abs(avg0 - downx[0]) + abs(avg1 - downx[1]) + abs(avg2 - downx[2]));
			down = i;

		}
	}
	for (int j = col / 2; j < col - 30; j += 10) {
		for (int a = j; a < j + 10; a++) {
			rightx[0] += color[row / 2][j][0];
			rightx[1] += color[row / 2][j][1];
			rightx[2] += color[row / 2][j][2];
		}
		if (abs(abs(avg0 - rightx[0]) + abs(avg1 - rightx[1]) + abs(avg2 - rightx[2])) > (rightsub + 10)) {

						if ((right != 0) && (abs(j - right) > 30))
							break;

			rightsub = abs(abs(avg0 - rightx[0]) + abs(avg1 - rightx[1]) + abs(avg2 - rightx[2]));
			right = j;

		}
	}
	for (int j = col / 2; j > 30; j -= 10) {
		for (int a = j; a > j - 10; a--) {
			leftx[0] += color[row / 2][j][0];
			leftx[1] += color[row / 2][j][1];
			leftx[2] += color[row / 2][j][2];
		}
		if (abs(abs(avg0 - leftx[0]) + abs(avg1 - leftx[1]) + abs(avg2 - leftx[2])) > (leftsub + 10)) {
		
			if ((right != 0) && (abs(j - right) > 30))
				break;

			leftsub = abs(abs(avg0 - leftx[0]) + abs(avg1 - leftx[1]) + abs(avg2 - leftx[2]));
			left = j;

		}
	}

	

	------------------------------------------------------------------------------------------------------------------

	for (int i = row / 2; i > 10; i--) {
		if ((abs(avg2 - (color[i - 1][col / 2][2] + color[i][col / 2][2] + color[i + 1][col / 2][2])) +
			abs(avg1 - (color[i - 1][col / 2][1] + color[i][col / 2][1] + color[i + 1][col / 2][1])) +
			abs(avg0 - (color[i - 1][col / 2][0] + color[i][col / 2][0] + color[i + 1][col / 2][0]))) > (upsub + 10) &&
			(abs(avg2 - (color[i - 1][col / 2][2] + color[i][col / 2][2] + color[i + 1][col / 2][2])) +
				abs(avg1 - (color[i - 1][col / 2][1] + color[i][col / 2][1] + color[i + 1][col / 2][1])) +
				abs(avg0 - (color[i - 1][col / 2][0] + color[i][col / 2][0] + color[i + 1][col / 2][0]))) < sub) {
			
			if ((up !=0)&&(abs(i - up) > 30))
				break;

			upsub = abs(avg2 - (color[i - 1][col / 2][2] + color[i][col / 2][2] + color[i + 1][col / 2][2])) +
				abs(avg1 - (color[i - 1][col / 2][1] + color[i][col / 2][1] + color[i + 1][col / 2][1])) +
				abs(avg0 - (color[i - 1][col / 2][0] + color[i][col / 2][0] + color[i + 1][col / 2][0]));
			up = i;

		}
	}





	for (int i = row / 2; i < row - 10; i++) {
		if ((abs(avg2 - (color[i - 1][col / 2][2] + color[i][col / 2][2] + color[i + 1][col / 2][2])) +
			abs(avg1 - (color[i - 1][col / 2][1] + color[i][col / 2][1] + color[i + 1][col / 2][1])) +
			abs(avg0 - (color[i - 1][col / 2][0] + color[i][col / 2][0] + color[i + 1][col / 2][0]))) > (downsub + 10) &&
			(abs(avg2 - (color[i - 1][col / 2][2] + color[i][col / 2][2] + color[i + 1][col / 2][2])) +
				abs(avg1 - (color[i - 1][col / 2][1] + color[i][col / 2][1] + color[i + 1][col / 2][1])) +
				abs(avg0 - (color[i - 1][col / 2][0] + color[i][col / 2][0] + color[i + 1][col / 2][0]))) < sub) {
			
			if ((down != 0) && (abs(i - down) > 30))
				break;

			downsub = abs(avg2 - (color[i - 1][col / 2][2] + color[i][col / 2][2] + color[i + 1][col / 2][2])) +
				abs(avg1 - (color[i - 1][col / 2][1] + color[i][col / 2][1] + color[i + 1][col / 2][1])) +
				abs(avg0 - (color[i - 1][col / 2][0] + color[i][col / 2][0] + color[i + 1][col / 2][0]));
			down = i;

		}
	}



	for (int j = col / 2; j > 10; j--) {
		if ((abs(avg2 - (color[row / 2][j - 1][2] + color[row / 2][j][2] + color[row / 2][j + 1][2])) +
			abs(avg1 - (color[row / 2][j - 1][1] + color[row / 2][j][1] + color[row / 2][j + 1][1])) +
			abs(avg0 - (color[row / 2][j - 1][0] + color[row / 2][j][0] + color[row / 2][j + 1][0]))) > (leftsub + 10) &&
			(abs(avg2 - (color[row / 2][j - 1][2] + color[row / 2][j][2] + color[row / 2][j + 1][2])) +
				abs(avg1 - (color[row / 2][j - 1][1] + color[row / 2][j][1] + color[row / 2][j + 1][1])) +
				abs(avg0 - (color[row / 2][j - 1][0] + color[row / 2][j][0] + color[row / 2][j + 1][0]))) < sub) {
			
			if ((left != 0) && (abs(j - left) > 30))
				break;
			
			leftsub = abs(avg2 - (color[row / 2][j - 1][2] + color[row / 2][j][2] + color[row / 2][j + 1][2])) +
				abs(avg1 - (color[row / 2][j - 1][1] + color[row / 2][j][1] + color[row / 2][j + 1][1])) +
				abs(avg0 - (color[row / 2][j - 1][0] + color[row / 2][j][0] + color[row / 2][j + 1][0]));
			left = j;

		}
	}





	for (int j = col / 2; j < col - 10; j++) {
		if ((abs(avg2 - (color[row / 2][j - 1][2] + color[row / 2][j][2] + color[row / 2][j + 1][2])) +
			abs(avg1 - (color[row / 2][j - 1][1] + color[row / 2][j][1] + color[row / 2][j + 1][1])) +
			abs(avg0 - (color[row / 2][j - 1][0] + color[row / 2][j][0] + color[row / 2][j + 1][0]))) > (rightsub + 10) &&
			(abs(avg2 - (color[row / 2][j - 1][2] + color[row / 2][j][2] + color[row / 2][j + 1][2])) +
				abs(avg1 - (color[row / 2][j - 1][1] + color[row / 2][j][1] + color[row / 2][j + 1][1])) +
				abs(avg0 - (color[row / 2][j - 1][0] + color[row / 2][j][0] + color[row / 2][j + 1][0]))) < sub) {

			if ((right != 0) && (abs(j - right) > 30))
				break;

			rightsub = abs(avg2 - (color[row / 2][j - 1][2] + color[row / 2][j][2] + color[row / 2][j + 1][2])) +
				abs(avg1 - (color[row / 2][j - 1][1] + color[row / 2][j][1] + color[row / 2][j + 1][1])) +
				abs(avg0 - (color[row / 2][j - 1][0] + color[row / 2][j][0] + color[row / 2][j + 1][0]));
			right = j;

		}
	}
	cout << up << "\t" << down << "\t" << left << "\t" << right << "\t";


	int up2 = 0;
	int up3 = 999;
	for (int j = left; j < right; j++) {
		for (int i = row / 2; i > 1; i--) {
			if ((abs(avg2 - (color[i - 1][col / 2][2] + color[i][col / 2][2] + color[i + 1][col / 2][2])) +
				abs(avg1 - (color[i - 1][col / 2][1] + color[i][col / 2][1] + color[i + 1][col / 2][1])) +
				abs(avg0 - (color[i - 1][col / 2][0] + color[i][col / 2][0] + color[i + 1][col / 2][0]))) > upsub) {
				up2 = i;
				cout << "1   " << i << "\n";
				break;
			}
		}
		if (up3 > up2)
			up3 = up2;
	}


	int down2 = 0;
	int down3 = 0;
	for (int j = left; j < right; j++) {
		for (int i = row / 2; i < row - 1; i++) {
			if ((abs(avg2 - (color[i - 1][col / 2][2] + color[i][col / 2][2] + color[i + 1][col / 2][2])) +
				abs(avg1 - (color[i - 1][col / 2][1] + color[i][col / 2][1] + color[i + 1][col / 2][1])) +
				abs(avg0 - (color[i - 1][col / 2][0] + color[i][col / 2][0] + color[i + 1][col / 2][0]))) > downsub) {
				down2 = i;
				cout << "2   " << i << "\n";
				break;
			}
		}
		if (down3 < down2)
			down3 = down2;
	}




	int left2 = 0;
	int left3 = 999;
	for (int i = up; i < down; i++) {
		for (int j = col / 2; j > 1; j--) {
			if ((abs(avg2 - (color[row / 2][j - 1][2] + color[row / 2][j][2] + color[row / 2][j + 1][2])) +
				abs(avg1 - (color[row / 2][j - 1][1] + color[row / 2][j][1] + color[row / 2][j + 1][1])) +
				abs(avg0 - (color[row / 2][j - 1][0] + color[row / 2][j][0] + color[row / 2][j + 1][0]))) > leftsub) {
				left2 = j;
				cout << "3   " << j << "\n";
				break;
			}

		}
		if (left3 > left2) {
			left3 = left2;
			cout << "asdf";
		}
	}


	int right2 = 0;
	int right3 = 0;
	for (int i = up; i < down; i++) {
		for (int j = col / 2; j < col - 1; j++) {
			if ((abs(avg2 - (color[row / 2][j - 1][2] + color[row / 2][j][2] + color[row / 2][j + 1][2])) +
				abs(avg1 - (color[row / 2][j - 1][1] + color[row / 2][j][1] + color[row / 2][j + 1][1])) +
				abs(avg0 - (color[row / 2][j - 1][0] + color[row / 2][j][0] + color[row / 2][j + 1][0]))) > rightsub) {
				right2 = j;
				cout << "4   " << j << "\n";
				break;
			}

		}
		if (right3 < right2)
			right3 = right2;
	}
	


	cout << "upsub " << upsub << "\n" << "downsub " << downsub << "\n" << "leftsub " << leftsub << "\n" << "rightsub " << rightsub << "\n";

	
	for (int j = 0; j < col; j++) {
		image.at<cv::Vec3b>(up, j)[2] = 255;
		image.at<cv::Vec3b>(up, j)[1] = 255;
		image.at<cv::Vec3b>(up, j)[0] = 255;
	}
	for (int j = 0; j < col; j++) {
		image.at<cv::Vec3b>(down, j)[2] = 255;
		image.at<cv::Vec3b>(down, j)[1] = 255;
		image.at<cv::Vec3b>(down, j)[0] = 255;
	}
	for (int i = 0; i < row; i++) {
		image.at<cv::Vec3b>(i, left)[2] = 255;
		image.at<cv::Vec3b>(i, left)[1] = 255;
		image.at<cv::Vec3b>(i, left)[0] = 255;
	}
	for (int i = 0; i < row; i++) {
		image.at<cv::Vec3b>(i, right)[2] = 255;
		image.at<cv::Vec3b>(i, right)[1] = 255;
		image.at<cv::Vec3b>(i, right)[0] = 255;
	}



	// create 4 windows
	cv::namedWindow("Original Image");


	// show 4 windows
	cv::imshow("Original Image", image);
	cv::waitKey(0);


	return 0;
}



#include <iostream>

#include <opencv2/highgui/highgui.hpp>

#include <opencv2/core/core.hpp>

#include <opencv2/imgproc/imgproc.hpp>

//#include "watershedSegment.h"

class WatershedSegmenter {

private:

	cv::Mat markers;

public:

	void setMarkers(const cv::Mat& markerImage) {

		markerImage.convertTo(markers, CV_32S); //32��Ʈ��Ŀ�����ڷ�����ȯ

	}

	cv::Mat process(const cv::Mat& image) {

		cv::watershed(image, markers);

		//���Ұ����markers������

		return markers;

	}

	cv::Mat getSegmentation() {

		cv::Mat tmp;

		markers.convertTo(tmp, CV_8U); return tmp;

	}

	cv::Mat getWatersheds() {

		cv::Mat tmp;

		markers.convertTo(tmp, CV_8U, 255, 255); return tmp;

	}

};


int main() {

	cv::Mat image = cv::imread("C:/Users/msi/Desktop/aaa.jpg");

	cv::imshow("Original Image", image); //����

	cv::Mat gray_image;

	cv::cvtColor(image, gray_image, CV_BGR2GRAY);

	cv::imshow("Gray Image", gray_image); //gray����

	cv::Mat binary_image;

	cv::threshold(gray_image, binary_image, 90, 255, cv::THRESH_BINARY_INV);

	cv::imshow("Binary Image", binary_image); //�����������κ�ȯ(���Ͼ�Բ�inverse)


	cv::Mat fg;

	cv::erode(binary_image, fg, cv::Mat(), cv::Point(-1, -1), 12); //ħ��

	cv::imshow("Foreground", fg);


	cv::Mat bg;

	cv::dilate(binary_image, bg, cv::Mat(), cv::Point(-1, -1), 40); //��â

	cv::threshold(bg, bg, 1, 128, cv::THRESH_BINARY_INV);

	//(1��������)�����128, (1����ū)��ü0. Threshold����INVERSE ����.

	cv::imshow("Background", bg);


	cv::Mat markers(binary_image.size(), CV_8U, cv::Scalar(0));

	markers = fg + bg; //ħ��+��â= ��Ŀ������������. ���ͽ���˰����� �Է����� ����.

	cv::imshow("Marker", markers);


	WatershedSegmenter segmenter; //���ͽ�����Ұ�ü����

	segmenter.setMarkers(markers); //set��Ŀ�ϸ�signed �̹����ιٲ�

	segmenter.process(image); //0,128,255�α�����

	cv::imshow("Segmentation", segmenter.getSegmentation());


	cv::imshow("Watershed", segmenter.getWatersheds()); // 0,255�α�����

	cv::waitKey(0);

	return 0;

}

*/


#include <iostream>
#include <cstdio>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;

cv::Mat masking(cv::Mat, int, int);//return masking image
cv::Mat cutting(cv::Mat, cv::Mat, int, int);//return cuting image
void histogram(cv::Mat);



class WatershedSegmenter {

private:

	cv::Mat markers;

public:

	void setMarkers(const cv::Mat& markerImage) {

		markerImage.convertTo(markers, CV_32S); //32��Ʈ��Ŀ�����ڷ�����ȯ

	}

	cv::Mat process(const cv::Mat& image) {

		cv::watershed(image, markers);

		//���Ұ����markers������

		return markers;

	}

	cv::Mat getSegmentation() {

		cv::Mat tmp;

		markers.convertTo(tmp, CV_8U); return tmp;

	}

	cv::Mat getWatersheds() {

		cv::Mat tmp;

		markers.convertTo(tmp, CV_8U, 255, 255); return tmp;

	}

};




int main(int argc, char* argv[]) {
	cv::Mat image = cv::imread("C:/Users/msi/Desktop/aaa.jpg", cv::IMREAD_COLOR);//���� �̹���
	int row = image.rows;//470 ���� 427
	int col = image.cols;//624 ���� 398
	cv::Mat black = masking(image, row, col);//��� �̹���
	cv::Mat capture = cutting(image, black, row, col);//�߸� �̹���






	cv::Mat image2 = image	;

		cv::imshow("Original Image", image2); //����

		cv::Mat gray_image;

		cv::cvtColor(image2, gray_image, CV_BGR2GRAY);

		cv::imshow("Gray Image", gray_image); //gray����

		cv::Mat binary_image;

		cv::threshold(gray_image, binary_image, 90, 255, cv::THRESH_BINARY_INV);

		cv::imshow("Binary Image", binary_image); //�����������κ�ȯ(���Ͼ�Բ�inverse)


		cv::Mat fg;

		cv::erode(binary_image, fg, cv::Mat(), cv::Point(-1, -1), 15); //ħ��

		cv::imshow("Foreground", fg);


		cv::Mat bg;

		cv::dilate(binary_image, bg, cv::Mat(), cv::Point(-1, -1), 40); //��â

		cv::threshold(bg, bg, 1, 128, cv::THRESH_BINARY_INV);

		//(1��������)�����128, (1����ū)��ü0. Threshold����INVERSE ����.

		cv::imshow("Background", bg);


		cv::Mat markers(binary_image.size(), CV_8U, cv::Scalar(0));

		markers = fg + bg; //ħ��+��â= ��Ŀ������������. ���ͽ���˰����� �Է����� ����.

		cv::imshow("Marker", markers);


		WatershedSegmenter segmenter; //���ͽ�����Ұ�ü����

		segmenter.setMarkers(markers); //set��Ŀ�ϸ�signed �̹����ιٲ�

		segmenter.process(image2); //0,128,255�α�����

		cv::imshow("Segmentation", segmenter.getSegmentation());


		cv::imshow("Watershed", segmenter.getWatersheds()); // 0,255�α�����





	histogram(capture);//���� �Ǵ�
	cv::imshow("original", image);
	cv::imshow("masking", black);
	cv::imshow("slice", capture);


	cv::waitKey(0);
	return 0;
}

cv::Mat masking(cv::Mat image, const int row, const int col) {
	int row_start = (row / 2) - 2;
	int col_start = (col / 2) - 2;
	int red = 0, green = 0, blue = 0;

	for (int i = 0; i < 5; i++) { //�߰��� �ֺ� 25 �ȼ��� rgb���� ��� ���
		for (int j = 0; j < 5; j++) {
			red += image.at<cv::Vec3b>(i + row_start, j + col_start)[2];
			green += image.at<cv::Vec3b>(i + row_start, j + col_start)[1];
			blue += image.at<cv::Vec3b>(i + row_start, j + col_start)[0];
		}
	}
	red /= 25;
	green /= 25;
	blue /= 25;

	cout << "rgb : " << red * 0.3 << ", " << green * 0.3 << ", " << blue * 0.3 << endl;
	cout << "rgb : " << red * 1.3 << ", " << green * 1.3 << ", " << blue * 1.3 << endl;

	cv::Mat black;
	cv::inRange(image, cv::Scalar((blue*0.3), (green*0.3), (red*0.3)), cv::Scalar((blue*1.3), (green*1.3), (red*1.3)), black);//��� rgb�� ���Ѱ��� ���Ѱ� ���� ����ŷ
	cv::Mat mask = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3), cv::Point(1, 1));//���� ����� ����ŷ
	cv::erode(black, black, /*cv::Mat(3, 3, CV_8U, cv::Scalar(1))*/mask, cv::Point(-1, -1), 1);//���꿬�� ����(������ ĵ����)

	return black;//������� ����ŷ�� �̹��� ��ȯ
}

cv::Mat cutting(cv::Mat image, cv::Mat black, const int row, const int col) {//����ŷ�� �̹����� ������� ���� �̹����� �ڸ�
	int left = 0, right = 0, top = 0, bottom = 0;
	int read = -1;
	bool flag = false;
	for (int i = 0; i < row; i++) {//find top
		for (int j = 0; j < col; j++) {
			read = black.at<uchar>(i, j);
			if (read == 255) {
				top = i;
				read = -1;
				flag = true;
				break;
			}
		}
		if (flag) {
			flag = false;
			break;
		}
	}
	for (int i = row - 1; i >= 0; i--) {//find bottom
		for (int j = 0; j < col; j++) {
			read = black.at<uchar>(i, j);
			if (read == 255) {
				bottom = i;
				read = -1;
				flag = true;
				break;
			}
		}
		if (flag) {
			flag = false;
			break;
		}
	}
	for (int i = 0; i < col; i++) {//find left
		for (int j = 0; j < row; j++) {
			read = black.at<uchar>(j, i);
			if (read == 255) {
				left = i;
				read = -1;
				flag = true;
				break;
			}
		}
		if (flag) {
			flag = false;
			break;
		}
	}
	for (int i = col - 1; i >= 0; i--) {//find right
		for (int j = 0; j < row; j++) {
			read = black.at<uchar>(j, i);
			if (read == 255) {
				right = i;
				read = -1;
				flag = true;
				break;
			}
		}
		if (flag) {
			flag = false;
			break;
		}
	}
	cout << "left" << left << "right" << right << endl;
	cout << "top" << top << "bottom" << bottom << endl;

	cv::Mat capture = image;
	if (!(left == 0 || right == 0 || top == 0 || bottom == 0))//���� ó��
		capture = image(cv::Range(top, bottom), cv::Range(left, right));

	return capture;//�߸� �̹��� ����
}

void histogram(cv::Mat capture) {
	cv::Mat dst;
	cv::Mat bgr[3];
	cv::Mat hist; //Histogram ��갪 ����
	int channel[] = { 0,1,2 };
	int histSize = 255; //Histogram ���ΰ��� ��
	int count = 0;
	float range[] = { 0,255.0 };
	const float * ranges = range;
	int hist_w = 512; int hist_h = 400;
	int number_bins = 255;
	int bin_w = cvRound((double)hist_w / number_bins);
	unsigned row2 = capture.rows; unsigned col2 = capture.cols; //�ڸ� ������ ũ�� ����

	cvtColor(capture, dst, CV_HSV2BGR); //Color ����
	calcHist(&dst, 3, channel, cv::Mat(), hist, 1, &histSize, &ranges, true, false); //Histogram ���
	cv::Mat histImage(hist_h, hist_w, CV_8UC3, cv::Scalar(0, 0, 0));
	normalize(hist, hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());

	for (int i = 1; i < number_bins; i++) {	//Histogram �� �׸���
		line(histImage, cv::Point(bin_w*(i - 1), hist_h - cvRound(hist.at<float>(i - 1))), cv::Point(bin_w*(i), hist_h - cvRound(hist.at<float>(i))), cv::Scalar(0, 255, 0), 2, 8, 0);
	}

	for (int i = 0; i < histSize; i++) { //���� �پ缺 ����
		printf("%d��° %f \n", i, hist.at<float>(i));
		if (hist.at<float>(i) > 229) {
			count++;
		}
	}

	printf("ī��Ʈ �� : %d\n", count);

	if (count > 15) {
		printf("�پ��� ������ ���Դϴ�.");
	}
	else {
		printf("�پ��� ������ ������ �ʽ��ϴ�.");
	}

	cv::namedWindow("Histogram", CV_WINDOW_AUTOSIZE);
	cv::imshow("HSV2BGR", dst);
	cv::imshow("Histogram", histImage);
}


