class Solution {
public:
    // int f(int r,int c,vector<vector<int>>&a,vector<vector<int>>&dp){

    //     if(r<0 || c<0) return 0;
    //     if(a[r][c]==1) return 0;
    //     if(r==0 && c==0) return 1;
    //     if(dp[r][c]!=-1) return dp[r][c];
    //     int up = 0;
    //     if( r-1>=0 && a[r-1][c]!=1 ) up = f(r-1,c,a,dp);
    //     int left = 0;
    //     if( c-1>=0 && a[r][c-1]!=1) left = f(r,c-1,a,dp);
    //     return dp[r][c]=up+left;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int  n = a.size();
        int  m = a[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return f(n-1,m-1,a,dp);
        vector<vector<int>>dp(n,vector<int>(m,0));

          for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) {
                    dp[i][j] = 0; // obstacle → no path
                } 
                else if (i == 0 && j == 0) {
                    dp[i][j] = 1; // start
                } 
                else {
                    int up = (i > 0 ? dp[i-1][j] : 0);
                    int left = (j > 0 ? dp[i][j-1] : 0);
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[n-1][m-1];
    }
};