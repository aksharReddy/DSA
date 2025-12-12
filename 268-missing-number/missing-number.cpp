class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size()+1;
        vector<int>freq(n,0);

        for(auto it:nums){
            freq[it]++;
        }

        for(int i=0;i<n;i++){
            if(freq[i]==0){
                return i;
            }
        }
        return -1;
    }
};