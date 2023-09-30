#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    Mat moon;
    Mat salt_pepper;

    moon = imread("Moon.jpeg", 0);
    if (moon.empty()) {
        cout << "Could not open the file or file doesn't exist" << endl;
        return -1;
    }

    salt_pepper = imread("saltnpepper.png", 0);
    if (salt_pepper.empty()) {
        cout << "Could not open the file or file doesn't exist" << endl;
        return -1;
    }

    int width = moon.cols;
    int height = moon.rows;

    // Split the moon image into left and right halves
    Mat left_half = moon(Rect(0, 0, width / 2, height));
    Mat right_half = moon(Rect(width / 2, 0, width / 2, height));

    // Apply Gaussian blur to the right-half of the image
    Mat blurred_right;
    GaussianBlur(right_half, blurred_right, Size(15, 15), 0, 0, BORDER_DEFAULT);

    // Calculate the unsharp mask
    Mat unsharp_mask = right_half - blurred_right;

    // Adjust the strength of the unsharp mask (k)
    double k = 2.0;
    Mat scaled_unsharp_mask = k * unsharp_mask;

    // Add the scaled unsharp mask to the original right-half to sharpen it
    Mat sharpened_right = right_half + scaled_unsharp_mask;

    // Merge the left and sharpened right halves to get the final sharpened image
    Mat sharpened_moon = moon.clone();
    left_half.copyTo(sharpened_moon(Rect(0, 0, width / 2, height)));
    sharpened_right.copyTo(sharpened_moon(Rect(width / 2, 0, width / 2, height)));

    namedWindow("Moon", WINDOW_AUTOSIZE);
    imshow("Moon", moon); // input image

    namedWindow("Sharpened Moon", WINDOW_AUTOSIZE);
    imshow("Sharpened Moon", sharpened_moon); // sharpened image

    namedWindow("SaltnPepper", WINDOW_AUTOSIZE);
    imshow("SaltnPepper", salt_pepper); // input image

    waitKey(0);
    return 0;
}
