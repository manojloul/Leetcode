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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL|| head->next==NULL) return head;
        ListNode* p=NULL,*curr=head,*prev=head;
        
        while(curr)
        {
            if(curr->val<x)
            {
                if(p==NULL)
                {
                    if(curr==head)
                    {
                        p=head;
                        curr=curr->next;
                    }
                    else
                    {
                        prev->next=curr->next;
                        curr->next=head;
                        p=curr;
                        head=p;
                        curr=prev->next;
                    }
                }
                else
                {
                    if(p==prev)
                    {
                        prev=curr;
                        p=curr;
                        curr=curr->next;
                        continue;
                    }
                    prev->next=curr->next;
                    curr->next=p->next;
                    p->next=curr;
                    p=p->next;
                    curr=prev->next;
                }
            }
            else
            {
                prev=curr;
                curr=curr->next;
            }
        }
        
        return head;
    }
};