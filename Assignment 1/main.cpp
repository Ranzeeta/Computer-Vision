#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat video;
    int total_frame,current_frame,delay;
    double show_vid=3.0;


    VideoCapture og_vid("background.mp4");
    delay=int(og_vid.get(CAP_PROP_FPS));

    //check if file exists 
    if (og_vid.isOpened()==0){
        cout<< "no such file"<<endl;
        waitKey(0);
        return -1;
    }

    total_frame=int(og_vid.get(CAP_PROP_FRAME_COUNT));  //gives total count of frames
    current_frame=0;
    

    while(1){
        og_vid>>video;

        if (video.empty()){
            cout<<"end of video"<<endl;
            break;
        }

        imshow("video",video);
        cout<< "The current Frame is "<<current_frame<<" and total frame is "<<total_frame<< endl;

        int key = waitKey(delay);  // Wait for 30 milliseconds (suitable for video playback)
        if (key == 27) {  // 'Esc' key to exit
            break;
        }

        current_frame++;
        
    }
    og_vid.release();
    

}