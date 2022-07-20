class Solution {
public:
//     void check(string s,unordered_map<string,int> &mp,int pos,string &str)
//     {
//         if(pos==s.size())
//         {
//             if(mp.find(str)!=mp.end())
//             {
//                 mp.erase(str);
//             }
//             return;
//         }
//         if(pos>=s.size())
//             return;
        
//         str+=s[pos];
//         check(s,mp,pos+1,str);
//         str.pop_back();
//         check(s,mp,pos+1,str);
//     }
    int numMatchingSubseq(string s, vector<string>& words) {
//         unordered_map<string,int> mp;
//         int count=words.size();
//         for(int i=0;i<words.size();++i)
//         {
//             mp[words[i]]++;
//         }
        
//         string str="";
//         check(s,mp,0,str);
        
//         int k=0;
//         for(auto it:mp)
//         {
//             k+=it.second;
//         }
//         return count-k;
       
        int ans = 0;
        int l1 = s.length(); 
        map<string,int> m;  
        for (auto word: words){
            int l2 = word.length();
            int j = 0;
            if (m.find(word)==m.end()){ 
               for (int i=0;i<l1 && j<l2;i++){   
                    if (s[i]==word[j]){
                        j++;
                    }
                }
                ans+=(j==l2); 
                m[word] = (j==l2);
            }
            else{
                ans+= m[word]; 
            }
            
            
        }
        return ans;
  
    }
};