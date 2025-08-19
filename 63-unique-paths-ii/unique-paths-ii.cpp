class Solution {
public:
    int f(int r,int c,vector<vector<int>>&a,vector<vector<int>>&dp){

        if(r<0 || c<0) return 0;
        if(a[r][c]==1) return 0;
        if(r==0 && c==0) return 1;
        if(dp[r][c]!=-1) return dp[r][c];
        int up = 0;
        if( r-1>=0 && a[r-1][c]!=1 ) up = f(r-1,c,a,dp);
        int left = 0;
        if( c-1>=0 && a[r][c-1]!=1) left = f(r,c-1,a,dp);
        return dp[r][c]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int  n = a.size();
        int  m = a[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,a,dp);
    }
};