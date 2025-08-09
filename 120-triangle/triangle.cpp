class Solution {
public:

// int f(int i, int j, vector<vector<int>>& a, vector<vector<int>>& dp) {
//     int n = a.size();

//     if(i == n-1) return a[i][j];
//     if(dp[i][j]!= -1) return dp[i][j];
//     int d = a[i][j] +f(i+1,j,a,dp);
//     int dg = a[i][j]+f(i+1,j+1,a,dp);
//     return dp[i][j]= min(d,dg);

// }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                if(i == n-1) {dp[i][j] = triangle[i][j];}
                else
                {
                int d = triangle[i][j] +dp[i+1][j];
                int dg = triangle[i][j]+dp[i+1][j+1];   
                dp[i][j] = min(d,dg);
                }
            }
        }
        return dp[0][0];
    
    }
};