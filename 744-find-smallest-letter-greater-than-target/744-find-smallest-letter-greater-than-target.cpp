class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i=0,j=letters.size()-1;
        int p=-1;
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            
            if(letters[mid]>target)
            {
                p=mid;
                j=mid-1;
            }
            else
                i=mid+1;
        }
        if(p==-1) return letters[0];
        else
        return letters[p];
    }
};