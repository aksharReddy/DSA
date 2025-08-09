class Solution {
public:

    // int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
    //     int n = matrix.size();
    //     if(i<0 || i>=n || j<0 || j>=n) return 1e9;
    //     if(i == 0) return matrix[i][j];
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int up = matrix[i][j]+f(i-1,j,matrix,dp);
    //     int ld = matrix[i][j]+f(i-1,j-1,matrix,dp);
    //     int rg = matrix[i][j]+f(i-1,j+1,matrix,dp);

    //     return dp[i][j] = min(up,min(ld,rg));
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
          for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Fill DP table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = matrix[i][j] + dp[i - 1][j];

                int ld = INT_MAX;
                if (j > 0) {
                    ld = matrix[i][j] + dp[i - 1][j - 1];
                }

                int rd = INT_MAX;
                if (j < n - 1) {
                    rd = matrix[i][j] + dp[i - 1][j + 1];
                }

                dp[i][j] = min(up, min(ld, rd));
            }
        }

        // Answer = min value in last row
        int mini = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (dp[n - 1][j] < mini) {
                mini = dp[n - 1][j];
            }
        }
        return mini;
    }
};