#include "main.h"

int main()
{
    foot foots; //足回り動作定義

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
        foots.out(1.f, 1.f, 0.f);
    }

    return 0;
}