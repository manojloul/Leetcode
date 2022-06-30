class MyCalendar {
public:vector<pair<int,int>> vp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        for(int i=0;i<vp.size();++i)
        {
            int s=vp[i].first;
            int e=vp[i].second;
            
            if((start>=e)||(end<=s))
            {
                continue;
            }
            else return false;
        }
      
        vp.push_back({start,end});
        return true;
       
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */