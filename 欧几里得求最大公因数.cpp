//ŷ������㷨
//����m,n
//��m����n������
//��������Ψ0�����n��ֵ����m����r��ֵ����n
//ֱ��rΪ0Ϊֹ 

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
