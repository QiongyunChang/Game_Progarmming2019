int respond();
//main function
int question(){//main function
	fflush(stdin);
	int fen = 0;
	printf("�O�D�D�A���T�е�\'Y\'�A���~�е�\'N\'�C\n\n");
	//Q1 
	printf("Emily Du�������O174����H\n"); 
	
	int ans;
	ans = respond();
	
	if(ans == 0){
		printf("�A����F�I\n\n");
		fen+=300;
	}
	else if(ans == 1){
		printf("�A�����F�I\n����=0.1�����A�o�S���O�ƤH><\n\n");
		fen-=100;
	}
	else{
		printf("�A�O�S�������H�H\n\n");
		fen-=200;
	}
	//Q2 
	printf("�L�s���`�`�ѥ[�����H\n");  //��
	
	ans = respond();
	
	if(ans == 0){
		printf("�A����F�I\n\n");
		fen+=300;
	}
	else if(ans == 1){
		printf("�A�����F�I\n�o�ܤְѥ[����A�i�O�u�n�ѥ[�N�|�����G�^\n\n");
		fen-=100;
	}
	else{
		printf("�A�O�S�������H�H\n\n");
		fen-=200;
	}
	//Q3
	printf("������ܩȧN�H\n");  //�� 
	
	ans = respond();
	
	if(ans == 0){
		printf("�A����F�I\n\n");
		fen+=300;
	}
	else if(ans == 1){
		printf("�A�����F�I\n�o���ٷ|�����H\n\n");
		fen-=100;
	}
	else{
		printf("�A�O�S�������H�H\n\n");
		fen-=200;
	} 
	//Q4
	printf("�d���̬O���O�ӭ��H\n");  //�� 
	
	ans = respond();
	
	if(ans == 0){
		printf("�A����F�I\n\n");
		fen+=600;
	}
	else if(ans == 1){
		printf("�A�����F�I\n�O�W�ŵL�Ĥj�ӭ��I\n\n");
		fen-=100;
	}
	else{
		printf("�A�O�S�������H�H\n\n");
		fen-=200;
	} 
	//���� 
	printf("\n������o%d��\n\n", fen);  //�ΥH�p����� 
	system("pause");
	fflush(stdin);
	return fen;
}

int respond(){
	
	char res;
	
	printf("�п�JY��N�G");
	scanf(" %c", &res);
	
	if(res == 'Y' || res =='y'){
		return 1;
	}
	else if(res == 'N' || res == 'n'){
		return 0;
	}
	else{
		return 2;
	}
} 
