#include<stdio.h>
#include<stdlib.h>
#include <windows.h>//windows 
#include<conio.h>//文字顏色 
#include<time.h>//random 
#include<stdbool.h>//鍵盤 
#include"bonus.h"//bonus game 
#include"changelevel.h"
#include"_rule.h" 
//////////////////////////////////////////44~48行 改各關數據 
struct data
{
	int x;//第幾關
	int t;//關卡幾秒
	int goal;//目標分數 
	int speed;//控制速度,Sleep的秒數,越快數字越小 
};
void gotoxy(int x, int y);//控制光標。X表示橫坐標，Y表示縱坐標	 
void console();//設置控制台窗口大小，為了讓程序運行得更好看      
void my_print();//設置介面										 
void run(struct data);
void print_map();
void down(int a,int b,int c);
void left();
void right();
void up();//加速 
void pause();
void gameover();//gg

unsigned long long int counter;//count time
char key;//讀鍵盤 
int i,j,point=0,heart=0,Time=0,Speed=0;
int map[18][30]={0};//1為障礙 2為飛機  3為星星加分  4為加命 5為bonus小遊戲 6為永久加速 7為加秒數(3s) 
HANDLE hout;
clock_t t1, t2,t3,t4;//t1=初始,t2=current,t4-t3紀錄進遊戲總時長 
int main()
{
	hout = GetStdHandle(STD_OUTPUT_HANDLE);// 獲取標準輸出設備句柄
	CONSOLE_CURSOR_INFO c;//控制台光標的模式
	GetConsoleCursorInfo(hout, &c);
	c.bVisible = 0;// 是否可觀(隱藏光標)
	SetConsoleCursorInfo(hout, &c);
	
	struct data lv1,lv2,lv3,lv4,lv5;
	lv1.x=1;lv1.t=30;lv1.goal=8000;lv1.speed=5000;
	lv2.x=2;lv2.t=30;lv2.goal=17000;lv2.speed=3000;
	lv3.x=3;lv3.t=30;lv3.goal=24000;lv3.speed=1500;
	lv4.x=4;lv4.t=30;lv4.goal=30000;lv4.speed=800;
	lv5.x=5;lv5.t=30;lv5.goal=100000;lv5.speed=500;
	
	rule();
	fflush(stdin);
	counter=0;
	point=0;
	heart=1;
	srand(time(NULL));//設置隨機數種子
	console();
	
	change_level(1);
	run(lv1);
	change_level(2);
	run(lv2);
	change_level(3);
	run(lv3);
	change_level(4);
	run(lv4);
	change_level(5);
	run(lv5);
    system("pause");
    return 0;
}
//設置窗口位置和大小，為了讓程序運行得更好看
void console(){

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 獲取標準輸出設備句柄

    CONSOLE_SCREEN_BUFFER_INFO bInfo; // 窗口緩衝區信息

    GetConsoleScreenBufferInfo(hOut, &bInfo);// 獲取窗口緩衝區信息

    SetConsoleTitle("飛機遊戲"); // 設置窗口的標題

    COORD size = { 80, 32 };//不能小於默認大小（80，25）

    SetConsoleScreenBufferSize(hOut, size); // 重新設置緩衝區大小*/

    SMALL_RECT rc = { 0,0, 70, 31 }; //不能大於緩衝區大小

    SetConsoleWindowInfo(hOut, true, &rc);// 重置窗口大小

}

void my_print(){

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);//黑底亮藍字。
    for (i = 1; i <= 30; i++)

    printf("■\t\t\t\t      ■ | |\n");
    printf("■■■■■■■■■■■■■■■■■■■■ |---------------------------|\n");//框架

    gotoxy(45, 0);
    printf("---------------------------");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);//黑底亮黃字。
    
    gotoxy(45, 2);
    printf("生 命:%6d",heart);
	gotoxy(45, 3);
    printf("分 數:%6d",point);
    //gotoxy(45, 4);
    //printf("時間 :%6d",t3-(t2-t1)/(CLOCKS_PER_SEC));
    gotoxy(45, 6);
    printf("操作方法：");
    gotoxy(45, 9);
    printf("↑：加速 ");
    gotoxy(45, 12);
    printf("→：右移 ←：左移");
    gotoxy(45, 15);
    printf("空格鍵：開始 / 暫停");
    gotoxy(45, 18);
    printf("Esc：退出");
    gotoxy(57, 26);
    printf("關 於：");
    gotoxy(50, 28);
    printf("2019年5月30日");  
}
//X表示橫坐標，Y表示縱坐標。
void gotoxy(int x, int y){
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hout, pos);
}

void run(struct data y){
	memset(map,0,sizeof(map));//初始陣列
	map[9][29]=2;//設飛機位置 
	t1 = clock();//初始時間
	Time=y.t;//過關時間
	Speed=y.speed;//控制速度 
	//死循環
	while(1){	
		counter++;	
		//時間倒數 
		t2 = clock();
		gotoxy(45, 4);
    	printf("時 間:%6d",Time-(t2-t1)/(CLOCKS_PER_SEC));
    	
    	if(Time-(t2-t1)/(CLOCKS_PER_SEC)<=0){
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);//黑底亮紅字;;
	    	gotoxy(45, 21);
	    	printf("Time up.");
	    	gotoxy(45, 22);
	    	system("pause");
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);//黑底亮黃字。
			gameover();//時間到 
    	}
    	if(counter%Speed==0){ //控制時間 
			int a=rand()*rand()%17;//0~16 位置 
			int b=rand()*rand()%17;//0~16 位置 
			int c;
			//int c=(rand()*rand()%4)+3;//決定道具種類  3~6 
			if(rand()%33==0)//加命 
				c=4;
			else if(rand()%29==0)//任意門 
				c=5;
			else if(rand()%23==0)//加時間 
				c=7;
			else if(rand()%7==0)//加速 
				c=6;
			else if(rand()%3==0)//星星 
				c=3;
			else c=0;//障礙 
			
			down(a,b,c);
			//a=rand()*rand()%17;//0~16
			
			print_map();
			Sleep(10);
		}
		
		if(counter%Speed==0){
			point+=20;
			gotoxy(45, 3);
    		printf("分 數:%6d",point);
		}
		
	    if (_kbhit()){
	        key = _getch();//捕獲按鍵
	        switch (key){
	            case 32:pause();break;//空格 暫停或開始
	            case 72:up();break;//上鍵 
				case 75:left();break;//左鍵 
				case 77:right();break;//右鍵 
	            case 27:system("cls");printf("goodbye!!");exit(0);//Esc 退出
	            default:;
	        }						
	    }
	    if(point>=y.goal){
	    	gotoxy(45, 3);
    		printf("分 數:%6d",point);
	    	point+=(Time-(t2-t1)/(CLOCKS_PER_SEC))*100;
	    	sleep(2);
	    	gotoxy(45, 21);
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);//黑底亮紅字;
	    	printf("恭喜進入下一關\n");
	    	gotoxy(45, 22);
	    	printf("獲得加分:%d\n",(Time-(t2-t1)/(CLOCKS_PER_SEC))*100);  	
	    	gotoxy(45, 23);
			system("pause");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);//黑底亮黃字。
	    	break;
		}
		
	}
}
void print_map(){
	//wchar_t c=FCA000
	for(i=0;i<=29;i++){//y軸
		for(j=0;j<18;j++){//x軸 
			gotoxy(j*2+2,i);
			if(map[j][i]==1)
				printf("■");
			else if(map[j][i]==2)
				printf("/\\");
			else if(map[j][i]==3)
				printf("★");
			else if(map[j][i]==4)
				printf("⊕");
			else if(map[j][i]==5)
				printf("?!");
			else if(map[j][i]==6)
				printf("X");	
			else if(map[j][i]==7)
				printf("+T");
			else printf("  ");
		}
	} 
}

void down(int a,int b,int c){
	for(i=29;i>0;i--){//y軸
		for(j= 0;j<18;j++){//x軸 
			if(map[j][i-1]==1&&map[j][i]==2){//最後一行且遇上障礙 
				heart-=1;
				gotoxy(45, 2);
    			printf("生 命:%6d",heart);	
			}
			if(heart==0) gameover();//沒命死去 
			
			if(map[j][i-1]==3&&map[j][i]==2){//最後一行且遇上星星 
				point+=800;
			} 
			if(map[j][i-1]==4&&map[j][i]==2){//最後一行且遇上加命 
				heart+=1;
				gotoxy(45, 2);
    			printf("生 命:%6d",heart);
			}
			if(map[j][i-1]==5&&map[j][i]==2){//最後一行且遇上任意門 
				system("cls");
				t3=clock();
				point+=bonus();
				map[j][i-1]=0;
				system("cls");
				my_print();
				print_map();				
				gotoxy(45, 21);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);//黑底亮紅字;;
				system("pause");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);//黑底亮黃字。
				system("cls");
				my_print();
				print_map();
				t4=clock();
				Time+=(t4-t3)/(CLOCKS_PER_SEC);
			}
			if(map[j][i-1]==6&&map[j][i]==2){//最後一行且遇上加速負面道具 
				Speed/=2; 
			} 
			if(map[j][i-1]==7&&map[j][i]==2){//最後一行且遇上加時道具 
				Time+=4; 
			} 
			if(map[j][i]!=2)
				map[j][i]=map[j][i-1];
		}
	} 
	for(j=0;j<18;j++){map[j][0]=0;}//第一行歸零 
	
	map[b][0]=c;//道具 
	map[a][0]=1;//設置障礙 
	map[a+1][0]=1;
	
}

void left(){
	for(j=1;j<18;j++){//最後一行找飛機 //最左不能往左 
		if(map[j][29]==2&&map[j-1][29]!=1){//左邊不為障礙物 
			if(map[j-1][29]==3)//星星
				point+=800;
			if(map[j-1][29]==4){//加命
				heart+=1;
				gotoxy(45, 2);
    			printf("生 命:%6d",heart);
			}
			if(map[j-1][29]==5){//遇上任意門 
				t3=clock();
				map[j-1][29]=2;
				map[j][29]=0;
				system("cls");
				point+=bonus();
				map[j][i-1]=0;
				system("cls");
				my_print();
				print_map();
				gotoxy(45, 21);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);//黑底亮紅字;;
				system("pause");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);//黑底亮黃字。
				system("cls");
				my_print();
				print_map();
				t4=clock();
				Time+=(t4-t3)/(CLOCKS_PER_SEC);
				break;
			}
			if(map[j-1][29]==6){//加速 
				Speed/=2;
			}
			if(map[j-1][29]==7){//加時 
				Time+=4;
			}
			map[j-1][29]=2;
			map[j][29]=0;
			print_map(); 
			break;
		}
	}
}
void right(){
	for(j=0;j<17;j++){//最後一行找飛機 //最右不能往右 
		if(map[j][29]==2&&map[j+1][29]!=1){//右邊不為障礙物 
			if(map[j+1][29]==3)//星星 
				point+=800;
			if(map[j+1][29]==4){//加命 
				heart+=1;
				gotoxy(45, 2);
    			printf("生 命:%6d",heart);
			}	
			if(map[j+1][29]==5){//遇上任意門 
				t3=clock();
				map[j+1][29]=2;
				map[j][29]=0;
				system("cls");
				point+=bonus();
				map[j][i-1]=0;
				system("cls");
				my_print();
				print_map();
				gotoxy(45, 21);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);//黑底亮紅字;;
				system("pause");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);//黑底亮黃字。	
				system("cls");
				my_print();
				print_map();
				t4=clock();
				Time+=(t4-t3)/(CLOCKS_PER_SEC);
				break;
			}	
			if(map[j+1][29]==6){//加速 
				Speed/=2;
			}	
			if(map[j+1][29]==7){//加時 
				Time+=4;
			}		
			map[j+1][29]=2;
			map[j][29]=0;
			print_map();
			break;
		}
	}
}
void up(){
	point+=30;
	gotoxy(45, 3);
    printf("分 數:%6d",point);
	int a=rand()*rand()%17;//0~16
	int b=rand()*rand()%17;//0~16
	//int c=rand()*rand()%4+3;//3~6決定道具種類 
	int c;
	if(rand()%33==0)
		c=4;
	else if(rand()%29==0)
		c=5;
	else if(rand()%23==0)//加時間 
		c=7;
	else if(rand()%11==0)
		c=6;
	else if(rand()%3==0)
		c=3;
	else c=0;
	down(a,b,c);
	print_map();
} 
void pause(){
	t3=clock();
	system("cls");
	my_print();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);//黑底亮紅字;
	gotoxy(10,10);
	system("pause");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);//黑底亮黃字。
	t4=clock();	
	Time+=(t4-t3)/(CLOCKS_PER_SEC);
}
void gameover(){
	system("cls");
	printf("gameover!!You got %d points.\n",point);
	
	FILE *fPtr;   /*宣告FILE資料型態的 指標*/ 
    fPtr = fopen("score.txt","a+");  /* fopen function , 給予檔案名稱，和寫入方式 */
  	fprintf(fPtr,"%d\n",point);   /* 將字串寫入檔案 */
   	fclose(fPtr); /* 關閉檔案 */ 
   	
	sleep(2);
	system("pause");
	system("cls");
	main();
}
