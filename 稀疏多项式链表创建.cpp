#include<stdio.h>
#include<stdlib.h> //?

//��������ʽ�ڵ�ṹ
typedef struct PNode{ //�� 
	float coef;   //ϵ��
	int expn;    //ָ�� 
	struct PNode* next;   //ָ����һ������ָ�� 
}PNode, *Polynomial; //Ϊʲô�ֺ�ǰҪ������������ 

//��������ʽ����ĺ���
void CreatePolyn(Polynomial &P, int n){
	P = (PNode*)malloc(sizeof(PNode));  //����ͷ�ڵ�
	P->next = NULL;  //��ʼ��ͷ�ڵ��nextָ��
	
	for(int i = 1; i <= n; ++i){  //Ϊʲô��++i������i++ 
		PNode* s = (PNode*)malloc(sizeof(PNode)); //�����½ڵ� 
		scanf("%f &d", &s->coef, &s->expn); // ����ϵ����ָ�� 
		
		PNode* pre = P; //pre���ڱ���q��ǰ������ֵΪͷ�ڵ� 
		PNode* q = P->next;  //q��ʼ����ָ����Ԫ���
		
		//�ҵ���һ������������ָ������*q
		while(q && q->expn < s->expn){
			pre = q;
			q = q->next;
		}
		
		s->next = q; //��������s���뵽q����ǰ���ڵ�pre֮��
		 pre->next = s; 
	}
}

//��ӡ����ʽ����ĺ���
void PrintPolyn(Polynomial P){
	PNode* q = P->next;
	while(q){
		if(q->coef != 0){
			if(q != P->next && q->coef > 0){
				printf(" + ");
			}
			
			if(q->coef != 1 && q->coef != -1){
				printf("%.1f", q->coef != -1);
			}
			else if(q->coef == -1){
				printf("-");
			}
			if(q->expn == 0){
				//ָ��Ϊ0ʱ��ֻ��ӡϵ�� 
			}
			else if(q->expn == 1){
				if(q->coef == 1){
					printf("x");
				}
				else{
					printf("x");
				}
			}
			
			else{
				if(q->coef == 1){
					printf("x^%d", q->expn);
				}
				else{
					printf("%.1fx^%d", q->coef, q->expn);
				}
			}
		}
		q = q->next;
	}
	printf("\n");
}

int main(){
	Polynomial P;
	int n;
	printf("���������ʽ��ĸ���");
	scanf("%d", &n);
	printf("����������ÿ���ϵ����ָ�����Կո�ָ�����\n");
	CreatePolyn(P, n);
	printf("�����Ķ���ʽΪ��");
	PrintPolyn(P);
	return 0; 
}
 
