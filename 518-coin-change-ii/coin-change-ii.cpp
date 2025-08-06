class Solution {

    int f(int ind, vector<int>&coins,int amt, vector<vector<int>>&dp){

        if(ind==0){
            if(amt%coins[ind] == 0) return 1;
            else return 0;
        }
        if(dp[ind][amt]!=-1)return dp[ind][amt];
        int pick = 0;
        if(coins[ind]<=amt) pick = f(ind,coins,amt-coins[ind],dp);
        int notpick = f(ind-1,coins,amt,dp);
        return dp[ind][amt]=pick+notpick;
    }
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,coins,amount,dp);
    }
};