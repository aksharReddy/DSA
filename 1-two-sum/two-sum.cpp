class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        int num=0;
        int value_req=0;
        for(int i=0;i<nums.size();i++)
        {
             num = nums[i];
            value_req = target-nums[i];

            if(mpp.find(value_req)!=mpp.end()){
                return{mpp[value_req],i};
            }

            mpp[nums[i]] = i;
        }
        return {};
    }
};