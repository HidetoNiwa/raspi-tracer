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
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);

    //motor初期状態定義
    vectors(0,0,0);

    cv::Mat frame; //取得したフレーム
    uint16_t def_y=480/(PLOTS+1);
    while(cap.read(frame))//無限ループ
    {

        linearApprox lin;
	GaussianBlur(frame,frame,Size(3,3),0);
        cvtColor(frame, frame,cv::COLOR_RGB2GRAY);
        //adaptiveThreshold(frame,frame, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 7, 8);
	threshold(frame, frame, 0, 255, THRESH_BINARY | THRESH_OTSU);
	/*
	int threshold_type = atoi(argv[2]) ?THRESH_BINARY : THRESH_BINARY_INV;
	int adaptive_method = atoi(argv[3]) ?ADAPTIVE_THRESH_MEAN_C : ADAPTIVE_THRESH_GAUSSIAN_C;
	int block_size =atoi (argv[4]);
	double offset = (double)atof(argv[5]);
	adaptiveThreshold(frame, frame, 255, adaptive_method,threshold_type, block_size, offset);
	*/
	uint16_t y=def_y;
        uint16_t l[PLOTS]={640};
        uint16_t r[PLOTS]={640};
        uint16_t centor[PLOTS]={0};

        for(uint8_t i=0;i<PLOTS;i++){
	    for(uint16_t x=0;x<640;x++){
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
            for(uint16_t x=639;x>l[i]+50;x--){
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
	    if((l[i]<630)&&(r[i]>10)){
            	lin.add(y,centor[i]);
		circle(frame, Point(centor[i],y), 20, Scalar(200,200,200), 1, 8);
	    }
            //printf("%d,%d\t",y,centor[i]);
        }
	float b=lin.getB();
	float a=lin.getA();
        printf("y=%fx+%f\t%d\n",a,b,lin.getN());
	float dify=lin.getB()-CENTOR_B;
	float outY=dify*P_Y;
	float outTHETA=a*a*P_THETA;
	if(outTHETA>14){
		outTHETA=14;
	}
	float outX;
	if((outY>2)||(outTHETA>2)){
		outX=2;
	}else{
		outX=8;
	}
        //vector(7,(int)outY*1.5,(int)outTHETA+outY);
	vectors(outX,(int)outY,(int)(outTHETA));
	cv::line(frame, cv::Point(b,0), cv::Point(480*a+b, 480), cv::Scalar(0,0,0), 3, 4);
	cv::imshow("Lune",frame);
/*
	for(uint8_t i=0;i<4;i++){
		w[i].setPower(-50);
        printf("%d\n",-i);
        delay(1000);
        w[i].setPower(50);
        printf("%d\n",i);
        delay(1000);
        w[i].setPower(0);
	}
*/
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

    printf("MAX:%d\t",max);
    for(uint8_t i=0;i<4;i++){
        if(max>MAX_POWER){
            vector[i]=vector[i]*MAX_POWER/max;
        }
        w[i].setPower(int8_t(vector[i]));
        printf("i%d:%d\t",i,vector[i]);
    }
    printf("\n");

}

