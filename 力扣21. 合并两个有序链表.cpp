/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//这道题用设置结构体变量栈分配内存更好（栈指针移动速度更快）,但我用的malloc分配内存（系统调用速度更慢）
// tail = list2;链表连接错了，->什么时候用？ 
//结果错误，没保存链表表头，结果返回值要返回一个连接好的链表，而不是以为遍历打印之后写一个return 0做装饰品
 
/* 
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    //先比较两个链表头节点哪个小，需要一个空节点作为开头
    struct ListNode* new_head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail = new_head;
    tail->next = NULL;

    while((list1 != NULL) && (list2 != NULL)){
        if(list1->val <= list2->val){
            //导入节点元素
            tail->next = list1;
            //被选中列表指针往后移一个
            list1 = list1->next;
        }
        else{
            //导入节点元素；
            tail->next = list2;
            //被选中列表指针往后移一个
            list2 = list2->next;
        }
        //结构体指针后移
        tail = tail->next;
    }

    //考虑其中一个list已经为空的状态
    if(list1 == NULL && list2 != NULL){
        tail = list2;
    }
    else{
        tail = list1;
    }
    free(new_head);
    
    //遍历打印链表结果
    while(tail != NULL){
        printf("%d", tail->val);
        tail = tail->next;
    }
    return 0;
}
*/

//修改后通过的代码
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    //需要一个空节点作为开头，设置哑节点
    struct ListNode* new_head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail = new_head;
    tail->next = NULL;
    
    //比大小
    while((list1 != NULL) && (list2 != NULL)){
        if(list1->val <= list2->val){
            //导入节点元素
            tail->next = list1;
            //被选中列表指针往后移一个
            list1 = list1->next;
        }
        else{
            //导入节点元素；
            tail->next = list2;
            //被选中列表指针往后移一个
            list2 = list2->next;
        }
        //结构体指针后移
        tail = tail->next;
    }

    //考虑其中一个list已经为空的状态
    if(list1 == NULL && list2 != NULL){
        tail->next = list2;
    }
    else{
        tail->next = list1;
    }
    //释放前保存真正的链表头
    struct ListNode* result = new_head->next;
    free(new_head);
    
    //可以直接返回result，练一练遍历打印链表结果
    struct ListNode* cur = result;
    while(cur != NULL){
        printf("%d", cur->val);
        cur = cur->next;
    }
    printf("\n");

    return result;
} 
