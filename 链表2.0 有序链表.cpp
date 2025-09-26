#include<stdio.h>
#include<stdlib.h>

//1.定义链表的节点结构：每个节点存一个整数和下一个结点的地址
typedef struct Node{
	int data; //存整数
	struct Node *next ; //指向下一个结点的指针 
} Node, *LinkedList;

// 2.初始化链表：创建一个空链表（只有头节点，不存数据）
LinkedList initList(){
	LinkedList head = (Node*)malloc(sizeof(Node)); //申请头节点的内存
	head->next = NULL; //头节点后面暂时没有元素
	return head; 
} 

//3.向链表中插入一个整数，保持链表从小到大有序
void insert(LinkedList head, int num){
	//3.1先创建一个新节点，存要插入的数字 
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = num;
	newNode->next = NULL;
	
	//3.2找到插入位置：用两个指针遍历链表
	Node *pre = head;      //pre永远在q的前面
	Node *q = head->next; // q用来找第一个比num大的结点 
	
	//当q不为空，且q的数字比num小，就继续往后找
	while(q != NULL && q->data < num){
		pre = q;       //pre跟着q移动
		q = q->next;   //q往后走一步 
	}
	
	//3.3把新节点插到pre和q之间
	newNode->next = q; //新节点的next指向q 
	pre->next = newNode;//pre的next指向新节点 
} 

//4.打印链表中的所有元素
void printList(LinkedList head){
	Node *p = head->next; //从第一个存数据的结点开始
	printf("链表内容：");
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;     //往后移动 
	} 
	printf("\n"); 
} 

//主函:测试
int main(){
	//5.1创建一个空链表
	LinkedList list = initList();
	
	//5.2插入几个数字（故意打乱数字）
	insert(list, 3);
	insert(list, 1);
	insert(list, 5);
	insert(list, 2);
	insert(list, 0);
	
	//5.3打印看看是不是有序的 
	printList(list);
	
	return 0; 
} 
