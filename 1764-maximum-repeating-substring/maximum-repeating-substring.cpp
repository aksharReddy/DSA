class Solution {
public:
    int solve(string &sequence, string &word, int i,vector<int>&dp) {
        // Base case: if remaining length is smaller than word, can't repeat
        if (i + word.size() > sequence.size()) return 0;

        if(dp[i]!=-1) return dp[i];
        if (sequence.substr(i, word.size()) == word) {
            // If it matches, we can move forward and try extending
            return dp[i]=1 + solve(sequence, word, i + word.size(),dp);
        }

        // Otherwise, no repetition starting at i
        return 0;
    }

    int maxRepeating(string sequence, string word) {
        int n = sequence.size();
        int maxi = 0;
        vector<int>dp(n+1,-1);
        // Try starting at every index
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, solve(sequence, word, i,dp));
        }

        return maxi;
    }
};
