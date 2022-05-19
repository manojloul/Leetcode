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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL,*curr=head;
        
        while(curr && curr->next)
        {
            head=curr->next;
            curr->next=prev;
            prev=curr;
            
            curr=head;
        }
        curr->next=prev;
        return curr;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
            return true;
        ListNode* slow=head,*fast=head,*t=head,*temp=head;
        
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        while(t->next!=slow)
            t=t->next;
        //cout<<t->val<<endl;
        t->next=reverse(slow);
        
        t=t->next;
        //cout<<t->val<<endl;
        slow=t;
        while(temp!=t)
        {
            if(temp->val!=slow->val) return false;
            temp=temp->next;
            slow=slow->next;
        }
        return true;
    }
};