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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode* t=head;
        int l=1;
        while(t->next) {
            t=t->next;
            l++;
        }
        t->next=head;
        k=k%l;
        
        k=l-k;
        while(k--)
            head=head->next;
        
        t=head;
        while(t->next!=head)
            t=t->next;
        t->next=NULL;
        return head;
        
    }
};