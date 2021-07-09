# MJPEGWriter
OpenCV Video HTTP Streaming via MJPEG.
Based on the code found in 
[StackExchange -  CodeReview](http://codereview.stackexchange.com/questions/124321/multithreaded-mjpg-network-stream-server/156915#156915) and [Answers - OpenCV](http://answers.opencv.org/question/6976/display-iplimage-in-webbrowsers/)

## Changes from the original
* Change UnitV2's output pixel format from YUYV to MJPG
* Skip frame data decoding and encoding
* Camera resolution change by argument at launch 
* Remove unnecessary wait for UnitV2

## Compiling
Cross-compile with C++11, OpenCV libraries and pthread.<br>
You can use cmake.

## Usage
```
sudo MJPEGWriter <mode>

<mode>
    0:352x288  about 14fps
    1:640x480  about 12fps
    2:800x600  about 10fps
    3:1280x720 about 14fps
```
Then, open `http://10.254.239.1/` in your browser
