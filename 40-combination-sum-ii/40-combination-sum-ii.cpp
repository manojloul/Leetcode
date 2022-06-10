class Solution {
public:vector<vector<int>> ans;
    void solve(vector<int> &can,int &tar,int i,int &sum,vector<int> &v)
    {
       
       if(sum==tar)
       {
             ans.push_back(v);
            return;
        }
        if(sum>tar)
            return;
        
        
        for(int pos=i;pos<can.size();++pos)
        {
            v.push_back(can[pos]);
            sum+=can[pos];
            solve(can,tar,pos+1,sum,v);
            sum-=can[pos];
            v.pop_back();
            
            while(pos+1<can.size() && can[pos]==can[pos+1])
                pos++;
        }
    
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
       vector<int> v;
        int sum=0;
        sort(can.begin(),can.end());
        solve(can,target,0,sum,v);
        return ans;
    }
};