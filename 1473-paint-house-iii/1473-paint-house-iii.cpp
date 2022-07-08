class Solution {
public:
     long long solve(int index, int prev, int count, vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target, vector<vector<vector<int>>> &dp) {
        if (count > target) return INT_MAX;
        
        if (index == m) return count == target ? 0 : INT_MAX; 
        
        if (dp[index][prev][count] != -1) return dp[index][prev][count];
        
        long long ans = INT_MAX;
        int newCount = count;
        
        if (houses[index]) {
            if (houses[index] != prev) newCount++;
            ans = min(ans, solve(index + 1, houses[index], newCount, houses, cost, m, n, target, dp));
        }
        else {
            for (int i = 1; i <= n; i++) {
                newCount = count + (prev != i);
                ans = min(ans, solve(index + 1, i, newCount, houses, cost, m, n, target, dp) + cost[index][i - 1]);
            }
        }
        
        return dp[index][prev][count] = ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        if (target > houses.size()) return -1;
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(target + 1, -1)));
        int ans = solve(0, 0, 0, houses, cost, m, n, target, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};