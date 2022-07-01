class Solution {
public:
    void sortColors(vector<int>& arr) {
         int l=0,r=arr.size()-1;
    
    int i=0;
    while(i<=r)
    {
        if(arr[i]==1) i++;
        else
        {
            if(arr[i]==0)
            {
                swap(arr[i],arr[l]);
                if(i==l) i++;
                l++;
            }
            else
            {
                swap(arr[i],arr[r]);
                if(i==r) i++;
                r--;
            }
        }
    }
    }
};