class SummaryRanges {
public:set<int> st;
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        st.insert(val);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        int p=-1,c=-1;
        for(auto it: st)
        {
            if(c==-1)
            {
                p=it;
                c=it;
            }
            else
            {
                if(it==c+1)
                    c=it;
                else
                {
                    ans.push_back({p,c});
                    p=it;
                    c=it;
                }
            }
            
        }
        if(c!=-1)
        ans.push_back({p,c});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */