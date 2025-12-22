class Solution {
public:
    bool check(vector<int>& nums) {
        int ind=0;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1])ind++;
        }

        if(nums[n-1]>nums[0])ind++;

        if(ind<=1) return true;
        else return false;
    }
};