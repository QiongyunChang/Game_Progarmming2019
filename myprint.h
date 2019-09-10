void my_print()//設置介面 
{

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
