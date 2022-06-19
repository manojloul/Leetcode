class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int f=0;
        while(left!=right)
        {
            left>>=1;
            right>>=1;
            f++;
        }
        return left<<f;
    }
};