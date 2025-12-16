class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mpp;
        mpp[0]=1;
        int cnt=0;
        int prefsum = 0; 
        for(int i=0;i<nums.size();i++){
            prefsum += nums[i];
            int remove = prefsum - k;
            cnt+=mpp[remove];
            mpp[prefsum]++;
        }
        return cnt;
    }
};