/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0,l2=0;
        ListNode* t1=headA,*t2=headB;
        
        while(t1)
        {
            l1++;
            t1=t1->next;
        }
        while(t2)
        {
            l2++;
            t2=t2->next;
        }
        
        if(l1>l2)
        {
            int k=l1-l2;
            while(k--)
                headA=headA->next;
        }
        else
        {
            int k=l2-l1;
            while(k--)
                headB=headB->next;
        }
        
        while(headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        if(headA==headB) return headA;
        return NULL;
    }
};