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
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> st;
        ListNode* t=head;
        while(t)
        {
            st.push(t);
            t=t->next;
        }
       
        while(!st.empty() && head)
        {
            if(st.top()->val!=head->val)
                return false;
            head=head->next;
            st.pop();
        }
        return true;
    }
};