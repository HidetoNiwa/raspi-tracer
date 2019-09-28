#include "main.h"
using namespace cv;
using namespace std;

//motorクラスの定義
motor w[4]{
    motor(0),
    motor(1),
    motor(2),
    motor(3)
};

void vectors(int x,int y ,int theta);

int main(int argh, char* argv[])
{
    cv::VideoCapture cap(0);//デバイスのオープン
    if(!cap.isOpened())//カメラデバイスが正常にオープンしたか確認．
    {
        //読み込みに失敗したときの処理
        return -1;
    }
    cap.set(cv::CAP_PROP_FRAME_WIDTH, WIDTH_);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, HIGH_);

    //motor初期状態定義
    vectors(0,0,0);
    float bef_a=0;
    cv::Mat frame; //取得したフレーム
    uint16_t def_y=HIGH_/(PLOTS+1);
    while(cap.read(frame))//無限ループ
    {

        linearApprox lin;
	GaussianBlur(frame,frame,Size(3,3),0);
        cvtColor(frame, frame,cv::COLOR_RGB2GRAY);
       	threshold(frame, frame, 0, 255, THRESH_BINARY | THRESH_OTSU);

	uint16_t y=def_y;
        uint16_t l[PLOTS]={WIDTH_};
        uint16_t r[PLOTS]={WIDTH_};
        uint16_t centor[PLOTS]={0};

        for(uint8_t i=0;i<PLOTS;i++){
	    for(uint16_t x=0;x<WIDTH_ ;x++){
                if(0 != frame.at<unsigned char>(y, x)){
                    uint8_t count=0;
		    for(uint8_t j=0;j<21;j++){
		    	if(0 != frame.at<unsigned char>(y, x+j)){
				count++;
			}
		    }
		    if(count>20){
		    	l[i]=x;
		    }
                    break;
            	}
            }
            for(uint16_t x=WIDTH_-1;x>l[i]+50;x--){
                if(0 != frame.at<unsigned char>(y, x)){
                    uint8_t count=0;
                    for(uint8_t j=0;j<21;j++){
                        if(0 != frame.at<unsigned char>(y, x-j)){
                                count++;
                        }
                    }
                    if(count>20){
                        r[i]=x;
                    }
                    break;
                }
            }
            y=y+def_y;
            centor[i]=(l[i]+r[i])/2;
	    if((l[i]<(int)(WIDTH_*0.98f))&&(r[i]>10)){
            	lin.add(y,centor[i]);
		circle(frame, Point(centor[i],y), 10, Scalar(200,200,200), 1, 8);
	    }
            //printf("%d,%d\t",y,centor[i]);
        }
	float b=lin.getB();
	float a=lin.getA();
        printf("y=%fx+%f\t%d\n",a,b,lin.getN());
	float dify=lin.getB()-CENTOR_B;
	float outY=dify*P_Y;
	float outTHETA=a*P_THETA+D_THETA*(a-bef_a)+dify*P_B;


	float max_f=9;
	if(outTHETA>max_f){
		outY=8;
		outTHETA=max_f;
	}else if(outTHETA<-max_f){
		outY=-8;
		outTHETA=-max_f;
	}
	float outX;

	float max_X=28;
	if(outTHETA<0){
		outTHETA=outTHETA*1;
	}
	if(abs(outTHETA)>4){
		outX=0;
		outY=outY*1.2;
	}else{
		outX=abs(max_X-abs(outTHETA)*10);
	}
	if(lin.getN()<10){
		outX=4;
		outY=0;
		outTHETA=1;
	}
	vectors(outX,(int)outY,(int)(outTHETA));

	bef_a=a;
	cv::line(frame, cv::Point(b,0), cv::Point(HIGH_*a+b, HIGH_), cv::Scalar(0,0,0), 3, 4);
	cv::imshow("Lune",frame);

        const int key = cv::waitKey(1);
        if(key == 'q'/*113*/)//qボタンが押されたとき
        {
	    vectors(0,0,0);
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

void vectors(int x,int y ,int theta){
    //theta=-theta;
    x=-x;
    printf("x:%d\ty:%d\tTHETA:%d\n",x,y,theta);
    int vector[4]={0};
    vector[0]=-x+y+theta;
    vector[1]=x+y-theta;
    vector[2]=-x+y-theta;
    vector[3]=x+y+theta;

    uint16_t max=MAX_POWER;

    for(int8_t i=0;i<4;i++){
        if(abs(vector[i])>max){
            max=abs(vector[i]);
        }
    }
   for(uint8_t i=0;i<4;i++){
        if(max>MAX_POWER){
            vector[i]=vector[i]*MAX_POWER/max;
        }
        w[i].setPower(int8_t(vector[i]));
        //printf("i%d:%d\t",i,vector[i]);
    }
}
