/*echo.c -- �ظ�����*/

#include<stdio.h>

int main(void){
	while(1){
		char ch = getchar();
		if(ch == '#')
			continue;
		putchar(ch);
	}
	return 0;	
}


/*
int main(void){
	char ch;
	
	while((ch  = getchar()) != '#')
		putchar(ch);
	
	return 0;
}
*/

/*
count = 0;
while(count < 10){  
    ch = getchar();  
    if(ch == '\n')   
        continue;    
    putchar(ch);     
    count++;         // ֻ�гɹ�����ַ���count��+1
}
*/

/*
for(count = 0; count < 10; count++){  // ѭ���Դ�count++��ÿ��ѭ��������ִ�У�����������ַ�countҲ+1 
    ch = getchar();                    
    if(ch == '\n')                     
        continue;                      
    putchar(ch);                       
}
*/


