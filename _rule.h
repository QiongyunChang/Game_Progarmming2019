void rule(){
	char option[1];
	int right=0;
	
	printf("歡迎來到即刻救援\n");
	while(option[0]!='\0'){
		printf("\n1-    進入劇情\n");
		printf("2-    跳過\n");
		printf("請輸入您的選擇：");
		gets(option);
		if(option[0]=='1'||option[0]=='2'){
			fflush(stdin);
			break;
		}
	}
		
	if(option[0]=='1'){
		printf("\n遊戲規則(嘟…嘟嘟…嘟嘟嘟…)\n\n");
		Sleep(1000);
		printf("「報…指揮官，終於…有訊號了，…刻…轉給您」\n");
		printf("「這裡是 NSK-MUY星區，MIS3051星艦，遭遇尚彥嘉嘉凍圓衝撞，嚴重毀損」\n");
		printf("「請求，哲芬小貝星星際聯邦處就近救援」\n\n");
		printf("「這裡是哲芬小貝星，三益聯合辦公所，受理救援請求，即刻出動」\n\n");
		printf("「我們只能再堅持3分鐘，益晃西裝褲破了洞」\n\n");
		printf("「收到，將派遣跨星救援艇，駐速森援蒂號，前往…. (斷訊)」\n\n");
		
		Sleep(2000);
		printf("「艦長，歡迎登上艦艇，這次為S級救援行動，將跨越五個星際軌域，請您善加利用<方向鍵-上>進行艦艇加速\n");
		printf("該次旅途將異常顛波，請授權生命權交付」\n\n");
		
		Sleep(1000);
		printf("「A-	白癡才接這任務，我拒絕」\n");
		printf("「B-	我接受這個任務」\n\n");
		printf("請輸入您的選擇：");
		gets(option);
		
		while(option[0]!='\0'){		
			if(option[0]=='A'){
				fflush(stdin);
				printf("「您沒有選擇的權利，祝您武運昌隆，拿的到身故保險金」\n\n");
				system("pause");
				break;
			}
			else if(option[0]=='B'){
				fflush(stdin);
				printf("「感謝您指揮官，祝您武運昌隆」\n\n");
				system("pause");
				break;
			}
			else{
				printf("\n「指揮官請輸入正確指令」\n");
				printf("「A-	白癡才接這任務，我拒絕」\n");
				printf("「B-	我接受這個任務」\n");
				printf("請輸入您的選擇：");
				gets(option);
			}	
		}	
	} 	
}

