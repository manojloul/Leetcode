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
        
        ListNode* temp=head;
        
        while(temp)
        {
            bool f=true;
            
            while(temp->next && temp->val==temp->next->val)
            {
                f=false;
                temp=temp->next;
            }
            
            if(f)
            {
                if(root==NULL)
                {
                    root=temp;
                    prev=root;
                }
                else
                {
                    prev->next=temp;
                    prev=prev->next;
                }
            }
            temp=temp->next;
        }
        
        if(prev) prev->next=NULL;
        return root;
        
    }
};