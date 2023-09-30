i#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat image;
    Mat rotated_image;
    Mat neg_image;
    int value, image_height,image_width;

    image=imread("lena.png",0);

    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    image_height=image.rows;
    image_width=image.cols;

    rotated_image = Mat(image_width, image_height, image.type());

   //for rotating 90 and negative transformation

    for(int j=0;j<image_height;j++){
		for(int i=0;i<image_width;i++)
        {
			//rotated_image.at<uchar>(i,j)=image.at<uchar>(image_height-1-j,i);
            uchar pixel_value = image.at<uchar>(image_height - 1 - j, i);
            if (pixel_value < 127) {
                rotated_image.at<uchar>(i, j) = 255 - pixel_value;
            } else {
                rotated_image.at<uchar>(i, j) = pixel_value; // Keep the pixel value unchanged
            }
        }
    }
            
    namedWindow("Gray Image", WINDOW_AUTOSIZE);
    imshow("Gray Image",image); //input image

    namedWindow("Result", WINDOW_AUTOSIZE);
    imshow("Result",rotated_image); //rotated 90 clockwise

    waitKey(0);
    

}