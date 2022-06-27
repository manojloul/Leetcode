class Solution {
public: 
    int reinitializePermutation(int n) {
        vector<int> v,t;
        int count=1;
        for(int i=0;i<n;++i)
             v.push_back(i);
        for(int i=0;i<n;++i)
        {
            if(i%2==0)
                t.push_back(v[i/2]);
            else
                t.push_back(v[n/2+(i-1)/2]);
        }
        
        while(t!=v)
        {
            count++;
            vector<int> p;
            for(int i=0;i<n;++i)
            {
                if(i%2==0)
                p.push_back(t[i/2]);
            else
                p.push_back(t[n/2+(i-1)/2]);
            }
            t=p;
          
        }
       
        
        return count;
    }
};