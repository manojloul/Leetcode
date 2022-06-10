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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        if(head->next==head) return head;
        
        ListNode* slow=head,*fast=head;
        
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast) break;
        }
        if(fast!=slow) return NULL;
        
        //cout<<fast->val<<" "<<slow->val<<endl;
        while(head!=slow)
        {
            head=head->next;
            slow=slow->next;
        }
        return head;
    }
};