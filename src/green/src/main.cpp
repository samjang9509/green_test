#include "green/main.hpp"


int mouseInterface::runloop()
{
    cv::Mat img_original, img_green;

    //이미지파일을 로드하여 image에 저장
    img_original = cv::imread(mouseInterface::path, cv::IMREAD_COLOR);
    if (img_original.empty())
    {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }
    
    //스케일 이미지로 변환
    cv::cvtColor(img_original, img_green, cv::COLOR_BGR2RGBA);
 
   //윈도우 생성
    cv::namedWindow("original image", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("green image", cv::WINDOW_AUTOSIZE);

    //윈도우에 출력
    cv::imshow("original image", img_original);
    cv::imshow("green image", img_green);



    //윈도우에 콜백함수를 등록
    cv::setMouseCallback("green image", mouseInterface::mouse_CallBackFunc, NULL);

    //키보드 입력이 될때까지 대기
    cv::waitKey(0);
}

int main(int argc, char **argv)
{
    mouseInterface mouse = mouseInterface();

    return 0;
}
