class Solution {
public:
    bool static cmp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        
        for(int i=0;i<people.size();++i)
        {
            int j=i,p=i;
            while(people[p][1]!=j && j>=0)
            {
                swap(people[p],people[p-1]);
                j--;
                p--;
            }
        }
        return people;
    }
};