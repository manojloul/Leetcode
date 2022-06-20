class Solution {
public:
    void dfs (vector<vector<int>>& isC , int i, vector<bool>& visi ) {
        if( visi[i] ) return;
        visi[i]=1;
        for ( int j = 0; j<isC[i].size(); j++) {
            if( isC[i][j] && !visi[j] ){
                dfs (isC , j , visi);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size(), m = isConnected[0].size();
        int count=0;
        vector<bool> visi(n,0);
        for( int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if( isConnected[i][j] && !visi[i] ){
                    dfs (isConnected , i , visi);
                    dfs (isConnected , j , visi);
                    count++;
                }
            }
        }
        return count;
    }
};