class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f=0,d=0;
        
        for(int i=0;i<bills.size();++i)
        {
            if(bills[i]==20)
            {
                if(d && f)
                {
                    d--;
                    f--;
                }
                else if(f>=3)
                {
                    f-=3;
                }
                else return false;
            }
            else if(bills[i]==10)
            {
                if(f) f--;
                else return false;
                d++;
            }
            else
                f++;
        }
        return true;
    }
};