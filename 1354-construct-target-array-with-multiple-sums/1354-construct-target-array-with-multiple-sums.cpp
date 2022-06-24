class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        if(target.size()==1) {
            if(target[0]==1) return true;
            return false;
        }
        
        long int sum=0;
        priority_queue<int> pq;
        for(int i=0;i<target.size();++i)
        {
            sum+=target[i];
            pq.push(target[i]);
        }
        
        int n=target.size();
        while(pq.top()>1 && sum>=n)
        {
            long int k=pq.top();
            pq.pop();
            long int s=pq.top();
            
            long int new_sum=sum-k;
            long int l=max(1l,(k-s)/new_sum);
            
            k-=new_sum*l;
            pq.push(k);
            if(k<1) return false;
            sum=new_sum+k;
            
        }
        if(pq.top()>1) return false;
        return true;
    }
};