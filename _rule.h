void rule(){
	char option[1];
	int right=0;
	
	printf("�w��Ө�Y��ϴ�\n");
	while(option[0]!='\0'){
		printf("\n1-    �i�J�@��\n");
		printf("2-    ���L\n");
		printf("�п�J�z����ܡG");
		gets(option);
		if(option[0]=='1'||option[0]=='2'){
			fflush(stdin);
			break;
		}
	}
		
	if(option[0]=='1'){
		printf("\n�C���W�h(�ʡK�ʹʡK�ʹʹʡK)\n\n");
		Sleep(1000);
		printf("�u���K�����x�A�ש�K���T���F�A�K��K�൹�z�v\n");
		printf("�u�o�̬O NSK-MUY�P�ϡAMIS3051�Pĥ�A�D�J�|�۹Źŭ��ļ��A�Y�����l�v\n");
		printf("�u�ШD�A����p���P�P���p���B�N��ϴ��v\n\n");
		printf("�u�o�̬O����p���P�A�T�q�p�X�줽�ҡA���z�ϴ��ШD�A�Y��X�ʡv\n\n");
		printf("�u�ڭ̥u��A���3�����A�q�̦�˿ǯ}�F�}�v\n\n");
		printf("�u����A�N������P�ϴ����A�n�t�˴������A�e���K. (�_�T)�v\n\n");
		
		Sleep(2000);
		printf("�uĥ���A�w��n�Wĥ���A�o����S�űϴ���ʡA�N��V���ӬP�ڭy��A�бz���[�Q��<��V��-�W>�i��ĥ���[�t\n");
		printf("�Ӧ��ȳ~�N���`�A�i�A�б��v�ͩR�v��I�v\n\n");
		
		Sleep(1000);
		printf("�uA-	��è�~���o���ȡA�کڵ��v\n");
		printf("�uB-	�ڱ����o�ӥ��ȡv\n\n");
		printf("�п�J�z����ܡG");
		gets(option);
		
		while(option[0]!='\0'){		
			if(option[0]=='A'){
				fflush(stdin);
				printf("�u�z�S����ܪ��v�Q�A���z�Z�B�����A�����쨭�G�O�I���v\n\n");
				system("pause");
				break;
			}
			else if(option[0]=='B'){
				fflush(stdin);
				printf("�u�P�±z�����x�A���z�Z�B�����v\n\n");
				system("pause");
				break;
			}
			else{
				printf("\n�u�����x�п�J���T���O�v\n");
				printf("�uA-	��è�~���o���ȡA�کڵ��v\n");
				printf("�uB-	�ڱ����o�ӥ��ȡv\n");
				printf("�п�J�z����ܡG");
				gets(option);
			}	
		}	
	} 	
}

