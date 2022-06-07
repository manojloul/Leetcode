class Solution {
public:
    string solve(string s1,string s2)
    {
        //cout<<s1<<" "<<s2<<" ";
        string ans="";
        int i=s1.size()-1,j=s2.size()-1;
        int carry=0;
        
        while(i>=0 && j>=0)
        {
            int sum=carry+(s1[i--]-48)+(s2[j--]-48);
            ans+=to_string(sum%10);
            carry=sum/10;
        }
        while(j>=0)
        {
            int sum=carry+(s2[j--]-48);
            ans+=to_string(sum%10);
            carry=sum/10;
        }
        while(i>=0)
        {
            int sum=carry+(s1[i--]-48);
            ans+=to_string(sum%10);
            carry=sum/10;
        }
        while(carry){
                ans+=to_string(carry%10);
                carry=carry/10;
            }
        
        reverse(ans.begin(),ans.end());
        //cout<<ans<<endl;
        return ans;
    }
    string multiply(string num1, string num2) {
        if(num2=="0" ||num1=="0") return "0";
        vector<string> v;
        int k=0;
        for(int j=num2.size()-1;j>=0;--j)
        {
            string s="";
            int carry=0;
            int n=num2[j]-48;
            for(int i=num1.size()-1;i>=0;--i)
            {
                int a=num1[i]-48;
                int sum=(a*n+carry);
                s+=to_string(sum%10);
                carry=sum/10;
            }
            while(carry){
                s+=to_string(carry%10);
                carry/=10;
            }
            reverse(s.begin(),s.end());
            
            for(int i=0;i<k;++i) s+='0';
            k++;
            //cout<<s<<endl;
            v.push_back(s);
        }
        string ans="";
        
        for(int i=0;i<v.size();++i)
        {
            ans=solve(ans,v[i]);
        }
        return ans;
    }
};