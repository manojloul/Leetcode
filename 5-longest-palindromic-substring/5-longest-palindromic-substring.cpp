class Solution {
public:
    pair<int,int> check(string s,int i,int j)
    {
        while(i>=0 && j<s.size() && s[i]==s[j])
        {
            i--;
            j++;
        }
        i++;
        j--;
        return {i,j};
    }
    string longestPalindrome(string s) {
        int left=0,right=0;
        
        for(int i=0;i<s.size();++i)
        {
            pair<int,int> p1=check(s,i,i);
            pair<int,int> p2=check(s,i,i+1);
            
            
            if(p1.second-p1.first+1>right-left+1)
            {
                right=p1.second;
                left=p1.first;
            }
            
            if(p2.second-p2.first+1>right-left+1)
            {
                right=p2.second;
                left=p2.first;
            }
            
        }
        return s.substr(left,right-left+1);
    }
};