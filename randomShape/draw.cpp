#include "draw.hpp"

cv::Mat draw::_convas{cv::Mat(cv::Size(ROWS,COLS), CV_8UC3, BGCOLOR)};
std::mutex draw::m;
// std::unique_lock<std::mutex> draw::ulock(m,std::defer_lock);

Shape::circle draw::_circle{_convas};
Shape::rectangle draw::_rect{_convas};

draw::draw()
{

}

draw::~draw()
{

}

// draw::draw(int count)
// {

// }

bool
draw::checkCollision(cv::Mat& mask)
{

    for(int i=0;i < mask.rows; i++)
    {
        for(int j=0;j < mask.cols; j++)
        {
            if((mask.at<cv::Vec3b>(cv::Point(i,j)) != BGCOLOR && 
                _convas.at<cv::Vec3b>(cv::Point(i,j)) != BGCOLOR) &&
                 (_convas.at<cv::Vec3b>(cv::Point(i,j)) != _circle.SHADOW))
                return true;
        }

    }
    return false;
}

void
draw::drawCircle()
{
    cv::Point p;
    cv::Mat mask(cv::Size(ROWS,COLS), CV_8UC3, BGCOLOR);
    int x,y;
    cv::namedWindow("Image",cv::WINDOW_AUTOSIZE);
    cv::imshow("Image",_convas);

    while(true)
    {
        
        x = rand()%500;
        y = rand()%500;
        p = cv::Point(x,y);
        mask = cv::Mat(cv::Size(ROWS,COLS), CV_8UC3, BGCOLOR);
        _circle.create(mask,p,20);
        // cv::circle(mask,p,20,cv::Scalar(0,255,0),-1);
        if(!checkCollision(mask))
        {
            m.lock();
            _circle.create(p,20);
            // cv::circle(_convas,p,20,cv::Scalar(0,255,0),-1);
            cv::imshow("Image",_convas);
            m.unlock(); 
        }
        cv::waitKey(100);
    }
}


void
draw::drawRect()
{
    cv::Mat mask(cv::Size(ROWS,COLS), CV_8UC3, BGCOLOR);
    cv::Point p1;
    cv::Point p2;
    
    int x,y;
    
    cv::imshow("Image",_convas);

    while(true)
    {
        x = rand()%500;
        y = rand()%500;
        p1 = cv::Point(x,y);
        p2 = cv::Point(x+10,y+10);
        mask = cv::Mat(cv::Size(ROWS,COLS), CV_8UC3, BGCOLOR);
        _rect.create(mask,p1,p2);
        // cv::rectangle(mask,p1, p2,cv::Scalar(0,0,255),-1);
        if(!checkCollision(mask))
        {
            m.lock();
            _rect.create(p1,p2);
            cv::imshow("Image",_convas);
            m.unlock(); 
        }

        cv::waitKey(100);
        //std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void
draw::run()
{
    
    cv::namedWindow("Image",cv::WINDOW_AUTOSIZE);
    std::vector<std::thread> _thread;
    _thread.push_back(std::thread(draw::drawCircle));
    _thread.push_back(std::thread(draw::drawRect));
    _thread[0].join();
    _thread[1].join();   
}