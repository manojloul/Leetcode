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
        if(head->next==NULL)
            return;
        unordered_map<int,ListNode*> mp;
        
        ListNode* temp=head;
        int i=0;
        while(temp)
        {
            mp[i++]=temp;
            temp=temp->next;
        }
        int s=1,e=i-1;
        
        temp=head;
        while(s<e)
        {
            temp->next=mp[e--];
            temp=temp->next;
            temp->next=mp[s++];
            temp=temp->next;
        }
       // cout<<s<<" "<<e<<endl;
        if(s==e)
        {
            temp->next=mp[s];
            temp=temp->next;
        }
        temp->next=NULL;
    }
};