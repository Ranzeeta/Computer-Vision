#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap("Road.mp4");

    if(!cap.isOpened())
    {
        cout << "Error opening video stream or file" << endl;        // Check if camera opened successfully
        return -1;
    }
    
    while(1){
 
        Mat video;
        cap >> video;       // Capture frame-by-frame
    
        // If the frame is empty, break immediately
        if (video.empty())
            break;
       
        imshow( "Road.mp4", video );                // Display the resulting frame

        // Press  ESC on keyboard to exit
        char c=30;
        if(c==27)
            break;
                
  }
  
    cap.release();                  // When everything done, release the video capture object
    waitKey(0);
}
