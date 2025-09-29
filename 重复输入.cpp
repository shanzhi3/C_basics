/*echo.c -- 重复输入*/

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
    count++;         // 只有成功输出字符后，count才+1
}
*/

/*
for(count = 0; count < 10; count++){  // 循环自带count++（每次循环结束后执行），输出不是字符count也+1 
    ch = getchar();                    
    if(ch == '\n')                     
        continue;                      
    putchar(ch);                       
}
*/


