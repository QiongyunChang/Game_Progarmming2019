/*game-生日占星術 
大凶 扣 10分 
凶   扣 5分 
普通 不加分 
吉   加 5分 
大吉 加 10分 
*/
//兩光法師占卜術


//main function
int fate(void){
	fflush(stdin);
	int fen = 0;
	int month, day, sum = 0;
	char a,b;
	printf("請輸入您的生日（例如：12 5）：");
	scanf("%d %d", &month, &day);
		
	while(month > 12 || month < 1||day > 31 || day < 1){
		printf("你是看不懂中文？？？\n再輸入一次：\n");
		fflush(stdin);
		fen-=500; 
		scanf("%d %d", &month, &day);
	}
	sum = (month * 2 + day) % 5 + 1;

	switch(sum){
		
		case 1:
			printf("\n大凶\n");
			fen -= 600;
			break;
			
		case 2:
			printf("\n凶\n");
			fen -= 300;
			break;		
		
		case 3:
			printf("\n普通\n");
			fen += 500;
			break;
	
		case 4:
			printf("\n吉\n");
			fen += 1000;
			break;
		
		case 5:
			printf("\n大吉\n");
			fen += 1500;
			break;
	}	
	printf("\n恭喜獲得%d分\n\n",fen);
	fflush(stdin);
	system("pause");
	return fen;
}
