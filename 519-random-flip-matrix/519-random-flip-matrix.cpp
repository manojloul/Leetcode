class Solution {
public:
    int m=0,n=0;
    unordered_map<int,unordered_map<int,int>> mp;
    Solution(int m1, int n1) {
        m=m1;
        n=n1;
    }
    
    vector<int> flip() {
        int i=rand()%m;
        int j=rand()%n;
        while(mp[i][j])
        {
            i=rand()%m;
            j=rand()%n;
        }
        mp[i][j]=1;
        return {i,j};
    }
    
    void reset() {
        mp.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */