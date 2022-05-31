class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while(n>26)
        {
            int m=n%26;
            
            if(m==0)
            {
                s.push_back('Z');
                m=26;
            }
            else
                s.push_back(64+m);
            
            n=(n-m)/26;
        }
        if(n>0)
            s.push_back(64+n);
        
        
        reverse(s.begin(),s.end());
        return  s;
    }
};