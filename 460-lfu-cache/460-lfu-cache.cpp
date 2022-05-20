class LFUCache {
public:
    struct Node{
        int key;
        int val;
        int count=1;
        Node* next;
        Node* prev;
        Node():val(0),key(0),next(nullptr),prev(NULL){}
        Node(int k,int v):val(v),key(k),next(nullptr),prev(nullptr){}
    };
    
    Node* head=new Node();
    Node* tail=new Node();
    
    int s=0;
    unordered_map<int,Node*> mp;
    
    LFUCache(int capacity) {
        s=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        int k=mp[key]->val;
        mp[key]->count++;
        
        Node* t=mp[key];
        while(t->count>=t->prev->count && t->prev!=head)
        {
            Node* pr=t->prev;
            pr->next=t->next;
            t->next->prev=pr;
            
            pr->prev->next=t;
            t->prev=pr->prev;
            
            t->next=pr;
            pr->prev=t;
        }
        
        return k;
        
    }
    
    void put(int key, int value) {
        if(s==0) return ;
        if(mp.find(key)!=mp.end())
        {
            mp[key]->val=value;
            mp[key]->count+=1;
            Node* t=mp[key];
            while(t->count>=t->prev->count && t->prev!=head)
            {
                Node* pr=t->prev;
                pr->next=t->next;
                t->next->prev=pr;

                pr->prev->next=t;
                t->prev=pr->prev;

                t->next=pr;
                pr->prev=t;
            }
            
            return;
        }
        Node* temp=new Node(key,value);
        if(mp.size()>=s)
        {
            Node* t=tail->prev;
            t->prev->next=tail;
            tail->prev=t->prev;
             mp.erase(t->key);
        }
       
            Node* t=head;
            while(t->next->count>temp->count)
            {
                t=t->next;
            }
            
            temp->next=t->next;
            t->next->prev=temp;
            
            t->next=temp;
            temp->prev=t;
            
            mp[key]=temp;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */