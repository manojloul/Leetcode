class Solution {
public:
// static bool cmp(pair<int,pair<string,string>> &p1,pair<int,pair<string,string>> &p2)
// {
//     if(p1.first==p2.first)
//     {
        
//     }
//     else
//         return p1.first>p2.first;
// }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int> mp;
        // map<string,string> sol;
        for(int i=0;i<senders.size();++i)
        {
            string s=messages[i];
            int count=0;
            for(int j=0;j<s.size();++j)
            {
                if(s[j]==' ') count++;
            }
            mp[senders[i]]+=count+1;
            // if(sol.find(senders[i])!=sol.end())
            //     sol[senders[i]]=messages[i];
            // else
            // {
            //     string temp=sol[senders[i]];
            //     if(temp+messages[i]<messages[i]+temp)
            //         sol[senders[i]]=temp+messages[i];
            //     else
            //         sol[senders[i]]=messages[i]+temp;
            // }
        }
       
        string ans="";
        int mx=INT_MIN;
        
        for(auto it:mp)
        {
            if(it.second>mx)
            {
                mx=it.second;
                ans=it.first;
            }
            else if(it.second==mx)
            {
                ans=max(ans,it.first);
            }
        }
        return ans;
        
    }
};