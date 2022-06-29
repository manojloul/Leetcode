class AuthenticationManager {
public:int t=0;unordered_map<string,int> mp;
    AuthenticationManager(int timeToLive) {
        t=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        if(mp.find(tokenId)==mp.end())
            mp[tokenId]=currentTime+t;
    }
    
    void renew(string tokenId, int currentTime) {
        if(mp.find(tokenId)!=mp.end())
        {
            if(mp[tokenId]>currentTime)
                mp[tokenId]=currentTime+t;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int c=0;
        for(auto it:mp)
        {
            if(it.second>currentTime)
                c++;
        }
        
        return c;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */