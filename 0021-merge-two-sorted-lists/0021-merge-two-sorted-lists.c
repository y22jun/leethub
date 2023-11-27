/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1,struct ListNode* list2)
{
    struct ListNode* a=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* b=a;
    if(list1==NULL) return list2;
    if(list2==NULL) return list1;
    while(list1!=NULL&&list2!=NULL)
    {
        if(list1->val>=list2->val)
        {
            b->next=list2;
            list2=list2->next;
        }
        else
        {
            b->next=list1;
            list1=list1->next;
        }
        b=b->next;
    }
    if(list1!=NULL) b->next=list1;
    if(list2!=NULL) b->next=list2;
    struct ListNode* res=a->next;
    free(a);
    return res;
}