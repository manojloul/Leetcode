class MyCircularQueue {
public:int len=0;
    struct manu {
      int val;
      manu *next;
      manu() : val(0), next(nullptr) {}
      manu(int x) : val(x), next(nullptr) {}
      manu(int x, manu *next) : val(x), next(next) {}
    };
    struct manu* head=NULL;
    struct manu* tail=NULL;
    int k1=0;
    MyCircularQueue(int k) {
       k1=k; 
    }
    
    bool enQueue(int value) {
        if(len>=k1) return false;
        if(head==NULL)
        {
            manu* m=new manu(value);
            head=m;
            tail=m;
            len++;
        }
        else
        {
           manu* m=new manu(value);
            tail->next=m;
            tail=tail->next;
            len++;
        }
        //cout<<head->val<<" "<<tail->val<<endl;
        return true;
    }
    
    bool deQueue() {
        //cout<<len<<endl;
        if(head==NULL || len==0)
            return false;
        //cout<<"head "<<head->val<<endl;
        head=head->next;
        len--;
        return true;
    }
    
    int Front() {
        if(head==NULL || len==0)
            return -1;
        return head->val;
    }
    
    int Rear() {
        if(tail==NULL || len==0)
            return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        if(tail==NULL ||len==0)
            return true;
        return false;
    }
    
    bool isFull() {
        if(len>=k1)
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */