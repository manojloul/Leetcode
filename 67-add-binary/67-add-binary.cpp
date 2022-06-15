class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int carry=0;
        
        int i=a.size()-1,j=b.size()-1;
        
        while(i>=0 && j>=0)
        {
            int sum=a[i--]-48+b[j--]-48+carry;
            ans+=to_string(sum%2);
            carry=sum/2;
        }
        while(i>=0)
        {
            int sum=a[i--]-48+carry;
            ans+=to_string(sum%2);
            carry=sum/2;
        }
        while(j>=0)
        {
            int sum=b[j--]-48+carry;
            ans+=to_string(sum%2);
            carry=sum/2;
        }
        while(carry)
        {
            ans+=to_string(carry%2);
            carry/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};