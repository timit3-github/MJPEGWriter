#include "MJPEGWriter.h"

int main(int argc, char *argv[])
{
    MJPEGWriter test(80);

    int mode = 1;
    Size size;
    if (argc > 1)
        mode = atoi(argv[1]);
    else
    {
        std::cout << "usage: " << argv[0] << " <mode>" << std::endl;
        std::cout << "                          camera   capture" << std::endl;
        std::cout << "  mode = 0 :  352 x  288 ( 30fps -> 14fps )" << std::endl;
        std::cout << "  mode = 1 :  640 x  480 ( 15fps -> 12fps )" << std::endl;
        std::cout << "  mode = 2 :  800 x  600 ( 10fps -> 10fps )" << std::endl;
        std::cout << "  mode = 3 : 1280 x  720 ( 30fps -> 14fps )" << std::endl;
        return 1;
    }
    switch (mode)
    {
    case 0:
        size = Size(352, 288);
        break;
    case 1:
        size = Size(640, 480);
        break;
    case 2:
        size = Size(800, 600);
        break;
    case 3:
        size = Size(1280, 720);
        break;
    // case 4: //MJPG is not available with 1600x1200
    //     size = Size(1600, 1200);
    //     break;
    default:
        size = Size(640, 480);
        break;
    }

    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        printf("no cam found ;(.\n");
        pthread_exit(NULL);
    }

    cap.set(cv::CAP_PROP_FRAME_WIDTH, size.width);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, size.height);
    cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G')); //change format from YUYV to MJPG
    cap.set(cv::CAP_PROP_CONVERT_RGB, false);                                  //skip decode MJPG

    Mat frame;
    cap >> frame;

    test.write(frame);
    // frame.release();
    test.start();
    while (cap.isOpened())
    {
        cap >> frame;
        test.write(frame);
        // frame.release();
    }
    test.stop();
    exit(0);

}
