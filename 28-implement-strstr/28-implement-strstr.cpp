class Solution {
public:
    int strStr(string h, string n) {
        if(n.size()>h.size()) return -1;
        if(n.size()==0) return 0;
        int i=0,j=0;
        
        while(j<h.size())
        {
            if(h[j]==n[0])
            {
                int i=j,k=0;
                while(k<n.size() && i<h.size() &&h[i]==n[k])
                {
                    i++;
                    k++;
                }
                if(k==n.size()) return j;
            }
            j++;
        }
        return -1;
    }
};