class MyCircularDeque {
public:int size=0;
    struct manu{
        int val;
        manu *next;
        manu *prev;
        manu():val(0),next(nullptr),prev(nullptr){}
        manu(int x):val(x),next(nullptr),prev(nullptr){}
        manu(int x,manu *t):val(x),next(t),prev(t){};
    };
    int len=0;
    struct manu* head=NULL;
    struct manu* tail=NULL;
    MyCircularDeque(int k) {
        size=k;
    }
    
    bool insertFront(int value) {
        if(len>=size)
            return false;
        if(head==NULL){
            manu* temp=new manu(value);
            head=temp;
            tail=temp;
            len++;
        }
        else
        {
            manu* temp=new manu(value);
            temp->next=head;
            head->prev=temp;
            head=temp;
            len++;
        }
        return true;
    }
    
    bool insertLast(int value) {
        if(len>=size) return false;
        if(head==NULL){
            manu* temp=new manu(value);
            head=temp;
            tail=temp;
            len++;
        }
        else
        {
            manu* temp=new manu(value);
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
            len++;
        }
        return true;
    }
    
    bool deleteFront() {
        if(head==NULL || len==0)
            return false;
        if(head->next==NULL)
        {
            len--;
            head=NULL;
            tail=NULL;
            return true;
        }
        manu* t=head;
        head=head->next;
        head->prev=NULL;
        t->next=NULL;
        len--;
        return true;
    }
    
    bool deleteLast() {
        if(head==NULL || len==0)
            return false;
        if(tail->prev==NULL)
        {
            len--;
            tail=NULL;
            head=NULL;
            return true;
        }
        manu* t=tail;
        tail=tail->prev;
        tail->next=NULL;
        t->prev=NULL;
        len--;
        return true;
    }
    
    int getFront() {
        if(head==NULL ||len==0)
            return -1;
        return head->val;
    }
    
    int getRear() {
        if(tail==NULL || len==0)
            return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        if(head==NULL || len==0)
            return true;
        return false;
    }
    
    bool isFull() {
        if(len>=size)
            return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */