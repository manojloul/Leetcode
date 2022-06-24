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
        Node* t=root,*temp=head;
        unordered_map<Node*,Node*> mp;
        while(temp)
        {
            Node* p=new Node(temp->val);
            mp[temp]=p;
            temp=temp->next;
            
            if(root==NULL)
            {
                root=p;
                t=p;
            }
            else
            {
                t->next=p;
                t=t->next;
            }
        }
        
        t=head;
        while(t)
        {
            mp[t]->random=mp[t->random];
            t=t->next;
        }
        return root;
    }
};