//main function
#define p 750 //�[��
int mora(){
	fflush(stdin);
	int yes = 1;
	int fen = 0;
	int win =0;
	int lose =0;
	int count =0;
	puts("------------------�q���C��(�T�Ԩ��)--------------------");
	while(yes){
		if (count<4 || win<3 ){ //�̦h3����or win 2�������C�� or lose 2�������C��  
			puts("1.�ŤMscissors  2.���Yrock	3.�� paper");
			int user=0;
			srand( time(NULL) );//�H���q��
			int a=(rand()%3)+1;  
			puts("�}�l�q��....\n");
			scanf("%d",&user);
			//count +=1; //�Ʀ@���X��
			switch(user){
				case 1: 	
					if(a==1) { 
							  puts("���X�F�ŤM");
							  puts("Again ����!"); 
							 } 
					if(a==2) {count +=1; //�Ʀ@���X��
							  puts("���X�F���Y");
							  lose +=1;
							  printf("�A��F %d ��\n",lose);
							  puts("----------------------");
							  
							 } 	  
					if(a==3) {
							  count +=1; //�Ʀ@���X��
							  puts("���X�F��");
							  win+=1;
							  printf("�AĹ�F %d ��\n",win);
							  fen = fen + p;
							  puts("----------------------");
							 }
					break;
					
				case 2: 
					if(a==1) {count +=1; //�Ʀ@���X��
							  fen = fen + p;
					 		  puts("���X�F�ŤM");
							  win+=1;
							  printf("�AĹ�F %d ��\n",win);
							  puts("----------------------");

						     } 
					if(a==2) {
							  puts("���X�F���Y");
							  puts("Again ����!");
							  
							 } 
					if(a==3) {count +=1; //�Ʀ@���X��
							  puts("���X�F��");
							  lose +=1;
							  printf("�A��F %d ��\n",lose);
							  puts("----------------------");

							 } 
					break;	
					
				case 3: 
					if(a==1) {count +=1; //�Ʀ@���X��
							  puts("���X�F�ŤM");
							  lose +=1;
							  printf("�A��F %d ��\n",lose);
							  puts("----------------------");
							 } 
					if(a==2) {puts("���X�F���Y");
							  fen = fen + p;
							  win+=1;
							  printf("�AĹ�F %d ��\n",win);
							  puts("----------------------");
							  count +=1; //�Ʀ@���X��

							  
						     } 
					if(a==3) {
							  puts("���X�F��");
							  puts("Again ����!\n"); 
							 } 
					break;	
				default:
				system("cls");
				printf("�A����ܿ��~,�h�X....\n");
				fen-=500;
				printf("\n�@�o�F %d ��\n\n",fen);
				system("pause");
				return fen;
				break;
			}
		}	
			if (lose==2){
				puts("You lose �A��F!");
				printf("�@�o�F %d ��\n",fen);
				puts("------�C������------\n");
				system("pause");
				yes=0;
			}
			if(win==2){
				puts("You win �AĹ�F!");
				printf("�@�o�F %d ��\n",fen);
				puts("------�C������------\n");
				system("pause");
				yes=0;
			}
		}
		fflush(stdin);
		return fen;	
}

