void my_print()//�]�m���� 
{

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
