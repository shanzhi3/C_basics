/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//����������ýṹ�����ջ�����ڴ���ã�ջָ���ƶ��ٶȸ��죩,�����õ�malloc�����ڴ棨ϵͳ�����ٶȸ�����
// tail = list2;�������Ӵ��ˣ�->ʲôʱ���ã� 
//�������û���������ͷ���������ֵҪ����һ�����Ӻõ�������������Ϊ������ӡ֮��дһ��return 0��װ��Ʒ
 
/* 
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    //�ȱȽ���������ͷ�ڵ��ĸ�С����Ҫһ���սڵ���Ϊ��ͷ
    struct ListNode* new_head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail = new_head;
    tail->next = NULL;

    while((list1 != NULL) && (list2 != NULL)){
        if(list1->val <= list2->val){
            //����ڵ�Ԫ��
            tail->next = list1;
            //��ѡ���б�ָ��������һ��
            list1 = list1->next;
        }
        else{
            //����ڵ�Ԫ�أ�
            tail->next = list2;
            //��ѡ���б�ָ��������һ��
            list2 = list2->next;
        }
        //�ṹ��ָ�����
        tail = tail->next;
    }

    //��������һ��list�Ѿ�Ϊ�յ�״̬
    if(list1 == NULL && list2 != NULL){
        tail = list2;
    }
    else{
        tail = list1;
    }
    free(new_head);
    
    //������ӡ������
    while(tail != NULL){
        printf("%d", tail->val);
        tail = tail->next;
    }
    return 0;
}
*/

//�޸ĺ�ͨ���Ĵ���
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    //��Ҫһ���սڵ���Ϊ��ͷ�������ƽڵ�
    struct ListNode* new_head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail = new_head;
    tail->next = NULL;
    
    //�ȴ�С
    while((list1 != NULL) && (list2 != NULL)){
        if(list1->val <= list2->val){
            //����ڵ�Ԫ��
            tail->next = list1;
            //��ѡ���б�ָ��������һ��
            list1 = list1->next;
        }
        else{
            //����ڵ�Ԫ�أ�
            tail->next = list2;
            //��ѡ���б�ָ��������һ��
            list2 = list2->next;
        }
        //�ṹ��ָ�����
        tail = tail->next;
    }

    //��������һ��list�Ѿ�Ϊ�յ�״̬
    if(list1 == NULL && list2 != NULL){
        tail->next = list2;
    }
    else{
        tail->next = list1;
    }
    //�ͷ�ǰ��������������ͷ
    struct ListNode* result = new_head->next;
    free(new_head);
    
    //����ֱ�ӷ���result����һ��������ӡ������
    struct ListNode* cur = result;
    while(cur != NULL){
        printf("%d", cur->val);
        cur = cur->next;
    }
    printf("\n");

    return result;
} 
