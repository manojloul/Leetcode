class Solution {
public:
    int minPartitions(string n) {
        int k=0;
        for(int i=0;i<n.size();++i)
        {
            k=max(k,n[i]-48);
        }
        return k;
    }
};