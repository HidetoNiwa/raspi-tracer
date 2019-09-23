#include "main.h"

int main(int argh, char* argv[])
{
    cv::VideoCapture cap(0);//デバイスのオープン
    if(!cap.isOpened())//カメラデバイスが正常にオープンしたか確認．
    {
        //読み込みに失敗したときの処理
        return -1;
    }

    cv::Mat frame; //取得したフレーム
    int flag=0;
    while(cap.read(frame))//無限ループ
    {
        cv::cvtColor(frame, frame,cv::COLOR_RGB2GRAY);
        cv::threshold(frame, frame, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

        cv::imshow("win", frame);//画像を表示．
        const int key = cv::waitKey(1);
        if(key == 'q'/*113*/)//qボタンが押されたとき
        {
            break;//whileループから抜ける．
        }
        else if(key == 's'/*115*/)//sが押されたとき
        {
            //フレーム画像を保存する．
            cv::imwrite("img.png", frame);
        }
    }
    cv::destroyAllWindows();
    return 0;
}