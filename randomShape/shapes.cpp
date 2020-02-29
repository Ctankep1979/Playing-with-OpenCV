#include "shapes.hpp"


namespace Shape
{

    shape::shape(cv::Mat& img): image{img}
    {

    }

    shape::~shape(){}

    void
    shape::create(){}


    circle::circle(cv::Mat& img): shape(img)
    {

    }

    circle::~circle(){}

    void
    circle::create(cv::Point p, int r)
    {
        cv::Point shadow{p.x+5, p.y+5};
        cv::circle(image,shadow,r+2,SHADOW,-1);
        cv::circle(image,p,r,cv::Scalar(0,255,0),-1);
    }


    void
    circle::create(cv::Mat& img, cv::Point p, int r)
    {
        cv::Point shadow{p.x+5, p.y+5};
        cv::circle(img,shadow,r+2,SHADOW,-1);
        cv::circle(img,p,r,cv::Scalar(0,255,0),-1);
    }

    rectangle::rectangle(cv::Mat& img): shape(img)
    {

    }

    rectangle::~rectangle(){}


    void
    rectangle::create(cv::Point p1, cv::Point p2)
    {

        cv::Point shp1{p1.x+3, p1.y+3};
        cv::Point shp2{p2.x+5, p2.y+5};

        cv::rectangle(image,shp1, shp2,SHADOW,-1);
        cv::rectangle(image,p1, p2,cv::Scalar(0,0,255),-1);

    }

    void
    rectangle::create(cv::Mat& img, cv::Point p1, cv::Point p2)
    {

        cv::Point shp1{p1.x+3, p1.y+3};
        cv::Point shp2{p2.x+5, p2.y+5};

        cv::rectangle(img,shp1, shp2,SHADOW,-1);
        cv::rectangle(img,p1, p2,cv::Scalar(0,0,255),-1);

    }

} // namespace Shape

