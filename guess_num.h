int guess_num(){
	fflush(stdin);
	printf("這是一個猜數字的遊戲，你必須輸入一個不重複的三位數（1~9）\n");
	printf("假如你輸入的三位數中，其中一個數的數字和位置都對了，便會得到一個A\n");
	printf("假如你輸入的三位數中，其中一個數的數字對了，但位置錯了，便會得到一個B\n");
	printf("以此類推\n開始遊戲吧！\n");
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
		printf("請輸入一個不重複數字的三位數：");
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
			printf("恭喜你猜出來了！！\n");
			fen+=1500;
			break;
		}	
	}	
	if(fen>0)
	printf("\n恭喜獲得%d分\n\n",fen);
	else
	printf("\n可惜了，再接再厲。\n\n");	
	system("pause");
	fflush(stdin);
	return fen;
}
