class MinStack {
public: vector<int> v;
    MinStack() {
        
    }
    
    void push(int val) {
        v.push_back(val);
    }
    
    void pop() {
        if(v.size()==0)
            return ;
        v.pop_back();
    }
    
    int top() {
        if(v.size()==0)
            return -1;
        int k=v[v.size()-1];
        return k;
    }
    
    int getMin() {
        if(v.size()==0)
            return -1;
        int mn=INT_MAX;
        for(int i=0;i<v.size();++i)
            mn=min(mn,v[i]);
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */