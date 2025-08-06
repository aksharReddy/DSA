class Solution {
public:

    // int f(int ind,int amt,vector<int>&coins,vector<vector<int>>&dp){

    //     if (ind == 0) {
    //         if (amt % coins[0] == 0) return amt / coins[0];
    //         else return 1e9;
    //     }

    //     if(dp[ind][amt]!=-1) return dp[ind][amt];
    //     int pick = 1e9;
    //     if(coins[ind]<=amt) pick = 1+f(ind,amt-coins[ind],coins,dp);
    //     int notpick = f(ind-1,amt,coins,dp);

    //     return dp[ind][amt] = min(pick,notpick);
    // }


    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        for(int amt=0;amt<=amount;amt++){
            if(amt%coins[0] == 0) dp[0][amt] = amt/coins[0];
            else{
                dp[0][amt] = 1e9;
            }
        }

        for(int i =1;i<n;i++){
            for(int amt=0;amt<=amount;amt++){
                
            int pick = 1e9;
            if(coins[i]<=amt) pick = 1+dp[i][amt-coins[i]];
            int notpick = dp[i-1][amt];

            dp[i][amt] = min(pick,notpick);
            }
        }
         int ans = dp[n - 1][amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};