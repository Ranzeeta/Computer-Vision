#include <opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(){
    Mat moon;
    Mat salt_pepper;
    Mat left_moon,right_moon,unsharp_moon,sharp_right,sharpened_moon;
    Mat leftsalt_roi;

//moon
    moon= imread("Moon.jpeg",0);
    if(moon.empty())
    {
        cout<< "Could not open the file or file doesn't exist"<<endl;
        return -1;
    }
   
    int width,height;
    width=moon.cols;
    height=moon.rows;

    left_moon=moon(Rect(0,0,width/2,height));
    right_moon=moon(Rect(width/2,0,width/2,height));

    Mat blur_right;
    GaussianBlur(right_moon,blur_right,Size(15,15),0,0,BORDER_DEFAULT);

    unsharp_moon= right_moon-blur_right;

    double k=2.0;
    sharp_right= right_moon+ k* unsharp_moon;

    sharpened_moon=moon.clone();
    left_moon.copyTo(sharpened_moon(Rect(0,0,width/2,height)));
   // unsharp_moon.copyTo(sharpened_moon(Rect(width/2,0,width/2,height)));
    sharp_right.copyTo(sharpened_moon(Rect(width/2,0,width/2,height)));
  
//saltnpepper
    salt_pepper= imread("saltnpepper.png",0);
    if(salt_pepper.empty())
    {
        cout<< "Could not open the file or file doesn't exist"<<endl;
        return -1;
    }
    int x=salt_pepper.cols;
    int y=salt_pepper.rows;
    Rect left_salt(0,0,x/2,y);
    leftsalt_roi=salt_pepper(left_salt); 
   
    Mat mfsalt,salt_pepper_filtered;
    medianBlur(leftsalt_roi,mfsalt,9);
    salt_pepper_filtered=salt_pepper.clone();

    mfsalt.copyTo(salt_pepper_filtered(left_salt));

//outputs
    namedWindow("Moon", WINDOW_AUTOSIZE);
    imshow("Moon",moon); //input image

    namedWindow("Moon Filtered", WINDOW_AUTOSIZE);
    imshow("Moon Filtered",sharpened_moon); //output image

    namedWindow("SaltnPepper", WINDOW_AUTOSIZE);
    imshow("SaltnPepper",salt_pepper); //input image
    namedWindow("SaltnPepper Filtered", WINDOW_AUTOSIZE);
    imshow("SaltnPepper Filtered",salt_pepper_filtered); //output image
    
    waitKey(0);
    return 0;
}