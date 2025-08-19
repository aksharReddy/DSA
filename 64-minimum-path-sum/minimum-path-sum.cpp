class Solution {
public:
    int f(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        // Out of bounds → return a large value (invalid path)
        if (r < 0 || c < 0) return 1e9;

        // Base case: starting cell
        if (r == 0 && c == 0) return grid[0][0];

        // If already computed, return from dp
        if (dp[r][c] != -1) return dp[r][c];

        // Recursive calls
        int up = grid[r][c] + f(r - 1, c, grid, dp);
        int left = grid[r][c] + f(r, c - 1, grid, dp);

        // Store result in dp and return
        return dp[r][c] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1)); // memo table
        return f(n - 1, m - 1, grid, dp);
    }
};
