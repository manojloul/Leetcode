class Solution {
public:
    int findTheWinner(int n, int k) {
        k-=1;
        vector<int> v;
        for(int i=0;i<n;++i)
            v.push_back(i+1);
        
        int i=0;
        while(v.size()>1 )
        {
            n=v.size();
            int p=(n+i+k)%n;
            v.erase(v.begin()+p);
            i=p;
        }
        return v[0]; 
    }
};