class Solution {
public:
    int nextGreaterElement(int n) {
       vector<int> v;
        while(n)
        {
            v.push_back(n%10);
            n/=10;
        }
        reverse(v.begin(),v.end());
        
        int i=v.size()-2;
        while(i>=0)
        {
            if(v[i]<v[i+1]) break;
            i--;
        }
        if(i<0) return -1;
        int j=v.size()-1;
        while(j>i)
        {
            if(v[j]>v[i]) break;
            j--;
        }
        swap(v[i],v[j]);
        reverse(v.begin()+i+1,v.end());
        long long int m=0;
        for(int i=0;i<v.size();++i)
            m=m*10+v[i];
        if(m>INT_MAX) return -1;
        return m;
    }
};