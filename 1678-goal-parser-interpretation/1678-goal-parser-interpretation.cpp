class Solution {
public:
    string interpret(string cmd) {
        string ans="";
        
        for(int i=0;i<cmd.size();++i)
        {
            if(cmd[i]=='(')
            {
                int j=i+1;
                while(cmd[j]!=')')
                    j++;
                if(j-i+1>2) ans+="al";
                else ans+='o';
                i=j;
            }
            else
                ans+='G';
        }
        return ans;
    }
};