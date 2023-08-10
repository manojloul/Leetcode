//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way
struct Node{
  public: int key;
  int val ;
  struct Node* next;
  struct Node* prev;
  
  Node(int k,int v)
  {
      key = k;
      val = v;
  }
  
};
class LRUCache
{
    private: 
    Node* head,* tail;
    public:
    int s = 0;
    map<int,Node*> mp;
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        head= new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = NULL;
        s= cap;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        if(mp.find(key)!=mp.end())
        {
            Node* tmp = mp[key];
            int ans = tmp->val;
            
            Node* p = tmp->prev;
            Node* nn= tmp->next;
            p->next = nn;
            nn->prev = p;
            
            tmp->next= head->next;
            head->next->prev = tmp;
            
            head->next = tmp;
            tmp->prev= head;
            
            return ans;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        if(mp.find(key)==mp.end())
        {
            Node * tmp = new Node(key,value);
            mp[key]=tmp;
            
            tmp->next = head->next;
            head->next->prev= tmp;
            
            head->next = tmp;
            tmp->prev = head;
            
            if(mp.size() > s)
            {
                tmp = tail->prev->prev;
                int k = tmp->next->key;
                tmp->next= tail;
                tail->prev=tmp;
                
                mp.erase(k);
            }
        
        }
        else
        {
            Node* tmp = mp[key];
            tmp->val = value;
            
            Node* p = tmp->prev;
            Node* nn= tmp->next;
            p->next = nn;
            nn->prev = p;
            
            tmp->next= head->next;
            head->next->prev = tmp;
            
            head->next = tmp;
            tmp->prev= head;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends