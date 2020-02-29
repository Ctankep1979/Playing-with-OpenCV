#ifndef _H_SHAPES_
#define _H_SHAPES_

#include <opencv2/opencv.hpp>

namespace Shape
{

    class shape
    {
    public:
        shape(cv::Mat& img);
        ~shape();

    public:
        cv::Vec3b SHADOW{150,150,150};
        virtual void
        create();

    public:
        cv::Mat& image;
    };


    class circle : public shape
    {
    public:
        circle(cv::Mat& img);
        ~circle();

    public:
        void
        create(cv::Point p, int r);

        void
        create(cv::Mat& img, cv::Point p, int r);

    };

    class rectangle : public shape
    {
    public:
        rectangle(cv::Mat& img);
        ~rectangle();

    public:
        void
        create(cv::Point p1, cv::Point p2);

        void
        create(cv::Mat& img, cv::Point p1, cv::Point p2);

    };

}


#endif