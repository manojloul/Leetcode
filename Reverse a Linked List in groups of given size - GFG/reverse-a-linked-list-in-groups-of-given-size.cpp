//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    node* solve(node* root)
    {
        if(!root || !root->next) return root;
        
        node* tmp = solve(root->next);
        node* headn= root->next;
        headn->next=root;
        root->next= NULL;
        return tmp;
    }
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        node* headn=NULL;
        node* tmp=head;
        int p=k;
        while(tmp)
        {
            p--;
            if(p==0)
            {
                node* pp=tmp->next;
                tmp->next=NULL;
                if(!headn)
                 headn=solve(head);
                else
                {
                    node* t=headn;
                    while(t->next) t=t->next;
                    t->next=solve(head);
                }
                head=pp;
                tmp=head;
                p=k;
                continue;
            }
            tmp=tmp->next;
        }
        if(head)
        {
            if(!headn)
                 headn=solve(head);
            else
            {
                node* t=headn;
                while(t->next) t=t->next;                   
                t->next=solve(head);
            }
        }
        return headn;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends