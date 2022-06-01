class Solution {
public:
    int subtractProductAndSum(int n) {
        long pro=1,sum=0;
        
        while(n)
        {
            int k=n%10;
            pro*=k;
            sum+=k;
            n/=10;
        }
        return pro-sum;
    }
};