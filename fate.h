/*game-�ͤ�e�P�N 
�j�� �� 10�� 
��   �� 5�� 
���q ���[�� 
�N   �[ 5�� 
�j�N �[ 10�� 
*/
//����k�v�e�R�N


//main function
int fate(void){
	fflush(stdin);
	int fen = 0;
	int month, day, sum = 0;
	char a,b;
	printf("�п�J�z���ͤ�]�Ҧp�G12 5�^�G");
	scanf("%d %d", &month, &day);
		
	while(month > 12 || month < 1||day > 31 || day < 1){
		printf("�A�O�ݤ�������H�H�H\n�A��J�@���G\n");
		fflush(stdin);
		fen-=500; 
		scanf("%d %d", &month, &day);
	}
	sum = (month * 2 + day) % 5 + 1;

	switch(sum){
		
		case 1:
			printf("\n�j��\n");
			fen -= 600;
			break;
			
		case 2:
			printf("\n��\n");
			fen -= 300;
			break;		
		
		case 3:
			printf("\n���q\n");
			fen += 500;
			break;
	
		case 4:
			printf("\n�N\n");
			fen += 1000;
			break;
		
		case 5:
			printf("\n�j�N\n");
			fen += 1500;
			break;
	}	
	printf("\n������o%d��\n\n",fen);
	fflush(stdin);
	system("pause");
	return fen;
}
