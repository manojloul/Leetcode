class Solution {
public:
    static bool cmp(pair<int,int> &p1,pair<int,int> &p2)
    {
        if(p1.second==p2.second)
            return p1.first<p2.first;
        return p1.second<p2.second;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>>pq;
        
        for(int i=0;i<arr.size();++i)
        {
            pq.push_back({arr[i],abs(arr[i]-x)});
        }
        
        sort(pq.begin(),pq.end(),cmp);
        int i=0;
        vector<int> ans;
        while(k--)
            ans.push_back(pq[i++].first);
        sort(ans.begin(),ans.end());
        return ans;
    }
};