#include<stdio.h>
#include<stdlib.h>

//1.��������Ľڵ�ṹ��ÿ���ڵ��һ����������һ�����ĵ�ַ
typedef struct Node{
	int data; //������
	struct Node *next ; //ָ����һ������ָ�� 
} Node, *LinkedList;

// 2.��ʼ����������һ��������ֻ��ͷ�ڵ㣬�������ݣ�
LinkedList initList(){
	LinkedList head = (Node*)malloc(sizeof(Node)); //����ͷ�ڵ���ڴ�
	head->next = NULL; //ͷ�ڵ������ʱû��Ԫ��
	return head; 
} 

//3.�������в���һ�����������������С��������
void insert(LinkedList head, int num){
	//3.1�ȴ���һ���½ڵ㣬��Ҫ��������� 
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = num;
	newNode->next = NULL;
	
	//3.2�ҵ�����λ�ã�������ָ���������
	Node *pre = head;      //pre��Զ��q��ǰ��
	Node *q = head->next; // q�����ҵ�һ����num��Ľ�� 
	
	//��q��Ϊ�գ���q�����ֱ�numС���ͼ���������
	while(q != NULL && q->data < num){
		pre = q;       //pre����q�ƶ�
		q = q->next;   //q������һ�� 
	}
	
	//3.3���½ڵ�嵽pre��q֮��
	newNode->next = q; //�½ڵ��nextָ��q 
	pre->next = newNode;//pre��nextָ���½ڵ� 
} 

//4.��ӡ�����е�����Ԫ��
void printList(LinkedList head){
	Node *p = head->next; //�ӵ�һ�������ݵĽ�㿪ʼ
	printf("�������ݣ�");
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;     //�����ƶ� 
	} 
	printf("\n"); 
} 

//����:����
int main(){
	//5.1����һ��������
	LinkedList list = initList();
	
	//5.2���뼸�����֣�����������֣�
	insert(list, 3);
	insert(list, 1);
	insert(list, 5);
	insert(list, 2);
	insert(list, 0);
	
	//5.3��ӡ�����ǲ�������� 
	printList(list);
	
	return 0; 
} 
