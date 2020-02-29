#include "draw.hpp"
#include <iostream>

using namespace cv;

int main()
{
    draw d{};
    d.run();
    
    // Mat img(300,300,CV_8UC3,Scalar(255,255,255));
    // circle(img,Point(40,40),6,Scalar(255,4,4));
    // d.checkCollision(img);
    
    // Mat img(300,300,CV_8UC3,Scalar(255,255,255));
    // Shape::circle _shape{img};
    // Shape::rectangle _rect{img};

    // namedWindow("Image", WINDOW_AUTOSIZE);
    
    // _shape.create(20, Point(50,50), Scalar(0,0,255));

    // imshow("Image", img);
    // waitKey();
    // _shape.create(20, Point(100,50), Scalar(0,255,0));

    // imshow("Image", img);
    // waitKey();

    // _rect.create(Point(100,50), Point(200,100), Scalar(255,0,0));


    // imshow("Image", img);

    // waitKey();
    // destroyWindow("Image");

    return 0;
}