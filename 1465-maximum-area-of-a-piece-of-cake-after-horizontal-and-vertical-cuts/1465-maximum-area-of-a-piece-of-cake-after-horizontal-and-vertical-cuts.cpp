class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        int x=hc[0],y=vc[0];
        hc.push_back(h);
        vc.push_back(w);
        for(int i=1;i<hc.size();++i)
        {
            x=max(x,hc[i]-hc[i-1]);
        }
        for(int i=1;i<vc.size();++i)
        {
            y=max(y,vc[i]-vc[i-1]);
        }
        int mod=1e9+7;
        return ((long)x*(long)y)%mod;
    }
};