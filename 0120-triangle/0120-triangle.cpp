class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& triangle,
            vector<vector<int>>& dp) {
        
        int n = triangle.size();

        if (i == n - 1)
            return triangle[i][j];

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        int left = dfs(i + 1, j, triangle, dp);
        int right = dfs(i + 1, j + 1, triangle, dp);

        return dp[i][j] = triangle[i][j] + min(left, right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(
            n, vector<int>(n, INT_MAX)
        );

        return dfs(0, 0, triangle, dp);
    }
};