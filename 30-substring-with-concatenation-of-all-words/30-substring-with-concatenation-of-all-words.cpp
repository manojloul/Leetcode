class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> mp,m;
        
        for(int i=0;i<words.size();++i)
            mp[words[i]]++;
        
        int len=words[0].size();
        int l=words.size();
        int wl=l*len;
        vector<int> v;
        
        for(int i=0;i<s.size()-wl+1;++i)
        {
            
            for(int j=i;j<i+wl;j+=len)
            {
                string temp=s.substr(j,len);
                //cout<<temp<<" ";
                m[temp]++;
            }
            //cout<<endl;
            bool f=true;
            
            for(auto it:mp)
            {
                if(mp[it.first]!=m[it.first])
                {
                    f=false;
                    break;
                }
            }
            if(f)
                v.push_back(i);
            
            m.clear();
        }
//         while(i<s.size()-len+1)
//         {
//             string temp=s.substr(i,len);
//             cout<<temp<<" ";
//             if(mp.find(temp)!=mp.end())
//             {
//                 mp[temp]--;
//                 if(mp[temp]==0)
//                     count--;
//             }
         
//             cout<<i-j+len<<" "<<count<<endl;
//             if(i-j+len==wl)
//             {
//                 if(count==0)
//                     v.push_back(j);
                
//                 string st=s.substr(j,len);
//                 //cout<<endl;
//                // cout<<"1  "<<count<<" "<<st<<endl;
//                 if(mp.find(st)!=mp.end())
//                 {
//                     if(mp[st]==0)
//                         count++;
//                     mp[st]++;
                    
//                 }
//                 j+=1;
//             }
//                i+=1;
//         }
        return v;
    }
};