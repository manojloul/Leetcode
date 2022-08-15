class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='I')
            {
                if(i+1<s.size())
                {
                    if(s[i+1]=='V')
                    {
                        ans+=4;
                        i++;
                    }
                    else if(s[i+1]=='X')
                    {
                        ans+=9;
                        i++;
                    }
                    else
                        ans+=1;
                }
                else
                    ans+=1;
            }
            else if(s[i]=='V')
            {
                ans+=5;
            }
            else if(s[i]=='X')
            {
                if(i+1<s.size())
                {
                    if(s[i+1]=='L')
                    {
                        i++;
                        ans+=40;
                    }
                    else if(s[i+1]=='C')
                    {
                        i++;
                        ans+=90;
                    }
                    else
                        ans+=10;
                }
                else
                    ans+=10;
            }
            else if(s[i]=='L')
            {
                ans+=50;
            }
            else if(s[i]=='C')
            {
                if(i+1<s.size())
                {
                    if(s[i+1]=='D')
                    {
                        i++;
                        ans+=400;
                    }
                    else if(s[i+1]=='M')
                    {
                        i++;
                        ans+=900;
                    }
                    else
                        ans+=100;
                }
                else
                    ans+=100;
            }
            else if(s[i]=='D')
            {
                ans+=500;
            }
            else if(s[i]=='M')
            {
                ans+=1000;
            }
        }
        return ans;
    }
};