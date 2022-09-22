class Solution {
public:
    string reverseWords(string s) {
        string str="";
        
       
         
        string temp="";
        for(int i=0;i<s.size();++i)
        {
            if(s[i]==' ')
            {
               reverse(temp.begin(),temp.end());
                str+=temp;
                str+=" ";
                temp.clear();
            }
            else
                temp+=s[i];
        }
        reverse(temp.begin(),temp.end());
        str+=temp;
        return str;
    }
};