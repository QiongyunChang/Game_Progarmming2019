int respond();
//main function
int question(){//main function
	fflush(stdin);
	int fen = 0;
	printf("是非題，正確請答\'Y\'，錯誤請答\'N\'。\n\n");
	//Q1 
	printf("Emily Du的身高是174公釐？\n"); 
	
	int ans;
	ans = respond();
	
	if(ans == 0){
		printf("你答對了！\n\n");
		fen+=300;
	}
	else if(ans == 1){
		printf("你答錯了！\n公釐=0.1公分，她又不是蟻人><\n\n");
		fen-=100;
	}
	else{
		printf("你是沒長眼睛？？\n\n");
		fen-=200;
	}
	//Q2 
	printf("林孟儒常常參加中獎？\n");  //錯
	
	ans = respond();
	
	if(ans == 0){
		printf("你答對了！\n\n");
		fen+=300;
	}
	else if(ans == 1){
		printf("你答錯了！\n她很少參加抽獎，可是只要參加就會中獎：）\n\n");
		fen-=100;
	}
	else{
		printf("你是沒長眼睛？？\n\n");
		fen-=200;
	}
	//Q3
	printf("蕭哲芬很怕冷？\n");  //錯 
	
	ans = respond();
	
	if(ans == 0){
		printf("你答對了！\n\n");
		fen+=300;
	}
	else if(ans == 1){
		printf("你答錯了！\n這個還會答錯？\n\n");
		fen-=100;
	}
	else{
		printf("你是沒長眼睛？？\n\n");
		fen-=200;
	} 
	//Q4
	printf("康藝晃是不是帥哥？\n");  //錯 
	
	ans = respond();
	
	if(ans == 0){
		printf("你答對了！\n\n");
		fen+=600;
	}
	else if(ans == 1){
		printf("你答錯了！\n是超級無敵大帥哥！\n\n");
		fen-=100;
	}
	else{
		printf("你是沒長眼睛？？\n\n");
		fen-=200;
	} 
	//結算 
	printf("\n恭喜獲得%d分\n\n", fen);  //用以計算分數 
	system("pause");
	fflush(stdin);
	return fen;
}

int respond(){
	
	char res;
	
	printf("請輸入Y或N：");
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
