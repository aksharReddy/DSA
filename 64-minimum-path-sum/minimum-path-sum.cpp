class Solution {
public:
    // int f(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    //     // Out of bounds → return a large value (invalid path)
    //     if (r < 0 || c < 0) return 1e9;

    //     // Base case: starting cell
    //     if (r == 0 && c == 0) return grid[0][0];

    //     // If already computed, return from dp
    //     if (dp[r][c] != -1) return dp[r][c];

    //     // Recursive calls
    //     int up = grid[r][c] + f(r - 1, c, grid, dp);
    //     int left = grid[r][c] + f(r, c - 1, grid, dp);

    //     // Store result in dp and return
    //     return dp[r][c] = min(up, left);
    // }

    int minPathSum(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        // vector<vector<int>> dp(n, vector<int>(m, -1)); // memo table
        // return f(n - 1, m - 1, grid, dp);
         vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (i == 0 && j == 0) {
                dp[i][j] = a[i][j]; // base case: starting cell
            } 
            else {
                int up = INT_MAX, left = INT_MAX;

                // If coming from top is valid
                if (i > 0) up = a[i][j] + dp[i - 1][j];

                // If coming from left is valid
                if (j > 0) left = a[i][j] + dp[i][j - 1];

                // Choose the minimum path sum
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n - 1][m - 1]; 
    }
};
