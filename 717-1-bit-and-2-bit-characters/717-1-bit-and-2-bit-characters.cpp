class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.size()==1) return true;
        int i=bits.size()-2;
        if(bits[i]==0) return true;
        
        for(int j=0;j<bits.size();++j)
        {
            if(j==bits.size()-1) return true;
            if(bits[j]==1)
                j+=1;
            
        }
        return false;
    }
};