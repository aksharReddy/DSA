class Solution {
    bool findsubset(int ind, vector<int>& nums, int s, vector<vector<int>>& dp) {
        if (s == 0) return true;
        if (ind == 0) return nums[0] == s;

        if (dp[ind][s] != -1)
            return dp[ind][s];

        bool take = false;
        if (nums[ind] <= s)
            take = findsubset(ind - 1, nums, s - nums[ind], dp);

        bool nottake = findsubset(ind - 1, nums, s, dp);

        return dp[ind][s] = take || nottake;
    }

public:
    bool canPartition(vector<int>& nums) {
        int s = 0;
        for (int num : nums) s += num;

        if (s % 2 != 0) return false;
        int sum = s / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return findsubset(n - 1, nums, sum, dp);
    }
};
