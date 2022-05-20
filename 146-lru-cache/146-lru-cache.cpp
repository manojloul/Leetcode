class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node* next;
        Node* prev;
        Node():val(0),key(0),next(nullptr),prev(NULL){}
        Node(int k,int v):val(v),key(k),next(nullptr),prev(nullptr){}
    };
    
    Node* head=new Node();
    Node* tail=new Node();
    
    int s=0;
    unordered_map<int,Node*> mp;
    
    LRUCache(int capacity) {
        s=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        int k=mp[key]->val;
        
        Node* t=mp[key];
        Node* pr=t->prev;
        pr->next=t->next;
        t->next->prev=pr;
        
        pr=head->next;
        head->next=t;
        t->prev=head;
        
        t->next=pr;
        pr->prev=t;
        
        return k;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            mp[key]->val=value;
            
            Node* t=mp[key];
            Node* pr=t->prev;
            pr->next=t->next;
            t->next->prev=pr;

            pr=head->next;
            head->next=t;
            t->prev=head;

            t->next=pr;
            pr->prev=t;
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
       
            Node* tp=head->next;
            head->next=temp;
            temp->prev=head;
            
            temp->next=tp;
            tp->prev=temp;
        mp[key]=temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */