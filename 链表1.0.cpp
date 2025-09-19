#include<stdio.h>
#include<stdlib.h> 

//定义结构体 
struct ListNode{
	int val;
	ListNode* next;
};

void print_ListNode(ListNode* L0);
void InsertTail(ListNode *L0, int v);

int main(){
	ListNode* L0 = (ListNode*)malloc(sizeof(ListNode));
	L0->val = 0;
	L0->next = NULL;
	
	ListNode* L1 = (ListNode*)malloc(sizeof(ListNode));
	L1->val = 10;
	L1->next = NULL;
	
	ListNode* L2 = (ListNode*)malloc(sizeof(ListNode));
	L2->val = 30;
	L2->next = NULL;
	
	//将这三个节点组成链表
	L0->next = L1;
	L1->next = L2;
	
	//当前链表0 10 30 
	print_ListNode(L0);
	
	//通过尾插插入节点
	InsertTail(L0, 40);
	print_ListNode(L0);
	
	return 0;
}

//遍历打印这个链表
void print_ListNode(ListNode* L0){
	ListNode* cur = L0;
	while(cur != NULL){
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
} 

//尾插法创建链表 
void InsertTail(ListNode *L0, int v){
	
	//先找到尾节点，尾节点的next是指向NULL 
	//定义一个指针cur->next == NULL，说明cur已经指向最后一个节点了
	
	ListNode* cur = L0;
	
	//找到最后一个节点
	while(cur->next != NULL){
		cur = cur->next;
	}
	// 运行完cur已经指向最后一个节点
	
	//先定义一个节点
	ListNode* NewNode = (ListNode*)malloc(sizeof(NewNode));
	NewNode->val = v;
	NewNode->next = NULL;      //新节点的next等于NULL 
	
	//当前列表最后一个节点next指向NULL
	cur->next = NewNode;
	
}
	
