/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=NULL,*temp=NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        int carry=0;
        while(l1 && l2)
        {
            int k=l1->val+l2->val+carry;
            carry=k/10;
            ListNode* t=new ListNode(k%10);
            if(head==NULL)
            {
                head=t;
                temp=head;
            }
            else
            {
                temp->next=t;
                temp=temp->next;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
            int k=carry+l1->val;
            carry=k/10;
            ListNode* t=new ListNode(k%10);
            temp->next=t;
            
            l1=l1->next;temp=temp->next;
        }
        while(l2)
        {
            int k=carry+l2->val;
            carry=k/10;
            ListNode* t=new ListNode(k%10);
            temp->next=t;
            
            l2=l2->next;temp=temp->next;
        }
        if(carry)
        {
            ListNode* t=new ListNode(carry);
            temp->next=t;
             
        }
        return head;
    }
};