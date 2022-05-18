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
        int ll1=0,ll2=0;
        ListNode* l1=headA;
        ListNode* l2=headB;
        while(l1)
        {
            ll1++;
            l1=l1->next;
        }
        while(l2)
        {
            ll2++;
            l2=l2->next;
        }
        
            while(ll1>ll2)
            {
                ll1--;
                headA=headA->next;
            }
        
        while(ll2>ll1)
        {
            ll2--;
            headB=headB->next;
        }
        
        while(headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};