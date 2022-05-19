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
    ListNode* reverse(ListNode* s,ListNode* e)
    {
        if(s==e) return s;
        ListNode* prev=NULL,*curr=s;
        //cout<<s->val<<" "<<e->val<<endl;
        while(curr && curr!=e)
        {
            s=curr->next;
            
            curr->next=prev;
            prev=curr;
            
            curr=s;
        }
        curr->next=prev;
        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int t=k;
        ListNode* temp=head;
        while(temp->next && t>1)
        {
            temp=temp->next;
            t--;
        }  
        cout<<t<<endl;
        ListNode* tp=temp->next;
        if(t==1){
        ListNode* nhead=reverse(head,temp);
        
        head->next=reverseKGroup(tp,k);
        return nhead;}
        return head;
       
    }
};