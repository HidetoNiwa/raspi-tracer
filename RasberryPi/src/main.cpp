#include "includes.h"
#include "foot.h"
#include "motor.h"
#include "main.h"

foot foots();

int main()
{
    cv::VideoCapture cap(0); //デバイスのオープン

    if (!cap.isOpened()) //カメラデバイスが正常にオープンしたか確認．
    {
        //読み込みに失敗したときの処理
        return -1;
    }

    cv::Mat frame;
    while (1)
    {
        cv::imshow("Picture", frame);
        foots.out(1, 1, 0);
    }

    return 0;
}