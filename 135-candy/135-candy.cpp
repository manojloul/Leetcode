class Solution {
public:
    int candy(vector<int>& r) {
        int ans=0;
        int n=r.size();
        if(n==1) return 1;
        vector<int> v(n,0);
        if(r[0]<=r[1])
            v[0]=1;
        if(r[n-1]<=r[n-2])
            v[n-1]=1;
        
       
        for(int i=1;i<n-1;++i)
        {
            if(r[i]<=r[i-1] && r[i]<=r[i+1])
                v[i]=1;
        }
        
        for(int i=1;i<n;++i)
        {
            if(v[i]!=0) continue;
            if(r[i]>r[i-1])
            {
                v[i]=v[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;--i)
        {
            if(v[i]!=0) continue;
            if(r[i]>r[i+1])
                v[i]=v[i+1]+1;  
        }
        
        for(int i=1;i<n-1;++i)
        {
            if(r[i]>r[i-1] && r[i]>r[i+1])
            {
                v[i]=max(v[i-1],v[i+1])+1;
            }
        }
        for(int i=0;i<n;++i)
        {
            ans+=v[i];
        }
        return ans;
    }
};