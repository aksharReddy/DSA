class Solution {
public:
    bool check(vector<int>& nums) {
         int ind=0;
        if(nums.size()==1) return true;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                ind++;
            }
        }
        if(nums[nums.size()-1]>nums[0]) ind++;

        if(ind<=1) return true;
        else return false;
    }
};