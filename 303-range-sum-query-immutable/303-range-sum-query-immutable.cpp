class NumArray {
public:vector<int> arr,p;
    NumArray(vector<int>& nums) {
        p=nums;
        arr.push_back(nums[0]);
        for(int i=1;i<nums.size();++i)
        {
            arr.push_back(arr[i-1]+nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        return arr[right]-arr[left]+p[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */