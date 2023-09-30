s
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap("background.mp4");

    if(!cap.isOpened())
    {
        cout << "Error opening video stream or file" << endl;        // Check if camera opened successfully
        return -1;
    }
    double showVid=3.0;     //video runs for 3 sec
    int frameDelay=20;      //delay in ms--> can be changed

    int totalFrames = int(cap.get(CAP_PROP_FRAME_COUNT));       // Get the total number of frames in the video
    int currentFrame = 0; // Initialize the current frame counter

    while(1){
 
        Mat video;
        cap >> video;       // Capture frame-by-frame
    
        // If the frame is empty, break immediately
        if (video.empty())
            break;
       
        imshow( "background.mp4", video );                // Display the resulting frame

        // Print the current frame number and total number of frames
        cout << "Current Frame is " << currentFrame << " and Total Frame is " << totalFrames << endl;
    
        // Press  ESC on keyboard to exit
        char c=(char)waitKey(frameDelay);
        if(c==27)
            break;
        
        if (cap.get(CAP_PROP_POS_MSEC) >= (showVid * 1000))             // Check elapsed time and break if it exceeds the desired duration
            break;
        
        currentFrame++; // Increment the current frame counter
  }
  
  
    cap.release();                  // When everything done, release the video capture object
    waitKey(0);
}
