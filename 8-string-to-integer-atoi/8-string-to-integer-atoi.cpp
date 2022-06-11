class Solution {
public:
    int myAtoi(string s) {
        long int ans=0;
        int p=1;
        bool ch=true;
        int f=0;
        for(int i=0;i<s.size();++i)
        {
            if(f>=2) break;
            if(s[i]==' ' && !ch)
                break;
            if(s[i]==' ' )
                continue;
            if((s[i]=='-' || s[i]=='+' )&& ch)
            {
                ch=false;
                f++;
                if(s[i]=='-')
                p=-1;
                continue;
            }
            if(s[i]>='0' && s[i]<='9')
            {
                ch=false;
                ans=(long long)ans*10+s[i]-48;
                
                if(ans>2147483647) {
                    if(p==1) return 2147483647;
                    else return -2147483648;
                }
            }
            else
                break;
            
        }
        return p*ans;
    }
};