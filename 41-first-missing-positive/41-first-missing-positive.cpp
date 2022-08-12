class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        
        for(int i=0;i<arr.size();++i)
        while(arr[i]>0 && arr[i]<=arr.size() &&arr[arr[i]-1]!=arr[i])
            swap(arr[i],arr[arr[i]-1]);
        
        for(int i=0;i<arr.size();++i)
            if(arr[i]!=i+1) return i+1;
        return arr.size()+1;
    
    }
};