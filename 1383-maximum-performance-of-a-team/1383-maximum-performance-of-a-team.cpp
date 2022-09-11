class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> vp(n);
        for(int i=0;i<n;i++)
        {
            vp[i]={efficiency[i],speed[i]};
        }
        
        sort(rbegin(vp),rend(vp));
        
        priority_queue<int,vector<int>,greater<int>> pq; 
        long sum=0;
        long  res=0;
        for(auto [eff,speed] : vp)
        {
            sum+=speed;
            pq.push(speed);
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            res=max(res,sum*eff);
        }
        return res % (int)(1e9+7);
    }
};