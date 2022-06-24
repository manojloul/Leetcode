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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        int l=0;
        ListNode* t=head;
        while(t)
        {
            st.push(t);
            t=t->next;
            l++;
        }
        l/=2;
        t=head;
        
        while(l--)
        {
            ListNode* p=st.top();
            st.pop();
            p->next=t->next;
            t->next=p;
            t=p->next;
        }
        t->next=NULL;
        
    }
};