#include<stdio.h>
#include<stdlib.h>
#include <windows.h>//windows 
#include<conio.h>//��r�C�� 
#include<time.h>//random 
#include<stdbool.h>//��L 
#include"bonus.h"//bonus game 
#include"changelevel.h"
#include"_rule.h" 
//////////////////////////////////////////44~48�� ��U���ƾ� 
struct data
{
	int x;//�ĴX��
	int t;//���d�X��
	int goal;//�ؼФ��� 
	int speed;//����t��,Sleep�����,�V�ּƦr�V�p 
};
void gotoxy(int x, int y);//������СCX��ܾ�СAY����a����	 
void console();//�]�m����x���f�j�p�A���F���{�ǹB��o��n��      
void my_print();//�]�m����										 
void run(struct data);
void print_map();
void down(int a,int b,int c);
void left();
void right();
void up();//�[�t 
void pause();
void gameover();//gg

unsigned long long int counter;//count time
char key;//Ū��L 
int i,j,point=0,heart=0,Time=0,Speed=0;
int map[18][30]={0};//1����ê 2������  3���P�P�[��  4���[�R 5��bonus�p�C�� 6���ä[�[�t 7���[���(3s) 
HANDLE hout;
clock_t t1, t2,t3,t4;//t1=��l,t2=current,t4-t3�����i�C���`�ɪ� 
int main()
{
	hout = GetStdHandle(STD_OUTPUT_HANDLE);// ����зǿ�X�]�ƥy�`
	CONSOLE_CURSOR_INFO c;//����x���Ъ��Ҧ�
	GetConsoleCursorInfo(hout, &c);
	c.bVisible = 0;// �O�_�i�[(���å���)
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
	srand(time(NULL));//�]�m�H���ƺؤl
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
//�]�m���f��m�M�j�p�A���F���{�ǹB��o��n��
void console(){

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// ����зǿ�X�]�ƥy�`

    CONSOLE_SCREEN_BUFFER_INFO bInfo; // ���f�w�İϫH��

    GetConsoleScreenBufferInfo(hOut, &bInfo);// ������f�w�İϫH��

    SetConsoleTitle("�����C��"); // �]�m���f�����D

    COORD size = { 80, 32 };//����p���q�{�j�p�]80�A25�^

    SetConsoleScreenBufferSize(hOut, size); // ���s�]�m�w�İϤj�p*/

    SMALL_RECT rc = { 0,0, 70, 31 }; //����j��w�İϤj�p

    SetConsoleWindowInfo(hOut, true, &rc);// ���m���f�j�p

}

void my_print(){

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);//�©��G�Ŧr�C
    for (i = 1; i <= 30; i++)

    printf("��\t\t\t\t      �� | |\n");
    printf("���������������������������������������� |---------------------------|\n");//�ج[

    gotoxy(45, 0);
    printf("---------------------------");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�©��G���r�C
    
    gotoxy(45, 2);
    printf("�� �R:%6d",heart);
	gotoxy(45, 3);
    printf("�� ��:%6d",point);
    //gotoxy(45, 4);
    //printf("�ɶ� :%6d",t3-(t2-t1)/(CLOCKS_PER_SEC));
    gotoxy(45, 6);
    printf("�ާ@��k�G");
    gotoxy(45, 9);
    printf("���G�[�t ");
    gotoxy(45, 12);
    printf("���G�k�� ���G����");
    gotoxy(45, 15);
    printf("�Ů���G�}�l / �Ȱ�");
    gotoxy(45, 18);
    printf("Esc�G�h�X");
    gotoxy(57, 26);
    printf("�� ��G");
    gotoxy(50, 28);
    printf("2019�~5��30��");  
}
//X��ܾ�СAY����a���СC
void gotoxy(int x, int y){
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hout, pos);
}

void run(struct data y){
	memset(map,0,sizeof(map));//��l�}�C
	map[9][29]=2;//�]������m 
	t1 = clock();//��l�ɶ�
	Time=y.t;//�L���ɶ�
	Speed=y.speed;//����t�� 
	//���`��
	while(1){	
		counter++;	
		//�ɶ��˼� 
		t2 = clock();
		gotoxy(45, 4);
    	printf("�� ��:%6d",Time-(t2-t1)/(CLOCKS_PER_SEC));
    	
    	if(Time-(t2-t1)/(CLOCKS_PER_SEC)<=0){
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);//�©��G���r;;
	    	gotoxy(45, 21);
	    	printf("Time up.");
	    	gotoxy(45, 22);
	    	system("pause");
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�©��G���r�C
			gameover();//�ɶ��� 
    	}
    	if(counter%Speed==0){ //����ɶ� 
			int a=rand()*rand()%17;//0~16 ��m 
			int b=rand()*rand()%17;//0~16 ��m 
			int c;
			//int c=(rand()*rand()%4)+3;//�M�w�D�����  3~6 
			if(rand()%33==0)//�[�R 
				c=4;
			else if(rand()%29==0)//���N�� 
				c=5;
			else if(rand()%23==0)//�[�ɶ� 
				c=7;
			else if(rand()%7==0)//�[�t 
				c=6;
			else if(rand()%3==0)//�P�P 
				c=3;
			else c=0;//��ê 
			
			down(a,b,c);
			//a=rand()*rand()%17;//0~16
			
			print_map();
			Sleep(10);
		}
		
		if(counter%Speed==0){
			point+=20;
			gotoxy(45, 3);
    		printf("�� ��:%6d",point);
		}
		
	    if (_kbhit()){
	        key = _getch();//�������
	        switch (key){
	            case 32:pause();break;//�Ů� �Ȱ��ζ}�l
	            case 72:up();break;//�W�� 
				case 75:left();break;//���� 
				case 77:right();break;//�k�� 
	            case 27:system("cls");printf("goodbye!!");exit(0);//Esc �h�X
	            default:;
	        }						
	    }
	    if(point>=y.goal){
	    	gotoxy(45, 3);
    		printf("�� ��:%6d",point);
	    	point+=(Time-(t2-t1)/(CLOCKS_PER_SEC))*100;
	    	sleep(2);
	    	gotoxy(45, 21);
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);//�©��G���r;
	    	printf("���߶i�J�U�@��\n");
	    	gotoxy(45, 22);
	    	printf("��o�[��:%d\n",(Time-(t2-t1)/(CLOCKS_PER_SEC))*100);  	
	    	gotoxy(45, 23);
			system("pause");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�©��G���r�C
	    	break;
		}
		
	}
}
void print_map(){
	//wchar_t c=FCA000
	for(i=0;i<=29;i++){//y�b
		for(j=0;j<18;j++){//x�b 
			gotoxy(j*2+2,i);
			if(map[j][i]==1)
				printf("��");
			else if(map[j][i]==2)
				printf("/\\");
			else if(map[j][i]==3)
				printf("��");
			else if(map[j][i]==4)
				printf("��");
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
	for(i=29;i>0;i--){//y�b
		for(j= 0;j<18;j++){//x�b 
			if(map[j][i-1]==1&&map[j][i]==2){//�̫�@��B�J�W��ê 
				heart-=1;
				gotoxy(45, 2);
    			printf("�� �R:%6d",heart);	
			}
			if(heart==0) gameover();//�S�R���h 
			
			if(map[j][i-1]==3&&map[j][i]==2){//�̫�@��B�J�W�P�P 
				point+=800;
			} 
			if(map[j][i-1]==4&&map[j][i]==2){//�̫�@��B�J�W�[�R 
				heart+=1;
				gotoxy(45, 2);
    			printf("�� �R:%6d",heart);
			}
			if(map[j][i-1]==5&&map[j][i]==2){//�̫�@��B�J�W���N�� 
				system("cls");
				t3=clock();
				point+=bonus();
				map[j][i-1]=0;
				system("cls");
				my_print();
				print_map();				
				gotoxy(45, 21);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);//�©��G���r;;
				system("pause");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�©��G���r�C
				system("cls");
				my_print();
				print_map();
				t4=clock();
				Time+=(t4-t3)/(CLOCKS_PER_SEC);
			}
			if(map[j][i-1]==6&&map[j][i]==2){//�̫�@��B�J�W�[�t�t���D�� 
				Speed/=2; 
			} 
			if(map[j][i-1]==7&&map[j][i]==2){//�̫�@��B�J�W�[�ɹD�� 
				Time+=4; 
			} 
			if(map[j][i]!=2)
				map[j][i]=map[j][i-1];
		}
	} 
	for(j=0;j<18;j++){map[j][0]=0;}//�Ĥ@���k�s 
	
	map[b][0]=c;//�D�� 
	map[a][0]=1;//�]�m��ê 
	map[a+1][0]=1;
	
}

void left(){
	for(j=1;j<18;j++){//�̫�@��䭸�� //�̥����੹�� 
		if(map[j][29]==2&&map[j-1][29]!=1){//���䤣����ê�� 
			if(map[j-1][29]==3)//�P�P
				point+=800;
			if(map[j-1][29]==4){//�[�R
				heart+=1;
				gotoxy(45, 2);
    			printf("�� �R:%6d",heart);
			}
			if(map[j-1][29]==5){//�J�W���N�� 
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
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);//�©��G���r;;
				system("pause");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�©��G���r�C
				system("cls");
				my_print();
				print_map();
				t4=clock();
				Time+=(t4-t3)/(CLOCKS_PER_SEC);
				break;
			}
			if(map[j-1][29]==6){//�[�t 
				Speed/=2;
			}
			if(map[j-1][29]==7){//�[�� 
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
	for(j=0;j<17;j++){//�̫�@��䭸�� //�̥k���੹�k 
		if(map[j][29]==2&&map[j+1][29]!=1){//�k�䤣����ê�� 
			if(map[j+1][29]==3)//�P�P 
				point+=800;
			if(map[j+1][29]==4){//�[�R 
				heart+=1;
				gotoxy(45, 2);
    			printf("�� �R:%6d",heart);
			}	
			if(map[j+1][29]==5){//�J�W���N�� 
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
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);//�©��G���r;;
				system("pause");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�©��G���r�C	
				system("cls");
				my_print();
				print_map();
				t4=clock();
				Time+=(t4-t3)/(CLOCKS_PER_SEC);
				break;
			}	
			if(map[j+1][29]==6){//�[�t 
				Speed/=2;
			}	
			if(map[j+1][29]==7){//�[�� 
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
    printf("�� ��:%6d",point);
	int a=rand()*rand()%17;//0~16
	int b=rand()*rand()%17;//0~16
	//int c=rand()*rand()%4+3;//3~6�M�w�D����� 
	int c;
	if(rand()%33==0)
		c=4;
	else if(rand()%29==0)
		c=5;
	else if(rand()%23==0)//�[�ɶ� 
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);//�©��G���r;
	gotoxy(10,10);
	system("pause");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�©��G���r�C
	t4=clock();	
	Time+=(t4-t3)/(CLOCKS_PER_SEC);
}
void gameover(){
	system("cls");
	printf("gameover!!You got %d points.\n",point);
	
	FILE *fPtr;   /*�ŧiFILE��ƫ��A�� ����*/ 
    fPtr = fopen("score.txt","a+");  /* fopen function , �����ɮצW�١A�M�g�J�覡 */
  	fprintf(fPtr,"%d\n",point);   /* �N�r��g�J�ɮ� */
   	fclose(fPtr); /* �����ɮ� */ 
   	
	sleep(2);
	system("pause");
	system("cls");
	main();
}
