class Solution {
public:
    int nge(vector<int> nums,int i)
    {
        stack<int> st;
        //cout<<i<<endl;
        for(int j=nums.size()-1;j>=i;--j)
        {
             while(!st.empty() && st.top()<nums[j])
                 st.pop();
            if(st.empty() && i==j)
                return -1;
            if(i==j) break;
            st.push(nums[j]);
        }
        return st.top();
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums2.size();++i)
            mp[nums2[i]]=i;
        
        vector<int> ans;
        for(int i=0;i<nums1.size();++i)
        {
            int  k=nge(nums2,mp[nums1[i]]);
            ans.push_back(k);
        }
        return ans;
    }
};