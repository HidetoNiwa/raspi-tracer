#include "main.h"

//motorクラスの定義
motor w[4]{
    motor(0),
    motor(1),
    motor(2),
    motor(3)
};

void vector(int x,int y ,int theta);

int main(int argh, char* argv[])
{
    cv::VideoCapture cap(0);//デバイスのオープン
    if(!cap.isOpened())//カメラデバイスが正常にオープンしたか確認．
    {
        //読み込みに失敗したときの処理
        return -1;
    }
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);

    //motor初期状態定義
    vector(0,0,0);

    cv::Mat frame; //取得したフレーム
    uint16_t def_y=480/(PLOTS+1);
    while(cap.read(frame))//無限ループ
    {
        cv::cvtColor(frame, frame,cv::COLOR_RGB2GRAY);
        cv::threshold(frame, frame, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

        uint16_t y=def_y;
        uint16_t l[PLOTS]={0};
        uint16_t r[PLOTS]={0};
        uint16_t centor[PLOTS]={0};

        for(uint8_t i=0;i<PLOTS;i++){
            for(uint16_t x=0;x<640;x++){
                if(255 == frame.at<unsigned char>(y, x)){
                    l[i]=x;
                    break;
                }
            }
            for(uint16_t x=l[0];x<640;x++){
                if(0 == frame.at<unsigned char>(y, x)){
                    r[i]=x;
                    break;
                }
            }
            if(r[i]==0){
                r[i]=640;
            }
            y=y+def_y;
            centor[i]=(l[i]+r[i])/2;
            printf("%d,%d\t",y,centor[i]);
        }

        printf("\n");

        vector(0,0,1000);

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

void vector(int x,int y ,int theta){
    int vector[4]={0};
    vector[0]=-x+y+theta;
    vector[1]=x+y-theta;
    vector[2]=-x+y-theta;
    vector[3]=x+y+theta;

    uint16_t max=MAX_POWER;

    for(int8_t i=0;i<4;i++){
        if(abs(vector[i])>max){
            max=vector[i];
        }
    }

    //printf("MAX:%d\t",max);
    for(uint8_t i=0;i<4;i++){
        if(max>MAX_POWER){
            vector[i]=vector[i]*MAX_POWER/max;
        }
        w[i].setPower(int8_t(vector[i]));
        //printf("i%d:%d\t",i,vector[i]);
    }
    //printf("\n");

}