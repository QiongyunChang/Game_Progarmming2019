//main function
#define p 750 //加分
int mora(){
	fflush(stdin);
	int yes = 1;
	int fen = 0;
	int win =0;
	int lose =0;
	int count =0;
	puts("------------------猜拳遊戲(三戰兩勝)--------------------");
	while(yes){
		if (count<4 || win<3 ){ //最多3局或or win 2次結束遊戲 or lose 2次結束遊戲  
			puts("1.剪刀scissors  2.石頭rock	3.布 paper");
			int user=0;
			srand( time(NULL) );//隨機猜拳
			int a=(rand()%3)+1;  
			puts("開始猜拳....\n");
			scanf("%d",&user);
			//count +=1; //數共有幾局
			switch(user){
				case 1: 	
					if(a==1) { 
							  puts("對手出了剪刀");
							  puts("Again 平手!"); 
							 } 
					if(a==2) {count +=1; //數共有幾局
							  puts("對手出了石頭");
							  lose +=1;
							  printf("你輸了 %d 局\n",lose);
							  puts("----------------------");
							  
							 } 	  
					if(a==3) {
							  count +=1; //數共有幾局
							  puts("對手出了布");
							  win+=1;
							  printf("你贏了 %d 局\n",win);
							  fen = fen + p;
							  puts("----------------------");
							 }
					break;
					
				case 2: 
					if(a==1) {count +=1; //數共有幾局
							  fen = fen + p;
					 		  puts("對手出了剪刀");
							  win+=1;
							  printf("你贏了 %d 局\n",win);
							  puts("----------------------");

						     } 
					if(a==2) {
							  puts("對手出了石頭");
							  puts("Again 平手!");
							  
							 } 
					if(a==3) {count +=1; //數共有幾局
							  puts("對手出了布");
							  lose +=1;
							  printf("你輸了 %d 局\n",lose);
							  puts("----------------------");

							 } 
					break;	
					
				case 3: 
					if(a==1) {count +=1; //數共有幾局
							  puts("對手出了剪刀");
							  lose +=1;
							  printf("你輸了 %d 局\n",lose);
							  puts("----------------------");
							 } 
					if(a==2) {puts("對手出了石頭");
							  fen = fen + p;
							  win+=1;
							  printf("你贏了 %d 局\n",win);
							  puts("----------------------");
							  count +=1; //數共有幾局

							  
						     } 
					if(a==3) {
							  puts("對手出了布");
							  puts("Again 平手!\n"); 
							 } 
					break;	
				default:
				system("cls");
				printf("你的選擇錯誤,退出....\n");
				fen-=500;
				printf("\n共得了 %d 分\n\n",fen);
				system("pause");
				return fen;
				break;
			}
		}	
			if (lose==2){
				puts("You lose 你輸了!");
				printf("共得了 %d 分\n",fen);
				puts("------遊戲結束------\n");
				system("pause");
				yes=0;
			}
			if(win==2){
				puts("You win 你贏了!");
				printf("共得了 %d 分\n",fen);
				puts("------遊戲結束------\n");
				system("pause");
				yes=0;
			}
		}
		fflush(stdin);
		return fen;	
}

