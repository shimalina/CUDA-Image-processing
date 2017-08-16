#include <opencv2/opencv.hpp>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <highgui.h>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <sys/timeb.h>
#include <time.h>
#include <cstdlib>
#include <unistd.h>
using namespace cv;
using namespace std;

#define DEBUG_TIME


int main(int argc, char** argv)
{
Mat img = imread(argv[1]);


waitKey();
#ifdef DEBUG_TIME
    //Start clock
    struct timeb start_time_st;
    ftime(&start_time_st);
#endif



Mat img_gray = img.clone();
cvtColor(img, img_gray, CV_RGB2GRAY);
//cvWaitKey(10000);

usleep(1000000);
#ifdef DEBUG_TIME
    // Stop clock
    struct timeb stop_time_st;
    ftime(&stop_time_st);
    double elapsed = ((double) stop_time_st.time + ((double) stop_time_st.millitm * 0.001)) -
                     ((double) start_time_st.time + ((double) start_time_st.millitm * 0.001));

	std::cout << "* Time elapsed: " << std::setprecision(5) << elapsed << " sec" << std::endl;
#endif

bool ret = imwrite("Debug/serial.png", img_gray);
if(ret) {
    cout << "Save worked." << endl;
} else {
    cout << "Save failed." << endl;
}
 

 return 0;
}