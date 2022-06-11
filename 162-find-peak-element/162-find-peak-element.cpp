class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int i=0,j=arr.size()-1;
        int n=arr.size();
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            int l=(n+mid-1)%n;
            int r=(n+mid+1)%n;
            if(arr[mid]>=arr[l] && arr[mid]>=arr[r]) return mid;
            else
            {
                if(mid-1<0) i=mid+1;
                else if(mid+1>=n) j=mid-1;
                else{
                if(arr[mid+1]>arr[mid-1])
                {
                    i=mid+1;
                }
                else
                    j=mid-1;
                }
            }
        }
        
        return -1;
    }
};