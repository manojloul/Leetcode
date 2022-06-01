class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i=0,j=arr.size()-1;
        
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                return mid;
            
            else if(arr[mid]>arr[mid-1])
            {
                i=mid+1;
                if(arr[i]>arr[mid] && arr[i]>arr[i+1])
                    return i;
            }
            else
            {
                j=mid-1;
                if(arr[j]>arr[mid] && arr[j]>arr[j-1])
                    return j;
            }
        }
        return -1;
    }
};