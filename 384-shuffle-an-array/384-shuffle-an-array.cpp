class Solution {
public:vector<int> o,p;
    Solution(vector<int>& nums) {
        o=nums;
        p=nums;
    }
    
    vector<int> reset() {
        return o;
    }
    
    vector<int> shuffle() {
        next_permutation(p.begin(),p.end());
        return p;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */