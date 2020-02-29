#ifndef _H_DRAW_
#define _H_DRAW_


#include <chrono>
#include <thread>
#include <mutex>
#include <vector>
#include "shapes.hpp"

#include <iostream>


const int ROWS = 500;
const int COLS = 500;
const cv::Vec3b BGCOLOR{200,200,200};

class draw
{
public:
    draw();
    // draw(int count);
    ~draw();

public:

    static cv::Mat _convas;
    static std::mutex m;
    
    static Shape::circle _circle;
    static Shape::rectangle _rect;
    // static std::unique_lock<std::mutex> ulock;
    

public:
    static void
    drawCircle();
    static void
    drawRect();

    void
    run();

    static bool
    checkCollision(cv::Mat& mask);

public:
    

};




#endif