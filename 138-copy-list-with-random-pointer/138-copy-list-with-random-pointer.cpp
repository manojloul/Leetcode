/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       Node* root=NULL;
        Node* temp=head;
        Node* t=NULL;
        unordered_map<Node*,Node*> mp;
        while(temp)
        {
            Node* p=new Node(temp->val);
            if(root==NULL)
            {
                root=p;
                t=root;
            }
            else{
            t->next=p;
            t=t->next;
            }
            mp[temp]=p;
            temp=temp->next;
        }
        
        t=root;
        while(head)
        {
            t->random=mp[head->random];
            head=head->next;
            t=t->next;
        }
        return root;
    }
};