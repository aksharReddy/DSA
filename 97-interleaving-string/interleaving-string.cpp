class Solution {
public:
    bool f(int i, int j, int k, int n, int m, int b, string &s1, string &s2, string &s3, vector<vector<int>>&dp) {
        if(i == n && j == m && k == b) return true;  // reached end of all strings
        if(dp[i][j] != -1) return dp[i][j];          // memoization
        
        bool ans = false;
        if(i < n && s1[i] == s3[k]) {
            ans = ans || f(i+1, j, k+1, n, m, b, s1, s2, s3, dp);
        }
        if(j < m && s2[j] == s3[k]) {
            ans = ans || f(i, j+1, k+1, n, m, b, s1, s2, s3, dp);
        }
        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), b = s3.size();
        if(n + m != b) return false;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(0, 0, 0, n, m, b, s1, s2, s3, dp);
    }
};
