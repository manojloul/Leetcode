class Solution {
public:map<int,vector<int>> mp;
    void solve(int n)
    {
        int c=0;
        int k=n;
        while(n)
        {
            n=n&n-1;
            c++;
        }
        mp[c].push_back(k);
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();++i)
            solve(arr[i]);
        
        vector<int> ans;
        for(auto it:mp)
        {
            for(auto i:it.second)
                ans.push_back(i);
        }
        return ans;
    }
};