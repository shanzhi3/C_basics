#include<stdio.h>
#include<stdlib.h> //?

//定义多多项式节点结构
typedef struct PNode{ //？ 
	float coef;   //系数
	int expn;    //指数 
	struct PNode* next;   //指向下一个结点的指针 
}PNode, *Polynomial; //为什么分号前要跟这两个东东 

//创建多项式链表的函数
void CreatePolyn(Polynomial &P, int n){
	P = (PNode*)malloc(sizeof(PNode));  //创建头节点
	P->next = NULL;  //初始化头节点的next指针
	
	for(int i = 1; i <= n; ++i){  //为什么是++i而不是i++ 
		PNode* s = (PNode*)malloc(sizeof(PNode)); //生成新节点 
		scanf("%f &d", &s->coef, &s->expn); // 输入系数和指数 
		
		PNode* pre = P; //pre用于保存q的前驱，初值为头节点 
		PNode* q = P->next;  //q初始化，指向首元结点
		
		//找到第一个大于输入项指数的项*q
		while(q && q->expn < s->expn){
			pre = q;
			q = q->next;
		}
		
		s->next = q; //将输入项s插入到q和其前驱节点pre之间
		 pre->next = s; 
	}
}

//打印多项式链表的函数
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
				//指数为0时，只打印系数 
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
	printf("请输入多项式项的个数");
	scanf("%d", &n);
	printf("请依次输入每项的系数和指数（以空格分隔）：\n");
	CreatePolyn(P, n);
	printf("创建的多项式为：");
	PrintPolyn(P);
	return 0; 
}
 
