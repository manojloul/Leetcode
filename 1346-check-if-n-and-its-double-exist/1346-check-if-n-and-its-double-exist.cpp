class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();++i)
        {
            if(mp.find(2*arr[i])!=mp.end()) return true;
            mp[arr[i]]++;
        }
        mp.clear();
        for(int i=arr.size()-1;i>=0;--i)
        {
            if(mp.find(2*arr[i])!=mp.end()) return true;
            mp[arr[i]]++;
        }
        return false;
    }
};