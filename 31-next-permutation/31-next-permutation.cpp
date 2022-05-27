class Solution {
public:
    void nextPermutation(vector<int>& arr) {
         int i,j;

    for(i=arr.size()-2;i>=0 ;i--)
    {
        if(arr[i]<arr[i+1]) break;
    }
    if(i<0)
    {
         reverse(arr.begin(),arr.end());
    }
    else{
    for(j=arr.size()-1;j>i ;j--)
    {
        if(arr[j]>arr[i]) break;
    }

    swap(arr[i],arr[j]);

    reverse(arr.begin()+i+1,arr.end());
    }
    }
};