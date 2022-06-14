class Solution {
public:
    bool isvalid(vector<int> &pos,int m,int mid)
    {
        int mt=2;
        int p=pos[0],n=pos[pos.size()-1];
        for(int i=1;i<pos.size()-1;++i)
        {
            if(pos[i]-p>=mid && n-pos[i]>=mid)
            {
                mt++;
                p=pos[i];
            }
        }
        if(mt>=m)return true;
        return false;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());
        if(pos.size()==2) return pos[1]-pos[0];
        int n=pos.size();
        if(m==2) return pos[n-1]-pos[0];
        
        int force=0;
        int left=0,right=pos[n-1]-pos[0];
        
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(isvalid(pos,m,mid))
            {
                force=mid;
                left=mid+1;
            }
            else
                right=mid-1;
        }
        return force;
        
    }
};