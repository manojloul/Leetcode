class Solution {
public:
    int solve(int n)
    {
        int sum=0;
        while(n)
        {
            sum+=(n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        while(n>10)
        {
            n=solve(n);
        }
        if(n==1 ||n==10 || n==7) return true;
        return false;
    }
};