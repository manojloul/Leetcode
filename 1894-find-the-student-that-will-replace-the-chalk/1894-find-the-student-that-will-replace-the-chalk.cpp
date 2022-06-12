class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int ans=0;
        for(int i=0;i<chalk.size();++i)
            ans+=chalk[i];
        
        ans=k%ans;
        
        for(int i=0;i<chalk.size();++i)
        {
            if(ans<chalk[i]) return i;
            ans-=chalk[i];
        }
        return -1;
    }
};