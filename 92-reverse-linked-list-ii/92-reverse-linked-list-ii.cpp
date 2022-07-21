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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL|| left==right)
            return head;
        ListNode* start=NULL,*end=NULL;
        int k=1;
        
        ListNode* prev=head;
        
         if(left==1)
         {  start=head;
           k--;
         }
        else
        {
            while(k<left-1)
            {
                prev=prev->next;
                k++;
            }
            start=prev->next;
        }
        
        end=start;
        while(k<right-1)
        {
            end=end->next;
            k++;
        }
        cout<<start->val<<" "<<end->val<<endl;
        ListNode* curr=start;
        ListNode* p=end->next;
        ListNode* root=NULL;
        while(p!=end)
        {
            root=curr->next;
            
            curr->next=p;
            p=curr;
            curr=root;
        }
        if(left!=1)
         prev->next=p;
        else
            return p;
        return head;
    }
};