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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev=NULL,*root=NULL;
        ListNode* curr=head;
        
        while(curr)
        {
            bool f=false;
            while(curr->next && (curr->val==curr->next->val))
            {
                f=true;
                curr=curr->next;
            }
            if(f==false)
            {
                if(prev==NULL)
                {
                    prev=curr;
                    root=prev;
                }
                else
                {
                    prev->next=curr;
                    prev=prev->next;
                }
                
            }
            curr=curr->next;
        }
        if(prev)
        prev->next=NULL;
        return root;
    }
};