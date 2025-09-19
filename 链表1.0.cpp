#include<stdio.h>
#include<stdlib.h> 

//����ṹ�� 
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
	
	//���������ڵ��������
	L0->next = L1;
	L1->next = L2;
	
	//��ǰ����0 10 30 
	print_ListNode(L0);
	
	//ͨ��β�����ڵ�
	InsertTail(L0, 40);
	print_ListNode(L0);
	
	return 0;
}

//������ӡ�������
void print_ListNode(ListNode* L0){
	ListNode* cur = L0;
	while(cur != NULL){
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
} 

//β�巨�������� 
void InsertTail(ListNode *L0, int v){
	
	//���ҵ�β�ڵ㣬β�ڵ��next��ָ��NULL 
	//����һ��ָ��cur->next == NULL��˵��cur�Ѿ�ָ�����һ���ڵ���
	
	ListNode* cur = L0;
	
	//�ҵ����һ���ڵ�
	while(cur->next != NULL){
		cur = cur->next;
	}
	// ������cur�Ѿ�ָ�����һ���ڵ�
	
	//�ȶ���һ���ڵ�
	ListNode* NewNode = (ListNode*)malloc(sizeof(NewNode));
	NewNode->val = v;
	NewNode->next = NULL;      //�½ڵ��next����NULL 
	
	//��ǰ�б����һ���ڵ�nextָ��NULL
	cur->next = NewNode;
	
}
	
