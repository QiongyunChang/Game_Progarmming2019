int guess_num(){
	fflush(stdin);
	printf("�o�O�@�Ӳq�Ʀr���C���A�A������J�@�Ӥ����ƪ��T��ơ]1~9�^\n");
	printf("���p�A��J���T��Ƥ��A�䤤�@�Ӽƪ��Ʀr�M��m����F�A�K�|�o��@��A\n");
	printf("���p�A��J���T��Ƥ��A�䤤�@�Ӽƪ��Ʀr��F�A����m���F�A�K�|�o��@��B\n");
	printf("�H������\n�}�l�C���a�I\n");
	printf("=======================================================================\n\n");
	int times=0,fen=0;
	int a=rand()%9+1;//1~9
	int b,integer,c,d,e,f,A,B;
	while(1){
		b=rand()%9+1;
		if(b!=a) break;
	}
	while(1){
		c=rand()%9+1;
		if(c!=a&&c!=b) break;
	}
	while(times<6){
		times++;
		A=0;B=0;
		printf("�п�J�@�Ӥ����ƼƦr���T��ơG");
		scanf("%d", &integer);
		d=integer/100;
		e=(integer-d*100)/10;
		f=integer%10;
		if(d==a) A++;
		else{
			if(d==b) B++;
			if(d==c) B++;
		}
		if(e==b) A++;
		else{
			if(e==a) B++;
			if(e==c) B++;
		}
		if(f==c) A++;
		else{
			if(f==b) B++;
			if(f==a) B++;
		}
		printf("%dA%dB\n\n",A,B);
		if(A==3) {
			printf("���ߧA�q�X�ӤF�I�I\n");
			fen+=1500;
			break;
		}	
	}	
	if(fen>0)
	printf("\n������o%d��\n\n",fen);
	else
	printf("\n�i���F�A�A���A�F�C\n\n");	
	system("pause");
	fflush(stdin);
	return fen;
}
