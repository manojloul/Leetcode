// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   // Your code here
   Node* temp = root;
    
    while(temp)
    {
        if(temp->bottom && temp->next)
        {
            
            if(temp->bottom->data <= temp->next->data)
            {
                temp->bottom->next = temp->next;
                temp->next = temp->bottom;
                temp->bottom = NULL;
                temp =temp->next;
            }
            else
            {
                Node * t1 = temp ->bottom;
                Node * t2 = temp->next->bottom;
                Node *headn = new Node(-1);
                Node *temp1 = headn;
                
                while(t1 && t2)
                {
                    if(t1->data <= t2->data)
                    {
                        temp1->bottom = new Node(t1->data);
                        t1 = t1->bottom;
                        temp1 = temp1->bottom;
                    }
                    else
                    {
                        temp1->bottom = new Node(t2->data);
                        t2=t2->bottom;
                        temp1 = temp1->bottom;
                    }
                }
                while(t1)
                {
                    temp1->bottom = new Node(t1->data);
                    t1 = t1->bottom;
                    temp1 = temp1->bottom;
                }
                while(t2)
                {
                    temp1->bottom = new Node(t2->data);
                    t2=t2->bottom;
                    temp1 = temp1->bottom;
                }
                
                temp->bottom = NULL;
                temp =temp->next;
                temp->bottom = headn->bottom;
            }
            
        }
        else if(!temp->bottom)
          temp = temp->next;
        else
        {
            while(temp)
            {
                temp->next = temp->bottom;
                temp->bottom = NULL;
                temp =temp->next;
            }
        }
    }
    temp =root;
    while(temp)
    {
        temp->bottom = temp->next;
        temp->next =NULL;
        temp = temp->bottom;
    }
    return root;
}

