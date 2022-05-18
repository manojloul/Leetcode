class FrontMiddleBackQueue {
public:vector<int> v;
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        v.insert(v.begin(),val);
    }
    
    void pushMiddle(int val) {
        int s=v.size();
        v.insert(v.begin()+(s/2),val);
    }
    
    void pushBack(int val) {
        v.push_back(val);
    }
    
    int popFront() {
        if(v.size()==0) return -1;
        int k=v[0];
        v.erase(v.begin());
        return k;
    }
    
    
    int popMiddle() {
        if(v.size()==0) return -1;
        int k=v[(v.size()-1)/2];
        v.erase(v.begin()+(v.size()-1)/2);
        return k;
    }
    
    int popBack() {
        if(v.size()==0) return -1;
        int k=v[v.size()-1];
        v.erase(v.begin()+v.size()-1);
        return k;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */