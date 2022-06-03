class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_map<long int,long int> mp;
        int k=sqrt(c);
        for(int i=0;i<=k;++i)
        {
            if((long)2*i*i==c) return true;
            if(mp.find(c-(i*i))!=mp.end())
                return true;
            mp[i*i]++;
        }
        return false;
    }
};