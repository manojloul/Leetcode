bool static cmp(const vector<int>& a, vector<int>& b)
{
    return a[1] < b[1];
}
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& arr) {
         if(arr.size() <= 0) return 0;
        sort(arr.begin(), arr.end(), cmp); {
            
        priority_queue<int> q;
        int sum = 0;
        for(auto i : arr) {
            sum += i[0];
            q.push(i[0]);
            if(sum > i[1]) {
                sum -= q.top();
                q.pop();
            }
        }
        return q.size();
    }
    }
};