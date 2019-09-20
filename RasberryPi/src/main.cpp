#include <stdio.h>
#include <opencv2/opencv.hpp>
int main(){
    cv::VideoCapture cap(0);//デバイスのオープン
    //cap.open(0);//こっちでも良い．

    if(!cap.isOpened())//カメラデバイスが正常にオープンしたか確認．
    {
        //読み込みに失敗したときの処理
        return -1;
    }

    cv::Mat frame;

    while(1){
        cv::imshow("Picture",frame);
    }

    return 0;
}