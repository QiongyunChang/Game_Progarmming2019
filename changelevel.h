void word_level ();
void word_numberOne();
void word_numberTwo();
void word_numberThree();
void word_numberFour();
void word_numberFive();

//main function, use it by change_level(n);
void change_level(int n){
	system("cls");
	my_print();
	switch(n){
		case 1:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�©��G��r;;
			word_numberOne();
			break;
		case 2:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);//�©��G���r;;
			word_numberTwo();
			break;
		case 3:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY);//�©��L�Ŧr;
			word_numberThree();
			break;
		case 4:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED |FOREGROUND_INTENSITY);//�©����r;
			word_numberFour();
			break;
		case 5:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);//�©��Ŧr;
			word_numberFive();
			break;
	}
	word_level ();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�©��G���r�C
	sleep(3);
}

void word_level (){	
    	gotoxy(5, 9);
    	printf("��   ������ ��  �� ������ ��\n");
    	gotoxy(5, 10);
    	printf("��   ��     ��  �� ��     ��\n");
    	gotoxy(5, 11);
    	printf("��   ��     ��  �� ��     ��\n");
    	gotoxy(5, 12);
    	printf("��   ������ ��  �� ������ ��\n");
    	gotoxy(5, 13);
    	printf("��   ��     ��  �� ��     ��\n");
    	gotoxy(5, 14);
    	printf("��   ��     ��  �� ��     ��\n");
    	gotoxy(5, 15);  
    	printf("���� ������   ��   ������ ��\n");
}
void word_numberOne(){
	gotoxy(19, 18);
	printf("��\n");
	gotoxy(17, 19);
	printf("����\n");
	gotoxy(19, 20);
	printf("��\n");
	gotoxy(19, 21);
	printf("��\n");
	gotoxy(19, 22);
	printf("��\n");
	gotoxy(17, 23);
	printf("������\n");
}
void word_numberTwo(){
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);//�©��G���r;;
	gotoxy(17, 18);
	printf("������\n");
	gotoxy(21, 19);
	printf("��\n");
	gotoxy(21, 20);
	printf("��\n");
	gotoxy(17, 21);
	printf("������\n");
	gotoxy(17, 22);
	printf("��\n");
	gotoxy(17, 23);
	printf("��\n");
	gotoxy(17, 24);
	printf("������\n");
}
void word_numberThree(){
	gotoxy(17, 18);
	printf("������\n");
	gotoxy(21, 19);
	printf("��\n");
	gotoxy(21, 20);
	printf("��\n");
	gotoxy(17, 21);
	printf("������\n");
	gotoxy(21, 22);
	printf("��\n");
	gotoxy(21, 23);
	printf("��\n");	
	gotoxy(17, 24);
	printf("������\n");
}
void word_numberFour(){
	gotoxy(19, 18);
	printf("��\n");
	gotoxy(17, 19);
	printf("����\n");
	gotoxy(15, 20);
	printf("��  ��\n");
	gotoxy(15, 21);
	printf("��������\n");
	gotoxy(19, 22);
	printf("��\n");
	gotoxy(19, 23);
	printf("��\n");
}
void word_numberFive(){
	gotoxy(17, 18);
	printf("������\n");
	gotoxy(17, 19);
	printf("��\n");
	gotoxy(17, 20);
	printf("��\n");
	gotoxy(17, 21);
	printf("������\n");
	gotoxy(21, 22);
	printf("��\n");
	gotoxy(21, 23);
	printf("��\n");
	gotoxy(17, 24);
	printf("������\n"); 
}
