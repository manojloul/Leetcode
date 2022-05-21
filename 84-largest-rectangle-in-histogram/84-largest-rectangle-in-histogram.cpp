class Solution {
public:
    vector<int> v1,v2;
    void nsl(vector<int> &nums)
    {
        stack<int> st;
        
        for(int i=0;i<nums.size() ;++i)
        {
            if(st.empty())
                v2.push_back(-1);
            else
            {
                while(!st.empty() && nums[st.top()]>=nums[i])
                    st.pop();
                if(st.empty())
                    v2.push_back(-1);
                else
                    v2.push_back(st.top());
                
            }
            st.push(i);
        }
    }
    void nsr(vector<int> &nums)
    {
        int k=nums.size();
        stack<int> st;
        
        for(int i=k-1;i>=0 ;--i)
        {
            if(st.empty())
                v1.push_back(k);
            else
            {
                while(!st.empty() && nums[st.top()]>=nums[i])
                    st.pop();
                if(st.empty())
                    v1.push_back(k);
                else
                    v1.push_back(st.top());
                
            }
            st.push(i);
        }
        reverse(v1.begin(),v1.end());
    }
    int largestRectangleArea(vector<int>& heights) {
        nsl(heights);
        nsr(heights);
        vector<int> sol;
        int mx=0;
        for(int i=0;i<v1.size();++i)
        {
            sol.push_back(v1[i]-v2[i]-1);
            mx=max(mx,sol[i]*heights[i]);
        }
        return mx;
    }
};