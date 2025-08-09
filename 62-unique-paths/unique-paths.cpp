class Solution {
public:

    int noofpaths(int i,int j,int m,int n, vector<vector<int>>&dp){
        if(i==m-1 && j ==n-1 ) return 1;
        if(i>=m || j>=n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        else return dp[i][j]= noofpaths(i+1,j,m,n,dp) + noofpaths(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return noofpaths(0,0,m,n,dp);
    }

    // can use m+n-2Cm-1 as m-1 and n-1 moves are to be made to reach final state
};