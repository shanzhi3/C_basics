//欧几里得算法
//输入m,n
//求m除以n的余数
//若余数不唯0，则把n的值赋给m，把r的值赋给n
//直到r为0为止 

#include<stdio.h>
int main(){
	int m, n;
	int temp;
	scanf("%d %d", &m, &n);
	if (m < n){
		temp = m;
		m = n;
		n = temp;
	}
	int r;
	r = m % n;
	while (r != 0){
		m = n;
		n = r;
	}
	printf("The greatest common divisor of %d is %d\n", m, n);
	return 0;
} 
