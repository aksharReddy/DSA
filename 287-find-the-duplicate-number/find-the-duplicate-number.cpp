class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            if(freq[nums[i]] >= 1) return nums[i];
            freq[nums[i]]++;
        }
        return -1;
    }
};