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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return head;
        int p=k-1;
        ListNode* tail=head;
        while(p-- && tail->next)
            tail=tail->next;
        
        //cout<<p<<endl;
        if(p>=0) return head;
         ListNode* prev=NULL,*curr=head,*temp=tail->next;
        ListNode* t=head;
        
        while(curr!=tail)
        {
            head=curr->next;
            
            curr->next=prev;
            prev=curr;
            
            curr=head;
        }
        curr->next=prev;
        head=curr;
        tail=t;
        
        tail->next=reverseKGroup(temp,k);
        return head;
    }
};