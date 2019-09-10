#include"fate.h"
#include"question.h"
#include"bomb.h"
#include"guess_num.h"
#include"mora.h"

int bonus(){
	srand(time(NULL));
	int x=rand()%5+1;
	int plus=0;
	//x=5;
	switch(x){
		case 1:plus=fate();break;
		case 2:plus=question();break;
		case 3:plus=bomb();break;
		case 4:plus=guess_num();break;
		case 5:plus=mora();break;
	}
	return plus;
}

